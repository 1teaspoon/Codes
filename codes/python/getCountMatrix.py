"""
Given files containing transcript counts, compile into one matrix
"""
base="/Users/RNAseq/TRX_LEVEL"

d0_1=open(base+"/E10.5_Endo_1.txt","r")
d0_2=open(base+"/E10.5_Endo_2.txt","r")
d1_1=open(base+"/E10.5_HE_1.txt","r")
d1_2=open(base+"/E10.5_HE_2.txt","r")
d2_1=open(base+"/E11.5_PreHSC_1.txt","r")
d2_2=open(base+"/E11.5_PreHSC_2.txt","r")
d2_3=open(base+"/E11.5_PreHSC_3.txt","r")
d4_1=open(base+"/E14.5_FL_1.txt","r")
d4_2=open(base+"/E14.5_FL_2.txt","r")
d5_1=open(base+"/BM_1.txt","r")
d5_2=open(base+"/BM_2.txt","r")
out=open(base+"/transcript_Counts_ID.txt","w")

IDs=[]
c01,c02,c11,c12,c21,c22,c23,c41,c42,c51,c52=[],[],[],[],[],[],[],[],[],[],[]
for line in d0_1:
    temp=line.split()
    if temp[0]!="Endo_1":
        c01.append(temp[1])
        IDs.append(temp[0])
d0_1.close()
for line in d0_2:
    temp=line.split()
    if temp[0]!="Endo_2":
        c02.append(temp[1])
d0_2.close()

for line in d1_1:
    temp=line.split()
    if temp[0]!="HE_1":
        c11.append(temp[1])
        IDs.append(temp[0])
d1_1.close()
for line in d1_2:
    temp=line.split()
    if temp[0]!="HE_2":
        c12.append(temp[1])
d1_2.close()


for line in d2_1:
    temp=line.split()
    if temp[0]!="PreHSC_1":
        c21.append(temp[1])
d2_1.close()
for line in d2_2:
    temp=line.split()
    if temp[0]!="PreHSC_2":
        c22.append(temp[1])
d2_2.close()
for line in d2_3:
    temp=line.split()
    if temp[0]!="PreHSC_3":
        c23.append(temp[1])
d2_3.close()
for line in d4_1:
    temp=line.split()
    if temp[0]!="FL_1":
        c41.append(temp[1])
d4_1.close()
for line in d4_2:
    temp=line.split()
    if temp[0]!="FL_2":
        c42.append(temp[1])
d4_2.close()
for line in d5_1:
    temp=line.split()
    if temp[0]!="BM_1":
        c51.append(temp[1])
d5_1.close()
for line in d5_2:
    temp=line.split()
    if temp[0]!="BM_2":
        c52.append(temp[1])
d5_2.close()

out.write("Endo_1\tEndo_2\tHE_1\tHE_2\tPreHSC_1\tPreHSC_2\tPreHSC_3\tFL_1\tFL_2\tBM_1\tBM_2\n")
for i in xrange(len(c01)):
    toWrite=[IDs[i],c01[i],c02[i],c11[i],c12[i],c21[i],c22[i],c23[i],c41[i],c42[i],c51[i],c52[i]]
    out.write("\t".join(toWrite))
    out.write("\n")
out.close()

