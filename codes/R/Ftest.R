#Ftest

library(edgeR)

#expression/FPKM value matrix
All_FPKM <- read.table("/Users/RNAseq/GENE_LEVEL/FtestInput/GeneLevelInputMatrix", sep = "\t", header = T)
#All_FPKM <- read.table("/Shared/Tan/sguthery/DiffGeneExpression/Cufflinks_out/genes_Expression_Matrix2.txt", sep = "\t", header = T)

#gene/transcript level read counts matrix
counts <- read.table("/Users/RNAseq/GENE_LEVEL/filtered_Gene_ID_Counts.txt", sep = "\t", header = T)
#counts <- read.table("/Shared/Tan/sguthery/DiffGeneExpression/ReadCounts/gene_level/gene_Counts_ID.txt", sep = "\t", header = T)


#samples
Endo <-c("Endo_1", "Endo_2")
HE <-c("HE_1", "HE_2")
PreHSC <-c("PreHSC_1", "PreHSC_2", "PreHSC_3")
FL <-c("FL_1", "FL_2")
BM <- c("BM_1","BM_2")
comparison <- c(Endo, HE, PreHSC, FL, BM)

###########################################################################
####specific comparison
#temp_FPKM <- All_FPKM[, comparison]
#filter out genes with low expression
#only keep genes with FPKM greater than 1 at least in one samples
#num <- apply(temp_FPKM,1, function(x) sum( x > 1 )) >= 1
#hit_names <- row.names(temp_FPKM[num,])
#temp_Counts <- counts[hit_names, comparison]
#construct the input matrix
#Input_Data <- subset(temp_Counts, !is.na(rowMeans(temp_Counts)))
Input_Data <- counts
#create design matrix, this tells the algorithm grouping information
info <- c(rep("Endo",2), rep("HE",2), rep("PreHSC",3), rep("FL",2), rep("BM",2))
lev <- c("Endo", "HE", "PreHSC","FL","BM")
f <- factor(info, levels=lev)
design <- model.matrix(~0+f)
colnames(design) <- lev

#apply TMM normalization
y <- DGEList(counts = Input_Data, group = info)
y <- calcNormFactors(y)

#create contrast matrix, basically all pairwise comparisons
contrast.matrix <- makeContrasts(Endo-HE,Endo-PreHSC,Endo-FL,Endo-BM,HE-PreHSC, HE-FL, HE-BM,PreHSC-FL,PreHSC-BM,FL-BM, levels=design)

#Estimate the dispersion, necessary#
#apply voom method
#dim(design)
#dim(y)
#design
#y
v <- voom(y,design, plot=TRUE)
fit <- lmFit(v,design)
fit2 <- contrasts.fit(fit, contrast.matrix)
fit2 <- eBayes(fit2)

output <- topTable(fit2,coef=1, number = 30000, sort.by="p")

	
out_all <- topTableF(fit2, number=30000)
#write the summary table to a text file
write.table(out_all,"/Users/RNAseq/GENE_LEVEL/FtestOutput/Ftest_ANOVA_results_GeneLevel_New4.txt", quote=F, sep = "\t")
#write.table(out_all,"/Shared/Tan/sguthery/DiffGeneExpression/ReadCounts/gene_level/Ftest_ANOVA_results_geneLevel_HEonly.txt",quote=F,sep="\t")
