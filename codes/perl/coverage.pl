#calculate genome coverage(how many percentage of the genome is covered by our query)

open(A,$ARGV[0]);
open(B,"HSC_project/annotation/mm9_ref");
open(C,">$ARGV[1]");
@tss=();
@gen=();
while(<B>){
    @a=split(/\s+/,$_);
    if($a[3] eq "+"){
	$l=$a[4]-5000;#promoter
	$r=$a[4]+1000;
	$l1=$r;#gene body
	$r1=$a[5];
    }else{
	$l=$a[5]-1000;
	$r=$a[5]+5000;
	$l1=$a[4];
	$r1=$l;
    }
    $s1="$a[2]-$l-$r-$a[12]";
    $s2="$a[2]-$l1-$r1-$a[12]";
    push(@tss,$s1);
    push(@gen,$s2);
}

$d1=0;$d2=0;$d3=0;
while(<A>){
    @a=split(/\s+/,$_);
    $c=int(($a[1]+$a[2])/2);
    $d=$a[2]-$a[1];
    $f=0;
    foreach $i(@tss){
	@t=split(/-/,$i);
	if($a[0] eq $t[0]){
	    if(($c>$t[1])&&($c<$t[2])){
		$f=1;
		$d1+=$d;
		print C "$a[0]\t$a[1]\t$a[2]\t$c\t$t[1]\t$t[2]\t$t[3]\tpromoter\n";
		last;
	    }
	}
    }
    if($f==0){
	foreach $i(@gen){
	    @t=split(/-/,$i);
	    if($a[0] eq $t[0]){
		if(($c>$t[1])&&($c<$t[2])){
		    $f=1;
		    $d2+=$d;
		    print C "$a[0]\t$a[1]\t$a[2]\t$c\t$t[1]\t$t[2]\t$t[3]\tgene body\n";
		    last;
		}
	    }
	}
    }
    if($f==0){
	$d3+=$d;
	print C "$a[0]\t$a[1]\t$a[2]\t$c\tintergenic\n";
    }
}

$d1=$d1/28000000;
$d2=$d2/28000000;
$d3=$d3/28000000;

$r1 = $d1/($d1+$d2+$d3);
$r2 = $d2/($d1+$d2+$d3);
$r3 = $d3/($d1+$d2+$d3);

print "Promoter $d1\nGene body $d2\n Intergenic $d3\n";
print "Promoter $r1\nGene body $r2\n Intergenic $r3\n";





