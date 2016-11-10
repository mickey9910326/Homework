# encoding: utf-8

import urllib,urllib2
url = "http://140.115.66.86/MCregisterSys2016/state.php"

request = urllib2.Request(url)
request.add_header("User-Agent","Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36")

reg = {
    "login_check":"1",
    "w_id_flag":"15",
    "stud_name":"李興儀",
    "stud_id":"101602003",
    "stud_db":"9999"
}

# 0:掛號
# login_check:1
# w_id_flag:0
# stud_id:1
# stud_name:胖虎
# stud_db:1
# stud_lb:0

reg = urllib.urlencode(reg)

response = urllib2.urlopen(request,data=reg)
html = response.read()

# file_out = file("01_thsrc.html",'w')
# file_out.write(html)
# file_out.close()


# curl 'http://140.115.66.86/WANG/state.php' -H 'Cookie: PHPSESSID=tlvpo9ilcqnhdf0srqn5ft3p92' -H 'Origin: http://140.115.66.86' -H 'Accept-Encoding: gzip, deflate' -H 'Accept-Language: zh-TW,zh;q=0.8,en-US;q=0.6,en;q=0.4' -H 'Upgrade-Insecure-Requests: 1' -H 'User-Agent: Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.116 Safari/537.36' -H 'Content-Type: application/x-www-form-urlencoded' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' -H 'Cache-Control: max-age=0' -H 'Referer: http://140.115.66.86/WANG/state.php' -H 'Connection: keep-alive' --data '5=%E6%8E%9B%E8%99%9F&login_check=1&w_id_flag=5&stud_id=5&stud_name=%E9%80%B2%E9%A6%99&stud_db=5&stud_lb=4' --compressed
