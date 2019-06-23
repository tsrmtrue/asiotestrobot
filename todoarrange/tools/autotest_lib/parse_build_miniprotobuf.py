# -*- coding: GBK -*-
#解析协议定义，生成c++类
#协议的功能，
    #1。嵌套
    #2。版本兼容
import string
import os
import codecs
import xml
from xml.dom import minidom
import re

"""
hfile_head
hfile_class_head
    hfile_class_consturctor
    hfile_class_copy_constructor
    hfile_class_operator_euqal
    hfile_class_destructor
    hfile_class_statment
    hfile_class_parse
    hfile_class_serialize
hfile_class_end
"""

hfile_head = """
#pragma once
#include "miniprotobuf_hlp.h"
"""

hfile_class_head = """
class CMiniPb_%(classname)s
{
public:
"""
hfile_class_end = """
};
"""
hfile_class_init_immutable = """
        pFmt = new CEasyFormat();
        memset(&_mask, 0, sizeof(_mask));
"""
hfile_class_init_mutable_option = """
        if (pr->has_%(attrname)s())
        {
            set_%(attrname)s(pr->%(attrname)s());
        }
"""
hfile_class_init_mutable_repeated = """
        if (pr->size_of_%(attrname)s()>0)
        {
            for (unsigned int i=0; i<pr->size_of_skill(); i++)
            {
                add_%(attrname)s(pr->%(attrname)s(i));
            }
        }
"""
hfile_class_uninit_immutable = """
        if (pFmt != NULL)
        {
            delete pFmt;
        }
"""
hfile_class_constructor = """
    CMiniPb_%(classname)s(void)
    {
        %(init_immutable)s
    }
"""
hfile_class_destructor = """
    ~CMiniPb_%(classname)s(void)
    {
        %(uninit_immutable)s
    }
"""
hfile_class_copy_constructor = """
    CMiniPb_%(classname)s(CMiniPb_%(classname)s& r)
    {
        CMiniPb_%(classname)s * pr = const_cast<CMiniPb_%(classname)s *>(&r);
        %(init_immutable)s
        %(init_mutable)s
    }
"""
hfile_class_operator_equal = """
    CMiniPb_%(classname)s& operator =(CMiniPb_%(classname)s& r)
    {
        CMiniPb_%(classname)s * pr = const_cast<CMiniPb_%(classname)s *>(&r);
        %(init_immutable)s
        %(init_mutable)s
        return *this;
    }
"""
hfile_class_immutable_satement = """
public:
    //format
    CFormat* pFmt;
    //idx
    //mask
    #define MASK_SIZE %(mask_size)d
    unsigned int _mask[MASK_SIZE];
    SET_BIT_HELP_EASY(_mask,MASK_SIZE);
    HAS_BIT_HELP_EASY(_mask,MASK_SIZE);
"""
hfile_class_attr_enum_format = """
    e_%(attr_name)s = %(idx)d,
"""
hfile_class_attr_enum = """
    enum {
    %(attr_enum_format)s
    };
"""
hfile_class_attr_format = """
    %(attr_type)s_ATTR(%(attr_data)s, %(attr_name)s);
"""
hfile_class_mutable_statement = """
    //attr enum
    %(attr_enum)s
    //attr
    %(attr_format)s
"""
hfile_class_parse_immutable = """
    bool parse(const char* pIn, unsigned int packetlen)
    {
        if (pIn == NULL || packetlen == 0)
        {
            return false;
        }
        CBytebuffer bb((char*)pIn, packetlen, pFmt);
        return parse(&bb);
    }
"""
hfile_class_parse_attr_option_system = """
            case e_%(attrname)s:
            {
                if ( !pbb->parse_%(attr_datatype)s(_%(attrname)s))
                {
                    return false;
                }
                _set_bit(tag);
            }
            break;
"""
hfile_class_parse_attr_option_selftype = """
            case e_%(attrname)s:
                {
                    int len = 0;
                    if ( !pbb->parse_varint32(len))
                    {
                        return false;
                    }
                    CBytebuffer tb(pbb->get_cur(), len, pFmt);
                    if ( !_%(attrname)s.parse(&tb))
                    {
                        return false;
                    }
                    pbb->advance(len);
                    _set_bit(tag);
                }
                break;
"""
parse_system = """

"""
parse_selftype = """

"""
hfile_class_parse_attr_repeated_system = """
            case e_%(attrname)s:
                {
                    int size = 0;
                    if ( !pbb->parse_varint32(size))
                    {
                        return false;
                    }
                    int count = 0;
                    if ( !pbb->parse_varint32(count))
                    {
                        return false;
                    }
                    for (int i=0; i<count; i++)
                    {
                        %(datatype)s s;
                        if (!pbb->parse_%(datatype)s(s))
                        {
                            return false;
                        }
                        add_%(attrname)s(s);
                    }
                    break;
                }
"""
hfile_class_parse_attr_repeated_selftype = """
            case e_%(attrname)s:
                {
                    int size = 0;
                    if ( !pbb->parse_varint32(size))
                    {
                        return false;
                    }
                    int count = 0;
                    if ( !pbb->parse_varint32(count))
                    {
                        return false;
                    }
                    for (int i=0; i<count; i++)
                    {
                        int len = 0;
                        if ( !pbb->parse_varint32(len))
                        {
                            return false;
                        }
                        CBytebuffer tb(pbb->get_cur(), len, pFmt);
                        CMiniPb_%(attrname)s s;
                        if (!s.parse(&tb))
                        {
                            return false;
                        }
                        pbb->advance(len);
                        add_%(attrname)s(s);
                    }
                    break;
                }
"""
hfile_class_parse_mutable = """
    bool parse(CBytebuffer* pbb)
    {
        if (pbb == NULL)
        {
            return false;
        }
        int tag = 0;
        int datatype = 0;
        while ((tag = pbb->get_tag_datatype(datatype))>0)
        {
            switch(tag)
            {
%(attr)s
                default :
                {
                    if (!pbb->parse_unknown_pass((DATA_TYPE)datatype))
                    {
                        return false;
                    }
                }
                break;
            }
        }
        return true;
    }
"""
hfile_class_serialize_immutable = """
public:
    int serialize(char* pOut, unsigned int len )
    {
        if (pOut == NULL || len==0)
        {
            return -1;
        }
        CBytebuffer bb(pOut, len, pFmt);
        return serialize(&bb);
    }
#define CHECK_RETURN(s)\
    if (!s)\
    {\
        return -1;\
    }
"""
hfile_class_serialize_option_system = """
        if (has_%(attrname)s())
        {
        ####这行有bug
            CHECK_RETURN(pbb->write_varint32(pbb->build_tag(e_%(attrname)s, e_dt_with_head_length)));
            CHECK_RETURN(pbb->write_%(datatype)s(_%(attrname)s));
        }
"""
hfile_class_serialize_option_selftype = """
        if (has_%(attrname)s())
        {
            CHECK_RETURN(pbb->write_varint32(pbb->build_tag(e_%(attrname)s, e_dt_with_head_length)));
            char temp[1024];
            int len = 0;
            CHECK_RETURN((len = _%(attrname)s.serialize(temp, 1024))>0);
            CHECK_RETURN(pbb->write_varint32(len));
            CHECK_RETURN(pbb->append(temp, len));
        }
"""
hfile_class_serialize_repeated_system = """
        if (size_of_%(attrname)s()>0)
        {
            CHECK_RETURN(pbb->write_varint32(pbb->build_tag(e_%(attrname)s, e_dt_with_head_length)));
            char temp[1024] = "";
            CBytebuffer bb(temp, 1024, pFmt);
            for (unsigned int i = 0; i<size_of_%(attrname)s(); i++)
            {
                CHECK_RETURN(bb.write_%(datatype)s(%(attrname)s(i)));
            }
            CHECK_RETURN(pbb->write_varint32(bb.payload()));
            CHECK_RETURN(pbb->write_varint32(size_of_%(attrname)s()));
            CHECK_RETURN(pbb->append(temp, bb.payload()));
        }
"""
hfile_class_serialize_repeated_selftype = """
        if (size_of_%(attrname)s() > 0)
        {
            int count = size_of_%(attrname)s();
            char tb[1024*10] = "";
            CBytebuffer tempbuf(tb, 1024*10, pFmt);
            for (int i=0; i<count; i++)
            {    
                char temp[1024] = "";
                int len = 0;
                CHECK_RETURN((len = %(attrname)s(i).serialize(temp, 1024))>0);
                CHECK_RETURN(tempbuf.write_varint32(len));
                CHECK_RETURN(tempbuf.append(temp, len));
            }
            CHECK_RETURN(pbb->write_varint32(pbb->build_tag(e_%(attrname)s, e_dt_with_head_length)));
            CHECK_RETURN(pbb->write_varint32(tempbuf.payload()));
            CHECK_RETURN(pbb->write_varint32(count));
            CHECK_RETURN(pbb->append(tb, tempbuf.payload()));
        }
"""
hfile_class_serialize_mutable = """
    int serialize(CBytebuffer* pbb)
    {
        if (pbb == NULL)
        {
            return -1;
        }
%(attrs)s
        return pbb->payload();
    }
"""
"""

typedef struct  person
{
    //option  1
    string name;
    //option    2
    string phoneNo;
    //option  3
    int age;
    //repeated  4
    std::vector<string> skill;
}st_person;
"""
"""
hfile_head
hfile_class_head
    hfile_class_consturctor
    hfile_class_copy_constructor
    hfile_class_operator_euqal
    hfile_class_destructor
    hfile_class_statment
    hfile_class_parse
    hfile_class_serialize
hfile_class_end
"""
def get_head(stname, st):
    str = hfile_head + hfile_class_head%{'classname':stname}
    return str
    
