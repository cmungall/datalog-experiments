# Datalog experiments

## Relation Graph

Currently testing an implementation of relation-graph in datalog.

See:

 * [relation_graph.dl](relation_graph.dl)

This is a datalog program using the souffle framework. It takes as
input triples as a TSV. Half of the DL program is mapping a subset of
RDF to OWL (we assume pre-reasoning using robot etc, the goal here is
to build something that provides all inferred subclass/existentials as
owlstar-style triples.

I have not yet formally checked the completeness of these rules. There
are likely parts of Elk's profile missing but I think it covers
everything we typically need for complete RGs.

uberon completes in ~30s:

```bash
$ time make rg-uberon
souffle -Fuberon -Duberon relation_graph.dl

real    0m27.892s
user    0m27.366s
sys     0m0.477s
```

compare with OWL:

```bash
$ make owlrg-uberon
time relation-graph --ontology-file merged/uberon.owl --non-redundant-output-file uberon/owlrg-nr.ttl --redundant-output-file uberon/owlrg-r.ttl > owlrg-uberon

real    7m47.015s
user    115m0.706s
sys     0m26.905s
```

## Connectivity Reasoning

The datalog framework makes it easy to extend inference to include edge weights etc
