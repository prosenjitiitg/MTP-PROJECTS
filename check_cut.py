import z3
from z3 import *
import sys
import re

#1 = conditions1
#2 = outputs1
#3 = conditions2
#4 = outputs2
#5 = test.smt
#6 = invarient_cond
#7 = idx

val = 0
in_vars = str()
def compareOut(str1, str2):
	# print("In compare out ==> ")
	# print("				str1 is:" + str1 + "::")
	# print("				str2 is:" + str2 + "::")
	print(in_vars)
	print("-----------------------------------------------")
	check = in_vars +"\n(set-option :pp-bv-literals false)\n" +"(assert ( not ( = " + str1 + " " + str2 + " ) ) )" + "(check-sat)"
	# print("check is:" + check + "::")
	sol = Solver()
	sol.from_string(check)
	k = sol.check()
	# print str(k)
	# print("Out compare out")
	if str(k) == "unsat":
		return 1
	global val
	if val == 0:
		ooo = sol.model()
		f = open("Testcase.txt","a+")
		f.write(str(ooo) + "\n")
		f.close()
	val = 0
	return 0
def compare(str1,str2):
    check = in_vars+"(assert ( and( \n"+str1+"\n ) ( not ( \n"+ str2 +"\n ) ) ) )"+"(check-sat)"
    sol=Solver()
    sol.from_string(check)
    k=sol.check()

    if str(k) == "unsat":
        return 1

    ooo = sol.model().sexpr()
    f=open("TestCase.txt","a+")
    f.write(str(ooo)+"\n")
    f.close()

    return 0

def condOr(cond1, cond2):
	cond_final = "or (" + cond1 + " ) ( " + cond2 + " )"
	return cond_final

def condAnd(cond1,cond2):
    cond_final = "and (" + cond1 + " ) ( " + cond2 + " )"
    return cond_final

def values_eq(str1,str2):
    cond_final = "=  ("+str1+") ("+str2+") "
    return cond_final

def var_in_smt2(str):
    ret="concat  (select  "+str+" (_ bv3 32) ) (concat  (select  "+str+" (_ bv2 32) ) (concat  (select  "+str+" (_ bv1 32) ) (select  "+str+" (_ bv0 32) ) ) ) "
    return ret

def regex_var_in_smt2(str):
    ret="concat  \(select  "+str+" \(_ bv3 32\) \) \(concat  \(select  "+str+" \(_ bv2 32\) \) \(concat  \(select  "+str+" \(_ bv1 32\) \) \(select  "+str+" \(_ bv0 32\) \) \) \)"
    return ret

def regex_var_in_smt2_long (str):
    ret="concat  \(select  "+str+" \(_ bv7 32\) \) \(concat  \(select  "+str+" \(_ bv6 32\) \) \(concat  \(select  "+str+" \(_ bv5 32\) \) \(concat  \(select  "+str+" \(_ bv4 32\) \) \(concat  \(select  "+str+" \(_ bv3 32\) \) \(concat  \(select  "+str+" \(_ bv2 32\) \) \(concat  \(select  "+str+" \(_ bv1 32\) \) \(select  "+str+" \(_ bv0 32\) \) \) \) \) \) \) \)"
    return ret	

def compareCond(str1, str2):
	if str1 == str2:
		return 1
	check = in_vars + "(assert ( not ( = ( " + str1 + " ) ( " + str2 + " ) ) ) )" + "(check-sat)"
	# print("\n\n\n\n\n\n")
	# print("str1 is:" + str1 + "::")
	# print("str2 is:" + str2 + "::")
	# print("check is:" + check + "::")
	# print("\n\n\n\n\n\n")
	sol = Solver()
	sol.from_string(check)
	k = sol.check()
	# print("Condition check:" + str(k))
	if str(k) == "unsat":
		# print("Returning 1")
		return 1
	return 0
def iscondition_true(str1):
	check = in_vars + "(assert ( "+ str1 +" ) )" + "(check-sat)"

	sol = Solver()
	sol.from_string(check)
	k = sol.check()
	# print("Condition check:" + str(k))
	if str(k) == "unsat":
		# print("Returning 1")
		return 0
	return 1
def sub_cond(str1,str2):

	check = in_vars + "(assert ( and ( "+str1+" ) ( not ( "+str2+" ) ) ) )"+ "(check-sat)"
	# check = in_vars + "(assert ( "+ str1 +" ) )" + "(check-sat)"
	sol = Solver()
	sol.from_string(check)
	k = sol.check()
	# print("Condition check:" + str(k))
	if str(k) == "unsat":
		# print("Returning 1")
		return 1
	return 0