def get_constructor(stname, st):
    init_immutable = hfile_class_init_immutable
    str = hfile_class_constructor%{'classname':stname,'init_immutable':init_immutable}
    return str
def get_copy_constructor(stname, st):
    init_immutable = hfile_class_init_immutable%{'classname':stname}
    l = list()
    for n in st:
        if st[n][2] == 'option':
            l.append(hfile_class_init_mutable_option%{'attrname':n})
        else:
            l.append(hfile_class_init_mutable_repeated%{'attrname':n})
    init_mutable = "".join(l) 
    str = hfile_class_copy_constructor%{'classname':stname,'init_immutable':init_immutable,'init_mutable':init_mutable}
    return str

#
def get_operator_equal(stname, st):
    init_immutable = hfile_class_init_immutable%{'classname':stname}
    l = list()
    for n in st.keys():
        if st[n][2] == 'option':
            l.append(hfile_class_init_mutable_option%{'attrname':n})
        else:
            l.append(hfile_class_init_mutable_repeated%{'attrname':n})
    init_mutable = "".join(l) 
    str = hfile_class_operator_equal%{'classname':stname,'init_immutable':init_immutable,'init_mutable':init_mutable}
    return str
def get_destructor(stname, st):
    str = hfile_class_destructor%{'classname':stname,'uninit_immutable':hfile_class_uninit_immutable}
    return str
