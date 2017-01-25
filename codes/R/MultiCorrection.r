args <- commandArgs(trailingOnly=TRUE)

m <- args[1]
out <- args[2]

a = read.table (m,row.names = 1)

A <- as.matrix(a)

b = p.adjust(A, method = "BH", n = length(A))

write.csv(b,file = out,quote = F, sep = "\t",row.name = T)
