import sys

f=open("klee_output1.txt")
f1=f.readlines()
f.close()

conditions1 = list()
outputs1 = list()
outputs1_dict = dict()

var_name = ""
last_cond = ""
vars_list = list()
cond_val_map = dict()
cond_val_cnt = 0

for s in f1:
	s = s.replace(" \n", "")
	s = s.replace("\n", "")
	# print("For s:"+s)
	# print("var_name is:"+var_name+"\n\n\n\n\n")
	if len(s) > 2 and s[1] =='(' and s[-1] == ')':
		k = s[2:-2]
		last_cond = k
	elif s == " true":
		# conditions1 = ["true"]
		last_cond = "true"
	elif len(s) > 2 and s[0] =='(' and s[-1] ==')':
		k = s[0:-1]
		if last_cond in outputs1_dict.keys():
			outputs1_dict[last_cond][var_name]=k
		else:
			cond_val_cnt = cond_val_cnt+1
			# cond_val_map[last_cond]=cond_val_cnt
			outputs1_dict[last_cond]=dict()
			outputs1_dict[last_cond][var_name]=k
	elif len(s) > 2 and s[-2:] == ":=":
		var_name = s[:-2]
		if var_name not in vars_list:
			vars_list.append(var_name)
    
for c1 in outputs1_dict.keys():
	conditions1.append(c1)

for s in conditions1:
    print (s)





# f = open("invarient_condition.txt", "w")
# for s in conditions1:
# 	f.write(s + "\n")
# f.close()

### minimize the invariant

# def parse(s):
# 	count = 1
# 	idx = 5
# 	for x in s[5:]:
# 		if(x == "("):
# 			count = count + 1
# 		elif(x == ")"):
# 			count = count - 1
# 		if count == 0:
# 			break
# 		idx = idx +1
# 	return  s[:idx],s[idx+1:]

# s = conditions1[0]
# if(s[:3] == "let"):
# 	s1,s = parse(s)

# print(s1)
