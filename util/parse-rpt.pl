#!/usr/bin/perl

while(<>) {
    if (m@ONTOLOGY:\s*(\S+).*SYSTEM:\s*(\S+)@) {
        ($ont,$sys) = ($1,$2);
    }
    if (m@^real\s+(\d+)m(\S+)s@) {
        my $t = $1 * 60 + $2;
        print "$sys\t$ont\t$t\n";
        ($sys,$ont) = ("","");
    }
}
