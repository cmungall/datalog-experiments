Sat Apr 10 15:29:05 PDT 2021
type-restrict

$ time make rg-go
souffle -Fgo -Dgo relation_graph.dl

real    0m49.924s
user    0m48.427s
sys     0m0.892s

$ grep -c RO_0002131 go/edge.csv 
177700
$ grep GO_0008150 go/edge.csv  | grep -c BFO_0000050
12382

$ time make rg-mondo
souffle -Fmondo -Dmondo relation_graph.dl

real    2m16.083s
user    2m14.394s
sys     0m1.472s

$ time make rg-uberon
souffle -Fuberon -Duberon relation_graph.dl

real    0m27.892s
user    0m27.366s
sys     0m0.477s


$ make owlrg-uberon
time relation-graph --ontology-file merged/uberon.owl --non-redundant-output-file uberon/owlrg-nr.ttl --redundant-output-file uberon/owlrg-r.ttl > owlrg-uberon

real    7m47.015s
user    115m0.706s
sys     0m26.905s




Sat Apr 10 15:28:56 PDT 2021



$ time make rg-uberon
souffle -Fuberon -Duberon relation_graph.dl

real    1m8.577s
user    1m7.412s
sys     0m1.080s
$ wc -l uberon/edge.csv 
 5766573 uberon/edge.csv
$ grep -c RO_0002131 uberon/edge.csv 
578628

$ time make rg-go
souffle -Fgo -Dgo relation_graph.dl

real    1m13.868s
user    1m12.659s
sys     0m1.124s

$ wc -l go/edge.csv 
 5167255 go/edge.csv

$ time make rg-mondo
souffle -Fmondo -Dmondo relation_graph.dl

real    6m4.515s
user    5m54.108s
sys     0m3.832s
$ wc -l mondo/edge.csv 
 14961770 mondo/edge.csv