def print_inv():
	f = open("invarient.txt")
	f1 = f.readlines()
	f.close()
	for s in f1:
		print(s),
	print("\n\n")

args = sys.argv

f = open(args[1],"r")
conditions1 = f.readlines()
f.close()

f = open(args[2],"r")
outputs1 = f.readlines()
f.close()

f = open(args[3],"r")
conditions2 = f.readlines()
f.close()

f = open(args[4],"r")
outputs2 = f.readlines()
f.close()

print(len(conditions1))
print(len(conditions2))

outputs1_dict = dict()
no_outs = len(outputs1)/len(conditions1)
i = 0
for cond1 in conditions1:
	outputs1_dict[cond1] = dict()
	for j in range(i*no_outs,(i+1)*no_outs):
		out = outputs1[j].split(":=")
		outputs1_dict[cond1][out[0]]=out[1]
	i = i + 1

outputs2_dict = dict()
no_outs = len(outputs2)/len(conditions2)
i = 0
for cond2 in conditions2:
	outputs2_dict[cond2] = dict()
	for j in range(i*no_outs,(i+1)*no_outs):
		out = outputs2[j].split(":=")
		outputs2_dict[cond2][out[0]]=out[1]
	i = i + 1


f = open(args[5], "r")
f1 = f.readlines()

for s in f1:
	s = s.replace(" \n", "")
	s = s.replace("\n", "")
	if len(s) > 3 and s[1] == 'd' and s[2] == 'e':
		in_vars = in_vars + s
	elif len(s) > 3 and s[1] == 's' and s[2] == 'e':
		in_vars = in_vars + s
	else:
		break
f.close()

# print(in_vars)

f=open(args[6],"r")
invarient_condition=f.readlines()
f.close()

FLAG = 0

IDX = int(args[7])
Ln_bf= int(args[8])


for cond1 in conditions1:
	p = "false"
	i = 0
	for cond2 in conditions2:
		cond_cur = condAnd(cond1,cond2)
		if(iscondition_true(cond_cur)):
			print("satisfied==>"+ str(i))
			if(p == "false"):
				p = cond2
			else:
				p = condOr(p,cond2)
		i = i +1
	ret = sub_cond(cond1,p)
	if(not ret):
		exit(-1)


print(len(invarient_condition))
print(Ln_bf)
if(Ln_bf == len(invarient_condition)):
	print("============================================>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<======================================================================")
	f = open("recheck.txt","a")
	rec=invarient_condition[IDX-1]
	f.write(rec)
	f.close
	IDX=IDX+1
index=IDX

# for each invariant s
for s in invarient_condition[IDX-1: ]:
# for s in invarient_condition[6:7]:
	s = s.replace(" \n", "")
	s = s.replace("\n", "")
	s=s.strip()

	# print("condition is====>\n"+s+"\n\n")


	regex = "\(select  ([a-zA-Z0-9_]+) \(_ bv[0-9]+ [0-9]+\) \)"
	var_inv_list = re.findall(regex,s)
	var_inv_list = list(set(var_inv_list))
	
	list1 = list()
	list2 = list()
	for var in var_inv_list:
		if(var[-1]=='1'):
			list1.append(var)
		else:
			list2.append(var)

	for cond1 in conditions1:
		cond_cur=""
		s1=s
		
		for var in list1:
			orig = regex_var_in_smt2(var)
			orig_long = regex_var_in_smt2_long(var)
			s1 = re.sub(orig,outputs1_dict[cond1][var],s1)
			s1 = re.sub(orig_long,outputs1_dict[cond1][var],s1)
		cond_cur=cond1
		for cond2 in conditions2:

			s2=s1
			for var in list2:
				orig = regex_var_in_smt2(var)
				orig_long = regex_var_in_smt2_long(var)
				s2 = re.sub(orig,outputs2_dict[cond2][var],s2)
				s2 = re.sub(orig_long,outputs2_dict[cond2][var],s2)
			cond_cur=condAnd(cond_cur,cond2)

			if iscondition_true(cond_cur):
				if not compare(cond_cur,s2):
					# print("cond_cur::",cond_cur)
					print("s2::",s2)
					print("index::",index,"failed")
					# print_inv()
					exit(index)
				# print("cond1:::"+cond1+"\n")					
	print("index",index,"==>satisfied")
	index=index+1