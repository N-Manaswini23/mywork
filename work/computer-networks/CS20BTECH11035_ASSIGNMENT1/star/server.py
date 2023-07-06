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
dict={'key1':'val1','key2':'val2','key3':'val3','key4':'val4','key5':'val5','key6':'val6'}
while True:
  c, addr = s.accept()
  print ('Got connection from', addr )
  recvmsg = c.recv(1024).decode()
  print('Server received '+recvmsg)
  #c.send('Hello client'.encode())
  msg=str(recvmsg)
  #print(msg)
  x=msg.find(' HTTP')
  key1=msg[25:x]
  #print('key=',key1)
  if key1 in dict:
           valuee=dict[key1]
           resp='HTTP/1.1 '+valuee+' \r\n\r\n'
           c.send(resp.encode())
  else:
             c.send('HTTP/1.1 Error:100. Given key not found \r\n\r\n'.encode())
    
 #Write your code here
  #1. Uncomment c.send 
  #2. Parse the received HTTP request
  #3. Do the necessary operation depending upon whether it is GET, PUT or DELETE
  #4. Send response
  ##################

  c.close()
  #break