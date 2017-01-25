
load("/Users/RNAseq/TRX_LEVEL/E10.5_Endo_1.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "Endo_1"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E10.5_Endo_1.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E10.5_Endo_2.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "Endo_2"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E10.5_Endo_2.txt",quote=FALSE, sep="\t")

load("/Users/jwang36/RNAseq/TRX_LEVEL/E10.5_HE_1.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "HE_1"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E10.5_HE_1.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E10.5_HE_2.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "HE_2"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E10.5_HE_2.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E11.5_preHSC_1.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "PreHSC_1"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E11.5_PreHSC_1.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E11.5_preHSC_2.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "PreHSC_2"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E11.5_PreHSC_2.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E11.5_preHSC_3.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "PreHSC_3"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E11.5_PreHSC_3.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E14.5_FL_1.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "FL_1"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E14.5_FL_1.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/E14.5_FL_2.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "FL_2"
write.table(df,"/Users/RNAseq/TRX_LEVEL/E14.5_FL_2.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/BM_1.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "BM_1"
write.table(df,"/Users/RNAseq/TRX_LEVEL/BM_1.txt",quote=FALSE, sep="\t")

load("/Users/RNAseq/TRX_LEVEL/BM_2.bam.rda")
cnts <- get("counts",counts)
df <- as.data.frame(cnts)
colnames(df) <- "BM_2"
write.table(df,"/Users/RNAseq/TRX_LEVEL/BM_2.txt",quote=FALSE, sep="\t")
