"""
Given a file containing F-test results and the input of a T-test file from the
CLI, Combine the files into one document. Output has the following fields -
geneID, geneName, log(fold change) (from T-test), average Expression 
(from T-test), Adjusted P-value (from T-test), B statistic (from T-test), and
adjusted P-value (from F-test)
"""

import sys

Ftest=open("/Users/RNAseq/GENE_LEVEL/Ftest_ANOVA_results_GeneLevel.txt","r")
Ttest=open("/Users/RNAseq/GENE_LEVEL/Ttest/"+sys.argv[1]+"_Results_New.txt","r")

out=open("/Users/RNAseq/GENE_LEVEL/Ttest/"+sys.argv[1]+"_Combined.txt","w")

id,name,fc,exp,adjP,b=[],[],[],[],[],[]
header=1
for line in Ttest:
    line=line.strip()
    temp=line.split()
    if header != 1:
        id.append(temp[0])
        #name.append(temp[1])
        fc.append(temp[1])
        exp.append(temp[2])
        adjP.append(temp[5])
        b.append(temp[6])
    else:
        header=0
Ttest.close()

fpval=["a"]*len(id)
header=1
for line in Ftest:
    line=line.strip()
    temp=line.split("\t")
    if header !=1:
        if temp[0] in id:
            ind=id.index(temp[0])
            fpval[ind]=temp[14]
    else:
        header=0
Ftest.close()

out.write("geneID\tlog(FC)\tAveExpr\tadj.P.Val\tB\tF.adj.P.Val\n")
for i in xrange(len(id)):
    toWrite=[id[i],fc[i],exp[i],adjP[i],b[i],fpval[i]]
    out.write("\t".join(toWrite))
    out.write("\n")
out.close()
