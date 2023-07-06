from socket import *
import sys
import time
import base64

soc_udp = socket(AF_INET,SOCK_DGRAM)
rcvip="10.0.0.2"
port = 1234
buffer_size =512
rcv_addr = (rcvip,port)

filename="testFile.jpg"

fl=open(filename,"rb")
sndpkt =base64.b64encode( fl.read(buffer_size)).decode()
#print(sndpkt)
sndpkt1=base64.b64encode( fl.read(buffer_size)).decode()
i=0
#msg="0"+sndpkt
#print(msg)
rtrn=0
start=time.time()
while (sndpkt1):
	#x=i%2
	#print(x)
	seqnum=str(i)
	n=len(seqnum)
	for x in range(16-n) :
		seqnum="0"+seqnum
	msg=seqnum + sndpkt + "0"
    #print(msg)
	#if(i==1 or i==0) :
		#print(msg)	
	if(soc_udp.sendto(msg.encode(),rcv_addr)):
		
		while True:
			try:
				soc_udp.settimeout(0.1)
				rcvmsg,addr = soc_udp.recvfrom(buffer_size)
				rcvmsg=int(rcvmsg.decode())
				if rcvmsg==i:
					break
				#else:
					#soc_udp.settimeout(0.1)
			except timeout :
				rtrn=rtrn+1
				soc_udp.sendto(msg.encode(),rcv_addr)



		
		sndpkt = sndpkt1
		sndpkt1=base64.b64encode( fl.read(buffer_size)).decode()
		i=i+1


seqnum=str(i)
n=len(seqnum)
for x in range(16-n):
   	seqnum="0"+seqnum
msg= seqnum +sndpkt + "1"
soc_udp.sendto(msg.encode(),rcv_addr)
while True:
			try:
				soc_udp.settimeout(0.1)
				rcvmsg,addr = soc_udp.recvfrom(buffer_size)
				rcvmsg=int(rcvmsg.decode())
				if rcvmsg==i:
					break
			except timeout :
				rtrn=rtrn+1
				soc_udp.sendto(msg.encode(),rcv_addr)
#soc_udp.close()
fl.close()
end=time.time()
print('time taken=',end-start)
print('number of retransmissions=',rtrn)
print('throughput=',(1172.316)/float(end-start))
