import socket, sys, time

def daytimesvr():
    try:
        print("Creating socket...")
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("done.")

        print("binding to local host...")
        s.bind(("127.0.0.1", 13))
        print("done.")

        print("listening...")
        s.listen(0)
        print("done.")
        
        print("Accept connection...")
        s_accept, s_info = s.accept()
        print("done.")
        print("Client Ip = ", s_info)
        
  
        
        try:
            buf = s_accept.send(time.strftime('%Y-%m-%d',time.localtime(time.time())).encode())
        except socket.error as e:
            print("socket send error!", e)
                  
        print("close connection...")
        s.close()
        print("done.")
    except socket.error as e:
        print("socket error!", e)
        sys.exit(1)
