#!/usr/bin/sh

export PATH=/Shared/samtools-1.1/:$PATH
export PATH=/Shared/bowtie2/:$PATH

/Shared/tophat-2.0.13.Linux_x86_64/tophat -p 4 -r 100 -o /Shared/Epigenomeatlas/tophat/Treg /Shared/bowtie2-2.2.4/hg19 /Shared/Epigenomeatlas/Alignment_Post_Processing_8477_Treg.fastq
