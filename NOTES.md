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

