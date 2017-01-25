#perform T test using edgeR package

library(edgeR)

counts <- read.table("testedgeR/EdgeRInputGeneCounts_EndovsHE",header = T)
y <- DGEList(counts, group=c(rep("Endo",2),rep("HE",2)))
y <- calcNormFactors(y)
y <- estimateCommonDisp(y, verbose=TRUE)
y <- estimateTagwiseDisp(y)
et <- exactTest(y)
top <- topTags(et,n=15000)
table <- subset(top$table,top$table$FDR < 0.05)
write.table(table,"testedgeRout/EndovsHE",quote=F,sep = "\t")