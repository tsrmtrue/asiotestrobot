# -*- coding: utf8 -*-
import MySQLdb
import sys
sys.path.append('../')
import server_cfg

from parse_sql_str import *


#main("_te")

def alter_tables_set_unsigned(_host, _user, _passwd, _port, _dbname):
    conn=MySQLdb.connect(host=_host, user=_user, passwd=_passwd, port=_port)
    
    cursor=conn.cursor()
    
    cursor.execute("use %(_dbname)s;"%(locals()))
    
    cursor.execute("ALTER TABLE role MODIFY `accountid` INTEGER(11) NOT NULL;")
    cursor.execute("ALTER TABLE role MODIFY `level` INTEGER(11) DEFAULT '1';")
    cursor.execute("ALTER TABLE role MODIFY `professionId` INTEGER(11) DEFAULT '100001' COMMENT 'see the document for profession';")
    cursor.execute("ALTER TABLE role MODIFY `exp` INTEGER(11) DEFAULT '0' COMMENT 'experience,for  current level';")
    cursor.execute("ALTER TABLE role MODIFY `popularity` INTEGER(11) DEFAULT '0' COMMENT 'popularity';")
    cursor.execute("ALTER TABLE role MODIFY `expTotal` INTEGER(11) DEFAULT '0' COMMENT 'total experience from birth';")
    cursor.execute("ALTER TABLE role MODIFY `starlevel` INTEGER(11) DEFAULT '1' COMMENT 'star level';")
    cursor.execute("ALTER TABLE role MODIFY `currentGuid` INTEGER(11) DEFAULT '2' COMMENT 'current guid for all objects owned by one role';")
    cursor.execute("ALTER TABLE role MODIFY `money` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'money';")
    cursor.execute("ALTER TABLE role MODIFY `diamond` INTEGER(11) UNSIGNED DEFAULT '0' COMMENT 'money';")
    cursor.execute("ALTER TABLE role MODIFY `exploit` INTEGER(11) DEFAULT '0' COMMENT 'exploit';")
    cursor.execute("ALTER TABLE role MODIFY `vigor` INTEGER(11) DEFAULT '0' COMMENT 'vigor for role';")
    cursor.execute("ALTER TABLE role MODIFY `isInit` INTEGER(11) DEFAULT '0' COMMENT 'if it is 0,it should be initialized';")
    cursor.execute("ALTER TABLE role MODIFY `loginCount` INTEGER(11) DEFAULT '0' COMMENT 'login count';")
    cursor.execute("ALTER TABLE role MODIFY `showLevel` INTEGER(11) DEFAULT '0' COMMENT 'show level';")
    cursor.execute("ALTER TABLE role MODIFY `currentArrayId` INTEGER(11) DEFAULT '111101' COMMENT 'current array id';")

    print "OK"
    cursor.close()
    conn.close()
 
alter_tables_set_unsigned("127.0.0.1", "root", "root", 7001, "lj_ts_1")    
#rebuild_tables(server_cfg.db_ip, server_cfg.db_user, server_cfg.db_pwd, server_cfg.db_port, server_cfg.db_name)
print "ALL OK"