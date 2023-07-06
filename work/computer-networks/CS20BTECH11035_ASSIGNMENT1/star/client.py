import socket
import time
serverIP = "10.0.1.2"

dst_ip = raw_input("Enter cache IP: ")
s = socket.socket()

print(dst_ip)

port = 12346

s.connect((dst_ip, port))

#Write your code here:
#1. Add code to send HTTP GET / PUT / DELETE request. The request should also include KEY.
request_str = raw_input("Enter HTTP request: ")
request_str=request_str+'\r\n\r\n'
st=time.time()
s.send(request_str.encode())
#2. Add the code to parse the response you get from the server.

print ('Client received :'+str(s.recv(1024).decode())[9:-5])
ed=time.time()
print('Time taken=',ed-st)
s.close()
