import socket
serverIP = "10.0.1.3"
#WRITE CODE HERE:
#1. Create a KEY-VALUE pairs (Create a dictionary OR Maintain a text file for KEY-VALUES).


dst_ip = raw_input("Enter cache IP: ")
serverIP = raw_input("Enter server IP: ")
s = socket.socket()
print ("Socket successfully created")

dport = 12346

s.bind((dst_ip, dport))
print ("socket binded to %s" %(dport))
s.listen(5)
print ("socket is listening")
dict={}




while True:
  c, addr = s.accept()
  print ('Got connection from', addr )
  recvmsg = c.recv(1024).decode()
  print('Server received '+recvmsg)
  #c.send('Hello client'.encode())
  msg=str(recvmsg)
  #print(msg)
  #print(msg[-13:-4])

  if msg[0:25]=='GET /assignment1?request=' and msg.endswith(" HTTP/1.1\r\n\r\n") :
       x=msg.find(' HTTP')
       if x==-1:
           c.send('HTTP/1.1 Error 200:Wrong syntax of GET. Syntax is  GET /assignment1?request=key1 HTTP/1.1 \r\n\r\n'.encode())
       else:
         key1=msg[25:x]
         print('key=',key1)
         if key1 in dict:
           print('found in cache')
           valuee=dict[key1]
           #print('val=',valuee)
           resp='HTTP/1.1 '+valuee+' \r\n\r\n'
           c.send(resp.encode())
         else:
             s1 = socket.socket()
             port = 12346
             s1.connect((serverIP, port))
             print('connecting to server')
             s1.send(msg.encode())
             recvmsg1 = s1.recv(1024).decode()
             msg1=str(recvmsg1)
             #print(msg1,' ',msg1[9:-5])
             c.send(msg1.encode())
             #print(msg1[9:-9])
             if  msg1!= 'HTTP/1.1 Error:100. Given key not found \r\n\r\n':
                 dict[key1]=msg1[9:-5]
             s1.close()
 
  else:
          c.send('HTTP/1.1 Error 600: Wrong syntax \r\n\r\n'.encode()) 
 #Write your code here
  #1. Uncomment c.send 
  #2. Parse the received HTTP request
  #3. Do the necessary operation depending upon whether it is GET, PUT or DELETE
  #4. Send response
  ##################
 
  c.close()
  #break