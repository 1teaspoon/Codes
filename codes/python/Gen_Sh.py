import os, sys

envir = "export PATH=$PATH:/Shared/Software/cufflinks-2.2.1/"

annotation = "/Shared/Annotation/Mouse/Mus_musculus/Ensembl/NCBIM37/Annotation/Genes/genes.gtf"
seq = "/Shared/Annotation/Mouse/Mus_musculus/Ensembl/NCBIM37/Sequence/WholeGenomeFasta/genome.fa"

source = "/Shared/HF/Merged_Bam/"
cluster = "/Users/HF/Cufflinks_novo/Clusters/"
output = "/Users/HF/Cufflinks_novo/Results/"

DirList = os.listdir(source)
for item in DirList:
	cur_name = item.split(".")[0]
	if ".bai" not in item:
		f = file(cluster + cur_name + ".sh", "w")
		f.write(envir + "\n")
		command = "cufflinks -p 6 -o " + output + cur_name + " -g " + annotation + " -b " + seq + " " +  source + item
		f.write(command + "\n")
		f.close
		print "qsub -pe smp 6 -l mf=50G " + cluster + cur_name + ".sh"
