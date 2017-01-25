use warnings;

@s = 1..16;
@a = ('Endo','HE','PreHSC','FL','BM');
open B, ">subTRXjob/runR.sh";

foreach $s (@s){
   # $arg2 = '/Users/HSC_Project/StemGeneCluster/stemTRX/C'.$s.'_ID.txt.enhancer.0.01';
    foreach $a (@a){
   #     $arg1 = '/Users/HSC_Project/StemGeneCluster/stemTRX/C'.$s.'_ID.txt.'.$a.'.0.01';
	#$arg1 = $a;
         #$arg1 = '/Users/HSC_Project/StemGeneCluster/stemTRX/c'.$s.'/'.$a.'/result/FDRmatrix.exp';
         #$arg2 = '/Users/HSC_Project/StemGeneCluster/stemTRX/c'.$s.'/'.$a.'/result/qvalue.exp';
	$arg1 = '/Users/HSC_Project/StemGeneCluster/stemTRXresult/c'.$s.$a.'sig.txt';
        #$arg2 = '/Users/HSC_Project/StemGeneCluster/stemTRX/c'.$s.'/'.$a.'/result';
    #    $arg3 = '/Users/HSC_Project/StemGeneCluster/stemTRX/c'.$s.'/'.$a;    
        #$out =  '/Users/HSC_Project/StemGeneCluster/subTRXjob/c'.$s.$a.'.sh';
        #open B,">$out";
        # $line = $arg1.' '.$arg2;
        #$path ='/Users/HSC_Project/StemGeneCluster/stemTRX/c'.$s.'/'.$a;
        $path ='/Users/HSC_Project/StemGeneCluster/stemTRX/c'.$s.'/'.$a.'/result';
#        print B "perl /Users/HSC_Project/StemGeneCluster/enrich1.pl $line\n";
      #  print B "perl /Users/HSC_Project/StemGeneCluster/run.pl $path\n";
	#print B "qsub $path/run.sh\n";
        $line = $arg1.' '.$path;
        #print B "perl /Users/HSC_Project/StemGeneCluster/fdr.pl $path\n"; 
        #print B "perl /Users/HSC_Project/StemGeneCluster/exp.pl $line\n";
        # print B "Rscript fdr.r $line\n";
         print B "perl fdr.name.pl $line\n"; 
        #print C "bash $out\n";
    }
}
