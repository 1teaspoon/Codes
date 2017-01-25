library(spp)
chip.data <- read.bam.tags("IP.bam")
input.data <- read.bam.tags("IN.bam")

binding.char <- get.binding.characteristics(chip.data,srange=c(200,5000),bin=20,accept.all.tags=T)

chip.info <- select.informative.tags(chip.data,binding.char)
input.info <- select.informative.tags(input.data,binding.char)

chip.qua <- remove.local.tag.anomalies(chip.info)
input.qua <- remove.local.tag.anomalies(input.info)

broad.clusters <- get.broad.enrichment.clusters(chip.qua,input.qua,window.size=1000,z.thr=4,tag.shift=round(binding.char$peak$x/2))

write.broadpeak.info(broad.clusters,"OUT.broadPeak");
