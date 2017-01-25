#prepare input for hypergeometric test

use warnings;
%BG = ();
%TEST = ();
$I = 0;
$J = 0;
#open A, "<All.txt";
#while (<A>){
#    chomp;
#    @a = split /\t/,$_;
#    $enh = "$a[0]\t$a[1]\t$a[2]";
#    $BG{$enh}++;    
#    $I++;
#}
#close A;

open A, "<$ARGV[0]";
while (<A>){
    chomp;
    @a = split /\t/,$_;
    $enh = $a[0];
    $TEST{$enh}=$a[1];;    
    $J++;
}
close A;


#%TF = ();
#open B, "<allfivestageActiveEnhancer_TF_0.01.stage";#enh-TF-0.01 or 0.05
open B, "<$ARGV[1]";
while (<B>){
    chomp;
    @a = split /\t/,$_;
    $enh = $a[0];
    $BG{$enh} = $a[1];
    $I++;
}
close B;


%bg = ();
%test = ();

#open D, ">tmp";
foreach $key (sort keys %BG){
    $tf = $BG{$key};
    @a = split /,/,$tf;
    foreach $i (@a){
 #       if ($i eq "ELF2"){
 #            print D "$key\t$tf\n";   

 #       }
        if (! exists $bg{$i}){
            $bg{$i} = 1;
        }
        else{
            $bg{$i} = $bg{$i} + 1;
        }       
    }
}


foreach $key (sort keys %TEST){
    $tf = $TEST{$key};
    @a = split /,/,$tf;
    foreach $i (@a){
 #       if ($i eq "ELF2"){
 #            print D "$key\t$tf\n";   

 #       }
        if (! exists $test{$i}){
            $test{$i} = 1;
        }
        else{
            $test{$i} = $test{$i} + 1;
        }       
    }
}

#open D, ">enrich_TF_hyper_table_0.01_1_2";

foreach $key (sort keys %bg){
    open C, ">$ARGV[2]/$key.r";

    $m = $bg{$key};
    $k = $I - $m;
    if (! exists $test{$key}){
        $n = 0;
    }
    else{
        $n = $test{$key};
    }
    print C "a <- phyper($n,$m,$k,$J,lower.tail = FALSE)\nwrite.table(a,file = \"$ARGV[2]/result/$key.pvalue.txt\",quote = F, row.names = F)\n";
   # print D "$key\t$n,$m,$k,$J\n";
}



