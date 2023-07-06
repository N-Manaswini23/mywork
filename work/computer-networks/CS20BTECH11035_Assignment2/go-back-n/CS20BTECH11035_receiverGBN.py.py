from socket import *
import sys
import select
import base64

rcvip="10.0.0.2"
rcv_port = 1234
soc_udp = socket(AF_INET,SOCK_DGRAM)
soc_udp.bind((rcvip,rcv_port))
print("UDP socket created successfully....." )
rcv_addr = (rcvip,rcv_port)
buffer_size=1024
exp=0
while True:
  
  rcvmsg,addr = soc_udp.recvfrom(buffer_size)
  #print(rcvmsg)
  rcvmsg=rcvmsg.decode()
  rcvpkt=rcvmsg[16:-1]
  expectedseqnum=exp
  rcvseqnum=int(rcvmsg[12:16])
  #print(rcvmsg[12:16])
  #print(expectedseqnum,rcvseqnum)
  #print(rcvmsg[-1])
  fl = open('finalimage2.jpg','wb')
  while(rcvmsg[-1]=='0'):
    #print('exp=',expectedseqnum,' rcv=',rcvseqnum,expectedseqnum==rcvseqnum)
    if expectedseqnum==rcvseqnum:
      st=base64.b64decode((rcvpkt))
      #print(st)
      fl.write(st)
      #print('exseqnum=',expectedseqnum)
      expectedseqnum=1+expectedseqnum
    msg=str(expectedseqnum-1)
    soc_udp.sendto(msg.encode(),addr)
    rcvmsg,addr = soc_udp.recvfrom(buffer_size)
    #print(rcvmsg)
    rcvmsg=rcvmsg.decode()
    rcvpkt=rcvmsg[16:-1]
    rcvseqnum=int(rcvmsg[12:16])
    #print(rcvmsg[-1])
    #print(expectedseqnum,rcvseqnum)
    #print('xxx',rcvmsg[-1])
  if(rcvmsg[-1]=='1'):
    #print(expectedseqnum,rcvseqnum)
    if expectedseqnum==rcvseqnum:
      fl.write(base64.b64decode((rcvpkt)))
      msg=str(rcvseqnum)
      soc_udp.sendto(msg.encode(),addr)
      fl.close()
      exp=0
      #soc_udp.close()
      print ("Completed transfer")
    else:
      exp=expectedseqnum
      msg=str(expectedseqnum-1)
      soc_udp.sendto(msg.encode(),addr)