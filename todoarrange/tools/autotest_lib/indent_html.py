#encoding -*- gbk -*-
"""
将一个html文件按照tag成对缩进，看的更清晰一点
"""
import re

def getfield(name):
    """parse the field for the name, type and count
    """
    pattern = "(?P<tag>\<\w+\>)(?P<value>[^<>]*)"
    #print re.match(pattern, name).groupdict()
    return re.match(pattern, name).groupdict()

def add_pre(str):
    return '<'+str

def turn_list(t):
    return list(t)

def build(l):
    str = ''
    for tag in l:
        str += tag[2]*"  " + tag[0] + tag[1] + '\n'
    print str

def get_tag(str):
    pattern = "\</?(?P<tag>\w+)"
    m = re.match(pattern, str)
    if m == None:
        print "NNNNNNNNNNNNNNNNNNNNNNNNone get ", str
        return None
    else:
        return m.group(1)

f = open('introduction.html', 'rb')
s = f.read()
f.close()
t = re.findall('(?P<tag>\<[^<>]*\>)(?P<value>[^<>]*)', s)
l = map(turn_list, t)
indent = 0
cur_l = list()
for tag in l:
    if tag[0][:4] == "<!--":
        pass
    elif get_tag(tag[0]) in ["META","meta",'img','hr']:
        pass
    elif tag[0][-2] == '/':
        pass
    elif tag[0][1] == '/':
        if get_tag(tag[0]) == cur_l[-1]:
            cur_l.pop()
        else:
            pass
            #print 'missing couple',indent,"pre : ",cur_l[-1],' now: ', get_tag(tag[0])
        indent -= 1
    else:
        cur_l.append(get_tag(tag[0]))
        indent += 1
    tag.append(indent)#*'    '
    #print tag
    #print tag
#print l
result = build(l)
f_w = open("result.html", 'w')
f_w.write(result)
f_w.close()