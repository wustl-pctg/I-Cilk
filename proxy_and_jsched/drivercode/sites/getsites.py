import os, requests, sys


if len(sys.argv) != 2:
    print ('need 2 args!')
    exit(0)


f=open(sys.argv[1])
out=open("good_sites.txt","w+", 0)
for l in f:
    try:
        r=(requests.get(l[0:len(l)-1],timeout=2))
        if r.status_code==200:
            out.write(l)
            print ('Good: ' + l + ' ' + str(r.status_code))
        print ('Good: ' + l + ' ' + str(r.status_code))
    except:
        print ('Bad: ' + l)
