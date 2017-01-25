#find and separate a file based on texts

use warnings;

%outfile = ();
open A, "<allfivestageEnhancer_TF_0.01.stage";
while (<A>){
    chomp;
    @a = split /\t/,$_;
    $chr = shift @a;
    $s = shift @a;
    $e = shift @a;
    $TF = shift @a;
    foreach $i (@a){
        ($stage, $status) = (split /_/,$i)[0,1];
        $outfile{$status}{"$chr-$s-$e\t$TF"}{$stage}++;
    }    
}
close A;


open B, ">allfivestageActiveEnhancer_TF_0.01.stage";
open C, ">allfivestagePrimedEnhancer_TF_0.01.stage";
open D, ">allfivestagePoisedEnhancer_TF_0.01.stage";

foreach $key (sort keys %outfile){
    if ($key eq 'Active'){
        foreach $active (sort keys %{$outfile{$key}}){
                $type = 0;
                $TYPE = "";
            foreach $activestage (sort keys %{$outfile{$key}{$active}}){
                $type ++;
                $TYPE = $TYPE . $activestage . ',';
            }
            if ($type == 1){
                print B "$active\t$TYPE\tSS\n";

            }
            else{
                print B "$active\t$TYPE\tNS\n";
            }
            
        }
    }
    if ($key eq 'Poised'){
        foreach $poised (sort keys %{$outfile{$key}}){
                $type = 0;
                $TYPE = "";
            foreach $poisedstage (sort keys %{$outfile{$key}{$poised}}){
                $type ++;
                $TYPE = $TYPE . $poisedstage . ',';
            }
            if ($type == 1){
                print D "$poised\t$TYPE\tSS\n";

            }
            else{
                print D "$poised\t$TYPE\tNS\n";
            }
        }
    }
    if ($key eq 'Primed'){
        foreach $primed (sort keys %{$outfile{$key}}){
                $type = 0;
                $TYPE = "";
            foreach $primedstage (sort keys %{$outfile{$key}{$primed}}){
                $type ++;
                $TYPE = $TYPE . $primedstage . ',';
            }
            if ($type == 1){
                print C "$primed\t$TYPE\tSS\n";

            }
            else{
                print C "$primed\t$TYPE\tNS\n";
            }
        
        }
    }

}
