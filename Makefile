BENCHDIR = benchmarks
BENCHDIR_CL = classification
ELDIR = el
TESTDIR = tests
BENCH_ONTS = uberon pato ro mondo hp mp go chebi obi zfa envo

RUN = souffle

ifdef SOUFFLE_THREADS
RUN = time docker run -v${PWD}:/mnt -w /mnt -it souffle/ubuntu:xenial souffle -j $(SOUFFLE_THREADS)
endif

# ----------------------------------------
# Tests
# ----------------------------------------
TESTS = go-nuclear-membrane
test: $(patsubst %, t-%, $(TESTS))

$(TESTDIR)/%/rdf.facts: $(TESTDIR)/%/ontology.owl
	robot query -f tsv -i $< -q sparql/triples.rq $@
.PRECIOUS: $(TESTDIR)/%/rdf.facts

t-%: $(TESTDIR)/%/rdf.facts
	(time souffle -F$(TESTDIR)/$* -D$(TESTDIR)/$* src/relation_graph.dl) >> $(TESTDIR)/$*/LOG && cat $(TESTDIR)/$*/test_summary.csv

test-%: tests/%/test.dl $(TESTDIR)/%/rdf.facts
	$(RUN) -F$(TESTDIR)/$* -D$(TESTDIR)/$* $< && cat $(TESTDIR)/$*/test_summary.csv && (test -s $(TESTDIR)/$*/pass.csv) && (test -s $(TESTDIR)/$*/fail.csv && echo FAIL || echo PASS)

# ----------------------------------------
# Benchmarks
# ----------------------------------------

all_bench: all_bench_dl all_bench_whelk
all_bench_dl: $(patsubst %, benchmark-dl-%, $(BENCH_ONTS))
all_bench_whelk: $(patsubst %, benchmark-whelk-%, $(BENCH_ONTS))

stats:
	make report_bench | ./util/parse-rpt.pl

report_bench: $(patsubst %, report-all-%, $(BENCH_ONTS))

report-all-%: report-dl-% report-whelk-%
	echo hi

report-dl-%:
	@echo ;
	@echo "## ONTOLOGY: " $* " SYSTEM: DATALOG";
	@cat $(BENCHDIR)/$*/DL-LOG

report-whelk-%:
	@echo ;
	@echo "## ONTOLOGY: " $* " SYSTEM: WHELK";
	@cat $(BENCHDIR)/$*/WHELK-LOG

merged/%.owl: download/%.owl download/ro.owl
	robot merge -i $< -i download/ro.owl -o $@
.PRECIOUS: merged/%.owl

download/%.owl:
	curl -L -s http://purl.obolibrary.org/obo/$*.owl > $@
.PRECIOUS: download/%.owl

$(BENCHDIR)/%/rdf-base.facts: download/%.owl
	robot query -f tsv -i download/$*.owl -q sparql/triples.rq $@
.PRECIOUS: $(BENCHDIR)/%/rdf-base.facts

$(BENCHDIR)/%/rdf.facts: $(BENCHDIR)/%/rdf-base.facts $(BENCHDIR)/ro/rdf-base.facts
	cat $^ > $@
.PRECIOUS: $(BENCHDIR)/%/rdf.facts

$(BENCHDIR_CL)/%/rdf.facts: $(BENCHDIR_CL)/%/edit.owl
	robot query -f tsv -i $< -q sparql/triples.rq $@
.PRECIOUS: $(BENCHDIR_CL)/%/rdf.facts

MON = uberon ro mondo hp mp go chebi
benchmarks/monarch/rdf-base.facts: $(patsubst %, $(BENCHDIR)/%/rdf-base.facts, $(MON))
	cat $^ > $@

merged/monarch.owl:
	robot merge $(patsubst %, -i download/%.owl, $(MON)) -o $@


# classification task
el-dl-%: $(BENCHDIR_CL)/%/rdf.facts
	(time $(RUN)  -F$(BENCHDIR_CL)/$* -D$(BENCHDIR_CL)/$* src/el_classification.dl) >& $(BENCHDIR_CL)/$*/DL-LOG && cat $(BENCHDIR_CL)/$*/{DL-LOG,test_summary.csv}

# relationgraph task
cl-dl-%: $(BENCHDIR_CL)/%/rdf.facts
	(time $(RUN)  -F$(BENCHDIR)/$* -D$(BENCHDIR)/$* src/relation_graph.dl) >& $(BENCHDIR)/$*/DL-LOG && cat $(BENCHDIR)/$*/{DL-LOG,test_summary.csv}

# relationgraph task
benchmark-dl-%: $(BENCHDIR)/%/rdf.facts
	(time $(RUN)  -F$(BENCHDIR)/$* -D$(BENCHDIR)/$* src/relation_graph.dl) >& $(BENCHDIR)/$*/DL-LOG && cat $(BENCHDIR)/$*/{DL-LOG,test_summary.csv}

benchmark-whelk-%: merged/%.owl
	(time relation-graph --ontology-file $< --non-redundant-output-file $(BENCHDIR)/$*/owlrg-nr.ttl --redundant-output-file $(BENCHDIR)/$*/owlrg-r.ttl) >& $(BENCHDIR)/$*/WHELK-LOG && cat $(BENCHDIR)/$*/WHELK-LOG

%.sorted: %
	perl -npe 's@\s*\.\s*\n@\n@g;s@ @\t@g' $< | sort > $@


# ----------------------------------------
# Make executable (optional)
# ----------------------------------------
bin/%: src/%.dl
	souffle -F. -D. -obin/$* $<


classification/uberon/uberon-edit.owl:
	robot merge -i ../uberon/uberon_edit.owl -o $@
