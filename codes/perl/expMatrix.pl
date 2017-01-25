#generating a matrix input for consensus clustering 
use warnings;
%filter = ();
open C, ">filtered_mm9_trxIDNAME";
open A, "<filtered_Mm9.gtf";
while (<A>){
    chomp;
    @a = split /\t/,$_;
    if ($a[2] eq 'transcript'){
        @b = split /;/,$a[-1];
        $id = (split /"/,$b[1])[1];
        $name = (split /"/,$b[4])[1];
        $filter{$id} = $name;
        print C "$id\t$name\n";
    }

}
close A;

%file = ();
@a = glob "FPKM/*.txt";

foreach $i (@a){
    $name = (split /\//,$i)[-1];
    @name = split /_/,$name;
    $sample = $name[0] . '_' . $name[1];
    #print "$sample\n";
    open A, "<$i";
    while (<A>){
        chomp;
        unless ($_ =~ /ENSEMBL/){
            @b = split /\t/,$_;
            if (exists $filter{$b[0]}){
                $id = (split /\./,$b[0])[0];                
                $file{$id}{$sample} = $b[1];
                #print "$id\t$sample\t$b[1]\n";
            }
            
        }
    }
    close A;

}



$val = 0;

open B, ">TRXexpMatrix";

print B "ENDO_1	ENDO_2	HE_1	HE_2	PreHSC_1	PreHSC_2	PreHSC_3	FL_1	FL_2	BM_1	BM_2";
foreach $s (sort keys %file){
    $flag = 0;
    foreach $sample (sort keys %{$file{$s}}){
        
        $val = $file{$s}{$sample};
        #print "$s\t$sample\t$val\n";
        #print "$val\n";
        if ($val>1){
            $flag++;
        }
    }
    unless ($flag == 0){
        print B "$s\t$file{$s}{'ENDO_1'}\t$file{$s}{'ENDO_2'}\t$file{$s}{'HE_1'}\t$file{$s}{'HE_2'}\t$file{$s}{'PreHSC_1'}\t$file{$s}{'PreHSC_2'}\t$file{$s}{'PreHSC_3'}\t$file{$s}{'FL_1'}\t$file{$s}{'FL_2'}\t$file{$s}{'BM_1'}\t$file{$s}{'BM_2'}\n";
    }
}


