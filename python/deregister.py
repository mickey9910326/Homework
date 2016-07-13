# encoding: utf-8

import urllib,urllib2
url = "http://140.115.66.86/SMCregisterSys2016/state.php"

request = urllib2.Request(url)
request.add_header("User-Agent","Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.106 Safari/537.36")

de_reg = {
    "reg_action" : "de_register",
    "row" : "0",
}

de_reg = urllib.urlencode(de_reg)

response = urllib2.urlopen(request,data=de_reg)