def get_statement(stname, st):
    statement_immutable = hfile_class_immutable_satement%{'mask_size':len(st)/32+1}
    l_e = list()
    l_o = list()
    l_r = list()
    for n in st.keys():
        l_e.append(hfile_class_attr_enum_format%{'attr_name':n,'idx':st[n][0]})
        if st[n][2] == 'option':
            if type.get(st[n][1], None) == None:
                l_o.append(hfile_class_attr_format%{'attr_type':'OPTION','attr_data':'CMiniPb_%s'%st[n][1],'attr_name':n})
            else:
                l_o.append(hfile_class_attr_format%{'attr_type':'OPTION','attr_data':st[n][1],'attr_name':n})
        else:
            if type.get(st[n][1], None) == None:
                l_r.append(hfile_class_attr_format%{'attr_type':'REPEATED','attr_data':'CMiniPb_%s'%st[n][1],'attr_name':n})
            else:
                l_r.append(hfile_class_attr_format%{'attr_type':'REPEATED','attr_data':st[n][1],'attr_name':n})
    attr_enum = hfile_class_attr_enum%{'attr_enum_format':''.join(l_e)}
    attr_format = ''.join(l_o+l_r)
    statement_mutable = hfile_class_mutable_statement%{'attr_enum':attr_enum,'attr_format':attr_format}
    str = statement_immutable+statement_mutable
    return str

