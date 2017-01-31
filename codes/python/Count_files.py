import os,sys

source = "/Users/Data/HF/lincRNA/Cufflinks_novo/Results/"

DirList = os.listdir(source)
test = []
for item in DirList:
	cur_path = source + item + "/"
	sub_list = os.listdir(cur_path)
	if len(sub_list) == 0:
		test.append(item)

all = {}
f = file("Run_cuff_novo.sh")
fw = file("Run_sub.sh", "w")
while True:
	line = f.readline()
	if len(line) == 0:
		break
	line = line.strip()
	temp = line.split("/")[-1]
	temp = temp.replace(".sh","")
	if temp in test:
		fw.write(line.replace("smp 2","smp 3").replace("mf=10G","mf=40G") + "\n")
f.close
fw.close
