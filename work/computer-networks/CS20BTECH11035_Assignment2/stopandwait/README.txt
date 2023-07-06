README
Start mininet instance using
* sudo mn
xterm into host h1 and h2 using commands 
* “xterm h1” in h1 
* “xterm h2” in h2
Run the following commands
* sudo tc qdisc add dev h1-eth0 root netem rate 10Mbit limit 100     (execute from xterm h1)
              sudo tc qdisc add dev h2-eth0 root netem rate 10Mbit limit 100    (execute from xterm h2)

* sudo tc qdisc change dev h1-eth0 root netem delay 5ms  (execute from xterm h1)
              sudo tc qdisc change dev h2-eth0 root netem delay 5ms  (execute from xterm h2)

* sudo tc qdisc change dev h1-eth0 root netem loss 5%  (execute from xterm h1)
              sudo tc qdisc change dev h2-eth0 root netem loss 5%  (execute from xterm h2)
Run receiver code using 
* “python3 CS20BTECH11035_receiverStopWait.py” in h2
Run sender code using
* “python3 CS20BTECH11035_senderStopWait.py” in h1
