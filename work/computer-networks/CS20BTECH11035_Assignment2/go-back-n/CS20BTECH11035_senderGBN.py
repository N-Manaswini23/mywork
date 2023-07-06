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
pckts=[]
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
	pckts.append(msg)
	sndpkt = sndpkt1
	sndpkt1=base64.b64encode( fl.read(buffer_size)).decode()
	i=i+1
seqnum=str(i)
n=len(seqnum)
for x in range(16-n):
   	seqnum="0"+seqnum
msg= seqnum +sndpkt + "1"
pckts.append(msg)
#soc_udp.settimeout(0.01)
base=0
nextseqnum=0
windowsize=4
n_pack=len(pckts)
#print('n=',n_pack)
#for z in range(n_pack):
	#print(z ,'         ',pckts[z])
while nextseqnum<n_pack:
	#print('base=',base,' nextseqnum=',nextseqnum)
	while nextseqnum<n_pack and base+windowsize>nextseqnum:
		soc_udp.sendto(pckts[nextseqnum].encode(),rcv_addr)
		if base==nextseqnum:
			soc_udp.settimeout(0.01)
		nextseqnum=nextseqnum+1
	while base<nextseqnum:
		#print('base1=',base,' nextseqnum1=',nextseqnum)
		try:
			soc_udp.settimeout(0.01)
			rcvmsg,addr = soc_udp.recvfrom(buffer_size)
			rcvmsg=int(rcvmsg.decode())
			#print('rcvmsg=',rcvmsg,' base=',base,rcvmsg==base)
			if rcvmsg==base:
				base=base+1
			if rcvmsg>base:
				base=rcvmsg+1
				if nextseqnum<base:
					nextseqnum=base
		except timeout :
			nextseqnum=base
			rtrn=rtrn+1
			break



    #print(msg)
	#if(i==1 or i==0) :
		#print(msg)	
#soc_udp.close()
fl.close()
end=time.time()
print('time taken=',end-start)
print('number of retransmissions=',rtrn)
print('throughput=',(1172.316)/float(end-start) )