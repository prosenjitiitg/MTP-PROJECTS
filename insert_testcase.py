def convert(x):
    if x[-1]==')':
        x=x[:-1]
    if x[-1]==')':
        x=x[:-1]
    x=x[2:]
    y=int(x,16)
    return y

def toSigned32(n):
    n = n & 0xffffffff
    return n | (-(n & 0x80000000))

var_dic=dict()

f=open("reintiate.txt","r")
f1=f.readlines()
f.close()

VAR = ""
l=0
for s in f1:
    s=s[:-1]
    # print s
    var_dic[s]=l
    VAR = s
    l=l+1

f=open("TestCase.txt","r")
f1=f.readlines()
f.close()

var_index=dict()
values=dict()
var=""
for s in f1:
    s = s.replace(" \n", "")
    s = s.replace("\n", "")
    if(s == ''):
        continue
    h=s.split()
    if(h[0]=='(define-fun'):
        var=h[1]
        if var not in var_index.keys():
            var_index[var]=0
        var_index[var] = var_index[var] + 1
    else:
        if var not in values.keys():
            values[var]=list()
        idx = var_index[var]
        if idx != len(values[var]):
            values[var].append(list())
        for x in h:
            if x[0]=="#":
                values[var][idx-1].append( convert(x) )


no_of_testcases = var_index[VAR]
for t in range(no_of_testcases):
    var_values=dict()
    for x in values.keys():
        if x not in var_dic.keys():
            continue
        index=var_dic[x]
        val=0

        val=( 2**0+ 2**8+ 2**16 + 2**24  ) *( values[x][t][0] )
        g=len(values[x][t])
        # print g
        for h in range(1,g,2):
            values[x][t][h]=8*values[x][t][h]
            val=val-( values[x][t][0] * (2** values[x][t][h] ) ) +( (2** values[x][t][h] ) *( values[x][t][h+1] ) )
        var_values[index]=toSigned32(val)

    for x in range( len(var_values) ):
        print var_values[x],
    if(t != no_of_testcases -1):
        print  