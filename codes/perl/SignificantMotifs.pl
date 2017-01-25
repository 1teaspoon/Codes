#find significant Motifs at FDR0.01

use warnings;
my @all_files = glob 'fimoOut/*';

%hash = ();

$j = 0;

while ($all_files[$j]){
    @motif = split /\//,$all_files[$j];
    $motif = $motif[-1];
    @name = split /\-/, $motif;
    $name = uc $name[0];
    my $filename = "$all_files[$j]/fimo.txt.Bonferroni";
    print "reading $filename\n";
    open(my $fh, $filename)
    or die "Could not open file '$filename' $!";
    while(<$fh>){
        chomp;
        unless($_ =~ /#/){
            @b = split /\t/,$_;
            if ($b[7]<0.01){

                if (! exists $hash{$b[1]}){
                    $hash{$b[1]} = $name;
            
                }
                else{
                    @a = split /,/,$hash{$b[1]};
                    $flag  = 0;
                    foreach $i(@a){
                        if ($i eq $name){
                            $flag++;
                        }
                    }
                    if ($flag == 0){
                        $hash{$b[1]} = $hash{$b[1]} . ",$name";
                    }
                }

            }       
      
            
        }
     }
     close $fh;

    $j++;
}


my $filenameout = "Enhancer_TF_0.01";
open(my $fhout, '>', $filenameout) or die "Could not open file '$filenameout' $!";

foreach $key (sort keys %hash){
    @a = split /-/,$key;
    printf $fhout ("$a[0]\t$a[1]\t$a[2]\t$hash{$key}\n");

}
close $fhout;


