import csv
import sys

def seq0(seq, mc, j):
    for i in  range(j , len(mc) + j):
        if (seq[i] != mc[i-j]):
            return False
    return True

# reading the sequence file
with open(f"{sys.argv[2]}","r") as f:
    seq = f.readline()

seq = seq[0:len(seq)-1]

dd = sys.argv[1]

if(dd[10:15]=="small"):
    mc = ["AGATC","AATG","TATC"]
elif(dd[10:15] == "large"):
    mc = ["AGATC","TTTTTTCT","AATG","TCTAG","GATA","TATC","GAAA","TCTG"]

mx = [0] * len(mc)
indx = [0] * len(mc)
ind = 0
count = 0

for i in range (len(mx)):
    count = 0
    ind = 0
    while (len(seq) - ind > 4):
        flag = seq0(seq,mc[i],ind)
        if(flag):
            #print(ind)
            count += 1
            #print(count)
            ind += len(mc[i])

        elif(not(flag)):

            if (mx[i] <= count):
                indx[i] = ind - count * len(mc[i])
                mx[i] = count
                count = 0
                ind += 1

            elif(mx[i] > count):
                count = 0
                ind += 1
#print(mx)
#print(indx)

def check(line,mx):
    for i in range (len(mx)):
        if(int(line[1 + i]) != mx[i]):
            return False
    return True


with open(f"{sys.argv[1]}","r") as dic:
    read = csv.reader(dic)
    next(read)
    for line in read:
        flag1 = check(line,mx)
        if(flag1):
            print(line[0])
            exit(0)
    print("No match")
    exit(1)

