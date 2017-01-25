"""
Given a file containing combined T-test and Ftest results, check to see if both are
significant and print to STDOUT
"""
import sys

combined=open("/Users/RNAseq/GENE_LEVEL/Ttest/"+sys.argv[1]+"_Combined.txt","r")
out=open("/Users/RNAseq/GENE_LEVEL/"+sys.argv[1]+"_SignificantTandF.txt","w")

toCheck=[]
header=1
for line in combined:
    if header==1:
        out.write(line)
        header=0
    else:
        temp=line.split()
        if float(temp[3])<0.05 and float(temp[5])<0.05:
            out.write(line)

combined.close()
