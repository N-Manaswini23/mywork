import socket

#WRITE CODE HERE:
#1. Create a KEY-VALUE pairs (Create a dictionary OR Maintain a text file for KEY-VALUES).


dst_ip = raw_input("Enter Server IP: ")

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
           c.send('HTTP/1.1 Error 200:Wrong syntax of GET. Syntax is  GET /assignment1?request=key1 HTTP/1.1'.encode())
       else:
         key1=msg[25:x]
         if key1 in dict:
           valuee=dict[key1]
           resp='HTTP/1.1 '+valuee+' \r\n\r\n'
           c.send(resp.encode())
         else:
             c.send('HTTP/1.1 Error:100. Given key not found  \r\n\r\n'.encode())
    
  elif msg[0:17]=='PUT /assignment1/' and msg.endswith(" HTTP/1.1\r\n\r\n"):
       m=msg[17:]
       x=m.find('/')
       if x==-1:
         c.send('HTTP/1.1 Error:300. Wrong syntax of PUT. Syntax is PUT /assignment1/key1/val1 HTTP/1.1  \r\n\r\n'.encode())
       else:
         key1=m[0:x]
         m=m[x+1:]
         x=m.find(' HTTP')
         if x==-1:
            c.send('HTTP/1.1 Error:300. Wrong syntax of PUT. Syntax is PUT /assignment1/key1/val1 HTTP/1.1  \r\n\r\n'.encode())
         else:
            val1=m[0:x]
            dict[key1]=val1
            print(dict)
            c.send('HTTP/1.1 Successfully inserted  \r\n\r\n'.encode())
    
  elif msg[0:20]=='DELETE /assignment1/' and msg.endswith(" HTTP/1.1\r\n\r\n") :
       x=msg.find(' HTTP')
       if x==-1:
           c.send('HTTP/1.1 Error 500:Wrong syntax of DELETE. Syntax is  DELETE /assignment1/key1 HTTP/1.1  \r\n\r\n'.encode())
       else:
         key1=msg[20:x]
         if key1 in dict:
           dict.pop(key1)
           print(dict)
           c.send('HTTP/1.1 Successfully deleted  \r\n\r\n'.encode())
         else:
             c.send('HTTP/1.1 Error:400. Given key not found. Unsuccessful delete  \r\n\r\n'.encode())
     
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