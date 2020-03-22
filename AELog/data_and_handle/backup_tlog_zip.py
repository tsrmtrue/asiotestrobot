#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import datetime

os.chdir('./log')

def move_and_tar(tar_path):
    now = datetime.datetime.now().strftime('%Y-%m-%d-%H-%M-%S')
    now_l = now.split('-')
    today_year = int(now_l[0])
    today_month = int(now_l[1])
    today_day = int(now_l[2])
    today_hour = int(now_l[3])

    all_source_file = os.listdir("./")
    all_handled_file = os.listdir(tar_path)
    all_need_tar_file = []
    # print all_source_file
    for f in all_source_file:
        new_f = f.replace("_", "-")
        sp_list = new_f.split("-")
        #[tlog, server, serverid, line, year, month, day, hour.tlog]
	if sp_list[0] <> 'tlog':
            continue

        if len(sp_list) == 8 :
            day = int(sp_list[6])
            month = int(sp_list[5])
            hour = int(sp_list[7][:-5])
            # if month *10000 + day*100 +hour < 9 *10000 + 16*100 + 0:
            #     continue

            print new_f

            if month *10000 + day*100 +hour < today_month *10000 + today_day*100 + today_hour:
                if not f in all_handled_file:
                    os.system("tar -czf %(tar_path)s/%(f)s %(f)s"%(locals()))
                    # os.system("scp %(tar_path)s/%(f)s root@10.0.150.34:/data/tlog"%(locals()))
                    print f

"""
将脚本放置在log目录外面。
创建和log同路径的文件夹tlog_backup_zip。
每5分钟做一次扫描。把已经完成的日志，也就是上个小时的日志文件，逐个压缩，并放入tlog_backup_zip。
可以把每5分钟，做成每个小时的05分。
"""
#使用crontab
#*/5 * * * * cd /data/ro_out_chenxi; python backup_tlog_zip.py
target_temp = "../tlog_backup_zip"
move_and_tar(target_temp)
