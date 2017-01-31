#!/usr/bin/perl
# generate summary bed file at given resolution
use POSIX qw(ceil);

#die "Usage: $0 [input bed file] [resolution in bp] [shift tag flag]
     #example: summaryBED.pl dnaseHs_CD4_All_Seqeuence.bed 200 1\n" unless @ARGV == 3;

%mm9 = ("1" => 197195432,
	"2" => 181748087,
	"3" => 159599783,
	"4" => 155630120,
	"5" => 152537259,
	"6" => 149517037,
	"7" => 152524553,
	"8" => 131738871,
	"9" => 124076172,
	"10" => 129993255,
	"11" => 121843856,
	"12" => 121257530,
	"13" => 120284312,
	"14" => 125194864,
	"15" => 103494974,
	"16" => 98319150,
	"17" => 95272651,
	"18" => 90772031,
	"19" => 61342430,
	"X" => 166650296,
	"Y" => 15902555);
%hg18 = ("1" => 247249719,
	 "2" => 242951149,
         "3" => 199501827,
	 "4" => 191273063,
	 "5" => 180857866,
	 "6" => 170899992,
	 "7" => 158821424,
	 "8" => 146274826,
	 "9" => 140273252,
	 "10" => 135374737,
	 "11" => 134452384,
	 "12" => 132349534,
	 "13" => 114142980,
	 "14" => 106368585,
	 "15" => 100338915,
	 "16" => 88827254,
	 "17" => 78774742,
	 "18" => 76117153,
	 "19" => 63811651,
	 "20" => 62435964,
	 "21" => 46944323,
	 "22" => 49691432,
	 "X" => 154913754,
	 "Y" => 57772954,
	 "M" => 16571);

($inFile,$outFile) = @ARGV;
$res=100;
$shiftFlag=0;
$histMod = (split /\./,$inFile)[1];
#$histMod = "H33.R1";
open IN,"<$inFile";
while(<IN>){
    if(/\@PG/){
	last;
    }
}
while (<IN>) {
    #chomp;
    #next if $.==1;
    # for Zhao et al. T-cell HDAC/HAT chip-Seq data 
    # shift by 150bp for HDAC/HAT data
    # shift by 75bp for histone modification data
    # other data, shift histone modification data by 100bp.
    #($temp,$lcoor,$rcoor,$strand,$tagCount) = (split/\s+/)[0,1,2,3,4];
    #($temp,$lcoor,$rcoor,$tagCount,$strand) = (split/\s+/)[0,1,2,4,5];
    #($temp,$lcoor,$rcoor,$strand) = (split/\s+/)[0,1,2,5];
    ($strand,$temp,$newCoor)=(split /\s+/)[1,2,3];
    #if ($shiftFlag ==1 && $strand eq "+") {
    	#$center = $lcoor+int(($rcoor-$lcoor)/2);
	#$newCoor = $lcoor+150;
    #}
    #elsif ($shiftFlag==1 && $strand eq "-") {
    	#$center = $lcoor+int(($rcoor-$lcoor)/2);
	#$newCoor = $rcoor-150;
    #}
    #elsif ($shiftFlag==0 && $strand eq "+") {
    	#$newCoor = $lcoor;
    #}
    #elsif ($shiftFlag==0 && $strand eq "-") {
    	#$newCoor = $rcoor;
    #}
    #else {
    	#next;
    #}
    ##########
 
    # for Crawford et al. T-cell DHS data
    #($temp,$coor,$strand) = (split/\s+/)[0,1,5];
    #next if $temp =~ /random/; # don't consider unalignable contigs
    #$newCoor = $coor;
    ##########

    # put tags in $res long segments 
    #
    #($chrID = $temp) =~ s/chr(\S+)/$1/;
    $chrID = $temp;
    
    $segCount = ceil($newCoor/$res);
    #push @{$segMembers{$chrID}{$segCount}},$newCoor;
    #$tagCount  = $tagCount+1;
    #$segTagCount{$chrID}{$segCount} += $tagCount;
    $segTagCount{$chrID}{$segCount}++;
    #if($strand==16){
	#$segTagCount{$chrID}{$segCount-1}++;
	#$segTagCount{$chrID}{$segCount-2}++;
    #}else{
	#$segTagCount{$chrID}{$segCount+1}++;
	#$segTagCount{$chrID}{$segCount+2}++;
    #}
    #push @{$tagCoors{$chrID}},$newCoor;
    
}

close IN;

open(A,">$outFile");
print A "track type=wiggle_0 name=\"$histMod\" description=\"$histMod\"\n";
$span = $res -1;
#foreach $chrID(sort {$a <=> $b} keys %tagCoors) {
foreach $chrID(sort {$a <=> $b} keys %mm9) {
#foreach $chrID(sort {$a <=> $b} keys %hg18) {
    print A "variableStep chrom=chr$chrID span=$span\n";
    #@tagCoors = sort {$a <=> $b} @{$tagCoors{$chrID}};
    #$lastTagCoor = $tagCoors[-1];
    #@tagCoors = ();
    $chrEnd = $mm9{$chrID};
    #$chrEnd = $hg18{$chrID};

    #$lastIdx = ceil($lastTagCoor/$res);
    $lastIdx = ceil($chrEnd/$res);

    ## sum up tag counts in $res segments
    ##
    for ($i=0;$i<$lastIdx;$i++) {
	
	#$c = scalar(@{$segMembers{$chrID}{$i+1}});
	
	if (! exists $segTagCount{$chrID}{$i+1}) {
	    $c = 0;
	}
	else {
	    $c = $segTagCount{$chrID}{$i+1};
	}
	#if ($c >0) {
	    $coor = $i*$res+1;
	    
	    print A "$coor\t$c\n";
	    	    
	#}
    }
    #@tagCoors = ();
    
}

