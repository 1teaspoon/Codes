
#perform consensus clustering over a 8000*12 matrix

library("clusterCons")
args <- commandArgs(trailingOnly=TRUE)
num1 <- as.numeric(args[1])
num2 <- as.numeric(args[2])
out <- args[3]
print(num1)
print(num2)
print(out)
input <- read.table("C2C300Matrix",sep = "\t", header = T)
#data_dist <- cor(t(input[,]), method = "pearson")
#data_dist <- 1 - data_dist
data_dist <- dist(input, method = "euclidean")
temp <- as.matrix(data_dist)
temp <- as.data.frame(temp)
row.names(temp) <- 1:length(temp[,1])
colnames(temp) <- 1:length(temp[,1])
alp <- list()
cmr <- cluscomp(temp, algorithms = list("pam"), alparams = list(alp), merge = 1, clmin = num1, clmax = num2, reps = 100, prop = 0.8)
print(str(cmr))
save(cmr,file=out)

