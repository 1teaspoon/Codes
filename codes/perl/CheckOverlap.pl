#calculate how many sequences are overlapped by 2000bp or other criteria

#!/usr/bin/perl
die "INPUT: perl getOverlap2.pl Input1.bed Input2.bed Output1 Output2\n" unless @ARGV==4;

($qFile,$tFile,$outq,$outt) = @ARGV;
open B,">$outq";

open F,"<$tFile";
while (<F>) {
    
    chomp;
    #next if (/^track name/);
    #if (/^>/) {
	#($chrID,$l,$r) = (split/-/);
	#$chrID =~ s/>//g;
    #}
	($chrID,$l,$r) = (split(/\s+/,$_))[0,1,2];
        
	#$chrID = "chr".$chrID;
	$peakCenter = int(($r-$l)/2)+$l;
#    $peakCenter=$l;
        $tPeaks{$chrID}{$peakCenter}++;
	$tPeaks2{$chrID}{$peakCenter} = $_;
        #print "$tPeaks2{$chrID}{$peakCenter}\n";
	#$tPeaks2{$chrID}{$peakCenter} = join "\t",($chrID,$l,$r);
	$tPeakLen{$chrID}{$peakCenter} = $r-$l+1;
    #}
}
close F;


$j = 0;

open F,"<$qFile";
#%qFileOverlap = ();
#%tFileOverlap = ();

while (<F>) {
    chomp;
    #next if (/^track name/);
    #($qid,$qchrID,$ql,$qr) = (split /\s+/)[0,1,2,3];
    ($qchrID,$ql,$qr) = (split /\s+/)[0,1,2];
    $qpeakCenter = int(($qr-$ql)/2)+$ql;
    $qpeakLen = $qr-$ql+1;
   # @temp = ();
    $flag = 0;
    #%singlepeak = ();
    foreach $tpeakCenter(keys %{$tPeaks{$qchrID}}) {
	$tpeakLen = $tPeakLen{$qchrID}{$tpeakCenter};
	$c2cDist = abs($qpeakCenter - $tpeakCenter);
	if ($tpeakLen >= $qpeakLen) {
	    if ($c2cDist <= int($tpeakLen/2)) {
#	    if ($c2cDist < 2000){
	#	push @temp,$tPeaks2{$qchrID}{$tpeakCenter};
		#$tPeaks2{$qchrID}{$tpeakCenter} = $tPeaks2{$qchrID}{$tpeakCenter}."\t"."1"; #FL
                 $tPeaks2{$qchrID}{$tpeakCenter} = $tPeaks2{$qchrID}{$tpeakCenter}."\t"."2"; #BM
                #$singlepeak{$tPeaks2{$qchrID}{$tpeakCenter}}++;
		$flag++;
	    }
	}
	else {
	    if ($c2cDist <= int($qpeakLen/2)) {
#	    if ($c2cDist < 2000){
         #       push @temp,$tPeaks2{$qchrID}{$tpeakCenter};
                #$tPeaks2{$qchrID}{$tpeakCenter} = $tPeaks2{$qchrID}{$tpeakCenter}."\t"."1";
                $tPeaks2{$qchrID}{$tpeakCenter} = $tPeaks2{$qchrID}{$tpeakCenter}."\t"."2";         
                #$singlepeak{$tPeaks2{$qchrID}{$tpeakCenter}}++;
                $flag++;
	    }

        }	 
    }
    if ($flag >0){
	#print B "$_\t1\n";
        print B "$_\t5\n";#BM
        #print B "$_";
        #foreach $key (sort keys %singlepeak){
        #    print B "\t$key";
        #}
        #print B "\n";

        #%a = ();
        #$a{$ql}++;
        #$a{$qr}++;        
        #foreach $tsinglepeak (keys %singlepeak){
         #   ($chrID,$s,$e) = (split(/\s+/,$tsinglepeak))[0,1,2];
         #   $a{$s}++; 
         #   $a{$e}++;
            
        #}
        #$a = (sort { $a <=> $b } (keys %a))[-1];
        #$b = (sort { $a <=> $b } (keys %a))[0];
   
        #print B "$qid\t1\n";        
        #print B "$qchrID\t$b\t$a\n"; 
	#$qFileOverlap{$_}++;
	#foreach $temp(@temp) {
	 #   print B "$temp\n";
	#}
    }
    else {
	print B "$_\n";
         #$j++;
    }
}
close F;

#$numQFileOverlap = scalar(keys %qFileOverlap);
#$numTFileOverlap = scalar(keys %tFileOverlap);
#print "\#\#: $numQFileOverlap\t$tproteinID: $numTFileOverlap\n";

open C, ">$outt";

foreach $chr (sort keys %tPeaks2){
    foreach $tl (sort keys %{$tPeaks2{$chr}}){
        print C "$tPeaks2{$chr}{$tl}\n";

    }

}





