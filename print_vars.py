import sys
import re
def extract_var(st):
	l = st.split()
	if "int" in l:
		if l[1] == "main" or l[1][:5] == "main(":
			return [-1]
		x = st.find('int')
		st = st[x:]
		st = st.replace("\t","")
		st = st.replace(" ","")
		st = st.replace("\n","")
		st = st.replace(";","")
		st = st[3:]
		val = st.split("=")[0]
		return val.split(",")
	return [-1]

def find_no(x,s):
	result = re.findall(r'^'+x+' *=',s)
	if len(result):
		return 2*len(result)
	result = re.findall(r'[^a-zA-Z1-9_]'+x+' *=',s)
	if len(result):
		# print(result)
		return 2*len(result)
	result = re.findall(r'[^a-zA-Z1-9_]'+x+'[^a-zA-Z1-9_]',s)
	return len(result)



args = sys.argv
if len(args) < 4:
	print "Arguements not supplied"
	exit()

f = open(args[1], "r")
f1 = f.readlines()
f.close()

var_list = []
l = 1
for s in f1:
	if l == int(args[2])+1:
		break;
	z = extract_var(s)
	if z != [-1]:
		var_list.extend(z)
	l = l+1



fin_var_list=[]
# for s in var_list:
# 	# print("var::",s)
for x in var_list: 
	if x[-1]=='\r':
		x=x[:-1]
	count=0
	l=1
	for s in f1:
		if l == int(args[2])+1:
			break;
		count =count+find_no(x,s)
		l=l+1
	# print(x)
	# print(x,count,len(x))
	if count >=2:
		fin_var_list.append(x)


var_list=fin_var_list


f_out_1 = ""
f_out_2 = ""

for s in var_list:
	# if s[-4:] == "temp":
	# 	continue
	if int(args[3])==1:
		f_out_1 = f_out_1 + s + "21\n"
	else:
		f_out_1 = f_out_1 + s + "22\n"

for s in var_list:
	# if s[-4:] == "temp":
	# 	continue
	if int(args[3])==1:
		f_out_2 = f_out_2 + s + "11\n"
	else:
		f_out_2 = f_out_2 + s + "12\n"



if int(args[3])==1:
	f = open("var_names_int_test1.txt", "w")
else:
	f = open("var_names_int_test2.txt", "w")

f.write(f_out_1)
f.close()

if int(args[3])==1:
	f = open("var_names_int1.txt", "w")
else:
	f = open("var_names_int2.txt", "w")

f.write(f_out_2)
f.close()

