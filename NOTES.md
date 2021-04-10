$ time make rg-uberon
souffle -Fuberon -Duberon relation_graph.dl

real    1m8.577s
user    1m7.412s
sys     0m1.080s
$ wc -l uberon/edge.csv 
 5766573 uberon/edge.csv
$ grep -c RO_0002131 uberon/edge.csv 
578628

