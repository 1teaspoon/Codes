#find texts in a file based on specific criteria

use warnings;

#%tf30 = ();
#open A, "<TF30";
#while (<A>){
#    chomp;
#    $tf30{uc $_} = 1;
#}
#close A;



#HAVANA
%H = ();
open A, "<havanalevel2_transcript";
while (<A>){
    chomp;
    $H{$_} = 1;
}
close A;



#REFSEQ
%R = ();
open B, "<emsembl_refseq_curated.txt";
while (<B>){
    chomp;
    @a = split /\t/,$_;
    $R{$a[0]} = 1;

}
close B;

%trxID = ();



open A, "<filtered_Mm9.gtf";
while (<A>){
    chomp;
    
        @a = split /\t/,$_;
        #print "$a[2]\n";
        if ($a[2] eq 'transcript'){
#         if ($a[2] eq 'gene'){
            #print "$a[2]\n";
            @b = split /;/,$a[-1];
            $trxid = (split /"/,$b[1])[1];
           # $geneid = (split /"/,$b[0])[1]; 
            $genename = (split /"/,$b[4])[1];
#            print "$trxid\t$genename\n";
            
           # if (exists $tf30{uc $genename}){
                if (exists $H{$trxid}){
                    $trxID{$trxid} = $genename;
                    if ($genename eq 'Sox7'){
                        print "$genename\t$trxid\n";
                    }
                }
                else{
                    $ID = (split /\./,$trxid)[0];
                    if (exists $R{$ID}){
                        $trxID{$trxid} = $genename;
                        if ($genename eq 'Sox7'){
			    print "$genename\t$trxid\n";
			}
                    }


                }

          #  }
        }
    

}
close A;


#open D, ">30TFhavanaTRXid";
open D, ">havanaTRXid";  
foreach $key (sort keys %trxID){
    print D "$key\t$trxID{$key}\n";


}




