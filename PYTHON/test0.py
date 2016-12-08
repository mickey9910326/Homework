# encoding: utf-8

import urllib,urllib2
# url = "http://www.thsrc.com.tw/tw/TimeTable/SearchResult"
url = "http://140.115.66.86/WANG/state.php"

request = urllib2.Request(url)
request.add_header("User-Agent","Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36")

# form_data = {
#     "StartStation": "977abb69-413a-4ccf-a109-0272c24fd490",
#     "EndStation": "f2519629-5973-4d08-913b-479cce78a356",
#     "SearchDate": "2016/01/10",
#     "SearchTime": "17:00",
#     "SearchWay":"DepartureInMandarin",
#     "RestTime":"",
#     "EarlyOrLater":""
# }

form_data  = {
    "login_check":"1",
    "w_id_flag":"12",
    "stud_id":"55555",
    "stud_name":"小亮",
    "stud_db":"5",
    "stud_lb":"4"
}
# 5:掛號
# login_check:1
# w_id_flag:5
# stud_id:5
# stud_name:進香
# stud_db:5
# stud_lb:4

# 4:掛號
# login_check:1
# w_id_flag:4
# stud_id:5
# stud_name:進香
# stud_db:5
# stud_lb:4

de_reg = {
    "8":"取消",
    "login_check":"2",
    "w_id_flag":"0",
    "stud_id":"5",
    "stud_name":"進香",
    "stud_db":"5",
    "stud_lb":"4"
}

# 4:取消
# login_check:2
# w_id_flag:4
# stud_id:5
# stud_name:進香
# stud_db:5
# stud_lb:4

# 8:取消
# login_check:2
# w_id_flag:8
# stud_id:5
# stud_name:進香
# stud_db:5
# stud_lb:4

form_data = urllib.urlencode(form_data)
# form_data = "userid=102303512&passwd=35125216";

# de_reg = "reg_action=de_register&user_Now=102303512&stud_name=+%B1i%AEa%BE%F6%0D%0A&user_labNO=1&login_check=1&row=20&action_de_reg=%A8%FA%AE%F8";
# de_reg = "reg_action=de_register&row=20";
de_reg = urllib.urlencode(de_reg)


# reg = "reg_action=register&user_Now=102303512&stud_name=+%B1i%AEa%BE%F6%0D%0A&user_labNO=1&row=20&login_check=1&action_de_reg=%B5n%B0O"
reg = "reg_action=register&user_Now=111222000&stud_name=+%B1i%AEa%BE%F6%0D%0A&user_labNO=1&row=20&login_check=1&action_de_reg=%B5n%B0O"

reg = {
    "4":"掛號",
    "login_check":"1",
    "w_id_flag":"15",
    "stud_id":"5",
    "stud_name":"進香666",
    "stud_db":"5",
    "stud_lb":"4"
}

reg = urllib.urlencode(reg)

response = urllib2.urlopen(request,data=de_reg)
html = response.read()

file_out = file("01_thsrc.html",'w')
file_out.write(html)
file_out.close()




#
# form_data  = {
#     userid:102303512,
#     passwd:35125216
# }

# POST /SMCregisterSys2016/login.php HTTP/1.1
# Host: 140.115.66.86
# Connection: keep-alive
# Content-Length: 32
# Cache-Control: max-age=0
# Origin: http://140.115.66.86
# Upgrade-Insecure-Requests: 1
# User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.106 Safari/537.36
# Content-Type: application/x-www-form-urlencoded
# Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
# Referer: http://140.115.66.86/SMCregisterSys2016/login.php
# Accept-Encoding: gzip, deflate
# Accept-Language: zh-TW,zh;q=0.8,en-US;q=0.6,en;q=0.4
# Cookie: PHPSESSID=aop629m3opnm3tk4upg68qicc3
