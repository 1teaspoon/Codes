import os,sys

source = "/Users/Data/HF/Com_transcripts/Results_cuff/"
output = "/Users/Data/HF/Cuffcompare/Scripts/Sum_Results/"

Hit_list = {}
DirList = os.listdir(source)
for item in DirList:
	cur_name = item.split(".")[0]
	Hit_list[cur_name] = []
	f = file(source + item)
	f.readline()
	while True:
		line = f.readline()
		if len(line) == 0:
			break
		line = line.strip()
		mid = line.split("\t")
		Hit_list[cur_name].append(mid[0])
	f.close

Match = {}
f = file("gtf_out_list.txt")
count = 1
while True:
	line = f.readline()
	if len(line) == 0:
		break
	line = line.strip()
	mid = line.split("/")
	com = mid[-2]
	Match["q" + str(count)] = com
	count += 1
f.close


f = file("/Users/Data/HF/Cuffcompare/Novel_Combine/cuffcmp.tracking")
all_list = {}
out = []
while True:
	line = f.readline()
	if len(line) == 0:
		break
	line = line.strip()
	mid = line.split("\t")
	key = mid[1]
	#if mid[3] == "u":
	if mid[3] != "." and mid[3] != "u":
		out.append(key)
	if True:
		for i in range(4, len(mid)):
			if mid[i] != "-":
				temp = mid[i].split("|")
				tmp_mid = temp[0].split(":")
				tmp_mid[0] = Match[tmp_mid[0]]
				ele = tmp_mid[0] + ":" + tmp_mid[1]
				if key not in all_list:
					all_list[key] = []
				if ele not in all_list[key] and tmp_mid[1] in Hit_list[tmp_mid[0]]:
					all_list[key].append(ele)
f.close

print "XLOC_012387" in out
print "XLOC_012387" in all_list
fw = file(output + "Novo_Match.txt", "w")
for key in all_list.keys():
	if len(all_list[key]) > 0 and key not in out:
		all_list[key].sort()
		fw.write(key + "\t" + ", ".join(all_list[key]) + "\n")
fw.close
