import sys
args = sys.argv

f = open( args[1], "r")
f1 = f.readlines()
f.close()
conditions1 = list()
outputs1 = list()
outputs1_dict = dict()

var_name = ""
last_cond = ""
vars_list1 = list()
cond_val_map = dict()
cond_val_cnt = 0
is_cond = 1

for s in f1:
	s = s.replace(" \n", "")
	s = s.replace("\n", "")
	if is_cond == 1 and len(s) > 2 and s[1] =='(' and s[-1] == ')':
		k = s[2:-2]
		last_cond = k
		is_cond = 0
	elif s == " true":
		last_cond = "true"
		is_cond = 0
	elif len(s) > 2 and s[0] =='(' and s[-1] ==')':
		k = s[0:-1]
		if last_cond in outputs1_dict.keys():
			outputs1_dict[last_cond][var_name]=k[1:-1]
		else:
			cond_val_cnt = cond_val_cnt+1
			outputs1_dict[last_cond]=dict()
			outputs1_dict[last_cond][var_name]=k[1:-1]
		is_cond = 1
	elif len(s) > 2 and s[-2:] == ":=":
		var_name = s[:-2]
		if var_name not in vars_list1:
			vars_list1.append(var_name)

for c1 in outputs1_dict.keys():
	conditions1.append(c1)
	for var in vars_list1:
		outputs1.append(outputs1_dict[c1][var])

f = open(args[2],"w")
for s in conditions1:
        print(s)
	f.write(s + "\n")
f.close()

f = open(args[3],"w")
for cond in conditions1:
	for var in outputs1_dict[cond].keys():
		s = var + ":=" + outputs1_dict[cond][var]
		f.write(s + "\n")
f.close()