type = {
"int" :"varint32",
"int64" :"varint64", 
"string" :"string",
       }
type_id = {
"int" :"e_dt_varint",
"int64" :"e_dt_varint", 
"string" :"e_dt_with_head_length",
       }
default_type_id = "e_dt_with_head_length"
def get_parse(stname, st):
    l_o_s = list()
    l_o_t = list()
    l_r_s = list()
    l_r_t = list()
    for n in st.keys():
        if st[n][2] == 'option':
            if type.get(st[n][1], None) == None:
                l_o_t.append(hfile_class_parse_attr_option_selftype%{'attrname':n})
            else:
                l_o_s.append(hfile_class_parse_attr_option_system%{'attrname':n,'attr_datatype':type[st[n][1]]})
        else:
            if type.get(st[n][1], None) == None:
                l_r_t.append(hfile_class_parse_attr_repeated_selftype%{'attrname':n})
            else:
                l_r_s.append(hfile_class_parse_attr_repeated_system%{'attrname':n,'datatype_o':st[n][1],'datatype':type[st[n][1]]})
    attr = ''.join(l_o_s+l_o_t+l_r_s+l_r_t)
    parse_mutable = hfile_class_parse_mutable%{'attr':attr}
    parse_immutable = hfile_class_parse_immutable
    str = parse_immutable + parse_mutable
    return str
    
def get_serialize(stname, st):
    l_o_s = list()
    l_o_t = list()
    l_r_s = list()
    l_r_t = list()
    for n in st.keys():
        if st[n][2] == 'option':
            if type.get(st[n][1], None) == None:
                l_o_t.append(hfile_class_serialize_option_selftype%{'attrname':n})
            else:
                l_o_s.append(hfile_class_serialize_option_system%{'attrname':n,'datatype':type[st[n][1]]})
        else:
            #repeated
            if type.get(st[n][1], None) == None:
                l_r_t.append(hfile_class_serialize_repeated_selftype%{'attrname':n})
            else:
                l_r_s.append(hfile_class_serialize_repeated_system%{'attrname':n,'datatype':type[st[n][1]]})
    attrs = ''.join(l_o_s+l_o_t+l_r_s+l_r_t)
    serialize_mutable = hfile_class_serialize_mutable%{'attrs':attrs}
    serialize_immutable = hfile_class_serialize_immutable
    str = serialize_immutable + serialize_mutable
    return str

def get_end(stname, st):
    str = hfile_class_end
    return str

"""from person_miniprotobuf import *
for i in struct.keys():
    print get_head(i,struct[i])
    print get_constructor(i,struct[i])
    print get_copy_constructor(i,struct[i])
    print get_operator_equal(i,struct[i])
    print get_destructor(i,struct[i])
    print get_statement(i,struct[i])
    print get_parse(i,struct[i])
    print get_serialize(i,struct[i])
    print get_end(i,struct[i])
"""