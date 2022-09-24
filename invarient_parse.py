
import sys

def valid_inv(s):
    for d in s:
        if not ( d==" " or d.isalnum() or d == "=" or d=="_" or d== "+" or d=="-" or d=="*" ):
            # print(s,d)
            return 0
    return 1

f=open("output.txt","r")
f1=f.readlines()
f.close()


cond=list()
flag=0
for s in f1:
    s=s[:-1]
    if flag==1 and (s=="Exiting Daikon." or s[0:4]=="===="):
        flag=0
    if s=="..mine():::EXIT":
        flag=1
        continue
    if flag==1:
        flag=1
        cond.append(s)

for s in cond:
    s = s.replace("::","")
    if valid_inv(s):
        print s