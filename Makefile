PL2S = pl2sparql -i obo_prefixes  -u obo_metadata/oio  -A ~/repos/onto-mirror/void.ttl -m obo=http://purl.obolibrary.org/obo/

from-pato:
	$(PL2S) -e -i pato "subClassOf(A,B)" -f tsv | egrep 'PATO.*PATO' | perl -npe 's@PATO:@@g' > edge.facts
from-go:
	$(PL2S) -e -i go "subClassOf(A,B)" -f tsv | egrep 'GO.*GO' | perl -npe 's@GO:@@g' > edge.facts

t-%/edge.facts:
	$(PL2S) -e -i $* "subClassOf(A,B)" -f tsv | grep :  > $@
.PRECIOUS: t-%/edge.facts

run:
	souffle -F. -D. example.dl

run-%: t-%/edge.facts
	souffle -Ft-$* -Dt-$* example.dl


## th
compile: bin/example

bin/%: %.dl
	souffle -F. -D. -obin/$* $<

merged/%.owl: download/%.owl download/ro.owl
	robot merge -i $< -i download/ro.owl -o $@
.PRECIOUS: merged/%.owl

download/%.owl:
	curl -L -s http://purl.obolibrary.org/obo/$*.owl > $@
.PRECIOUS: download/%.owl

%/rdf-base.facts: download/%.owl
	robot query -f tsv -i download/$*.owl -q sparql/triples.rq $@
.PRECIOUS: %/rdf-base.facts

%/rdf.facts: %/rdf-base.facts ro/rdf-base.facts
	cat $^ > $@
.PRECIOUS: %/rdf.facts

MON = uberon ro mondo hp mp go chebi
monarch/rdf.facts: $(patsubst %, %/rdf-base.facts, $(MON))
	cat $^ > $@

rg-%: %/rdf.facts
	souffle -F$* -D$* relation_graph.dl

owlrg-%: merged/%.owl
	time relation-graph --ontology-file $< --non-redundant-output-file $*/owlrg-nr.ttl --redundant-output-file $*/owlrg-r.ttl > $@
