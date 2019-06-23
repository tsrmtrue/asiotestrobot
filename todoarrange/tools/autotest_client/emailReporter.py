#coding=gbk  
  
import smtplib   
  
smtp = smtplib.SMTP()   
smtpServer = "smtp.163.com"#"gmail-smtp-in.l.google.com"
smtpPort = "25"#"465"
emailAccount = "tsrmtrue@163.com"#'tsrmtrue@gmail.com'
emailPwd= "nukecusn12!@"
smtp.connect(smtpServer, smtpPort)   
smtp.login(emailAccount, emailPwd)   
toEmailAccount = 'tsrmtrue@gmail.com'
email = """From: %(emailAccount)s/r/nTo: %(toEmailAccount)s/r/nSubject: this is a email from python demo/r/n/r/nJust for test~_~"""
smtp.sendmail(emailAccount, toEmailAccount, email%(locals()))   
smtp.quit()  
