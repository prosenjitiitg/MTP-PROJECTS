import sys
import re

#1=>invarient_before(before variable expr is changed)
#2=>variables_1 at cut a
#3=>variables_2 at cut b

args = sys.argv
f = open(args[1],"r")
f1 = f.readlines()
f.close()

f = open(args[2],"r")
f2 = f.readlines()
f.close()

f = open(args[3],"r")
f3 = f.readlines()
f.close()

conditions_output = list()

def remove_line_end(s):
    s = s.replace(" \n","")
    s = s.replace("\n","")
    return s

for condition in f1:
    condition = remove_line_end(condition)
    condition = " "+condition+" "
    condition_new = condition
    for var in f2:
        var = remove_line_end(var)
        condition_new = re.sub('(?<=[^a-zA-Z1-9_])'+var+'(?=[^a-zA-Z1-9_])',var[:-2]+"11",condition_new)
    for var in f3:
        var = remove_line_end(var)
        condition_new = re.sub('(?<=[^a-zA-Z1-9_])'+var+'(?=[^a-zA-Z1-9_])',var[:-2]+"12",condition_new)
    print(condition_new[1:-1])
