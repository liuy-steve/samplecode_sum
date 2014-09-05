
import socket,sys

def daytimecli(url):
    if url == '':
        url = '127.0.0.1'
    try:
        print("Server Ip = ", url)
        print("Creating socket...")
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        print("done.")

        print("Conneting to remote host...")
        s.connect((url, 13))
        print("done.")

        while (1):
            try:
                buf = s.recv(1024)
            except socket.error as e:
                print("socket read error!")
            if len(buf) == 0:
                break
            print("time is ...", buf)

        print("close connection...")
        s.close()
        print("done.")
    except socket.error as e:
        print("socket error!")
        sys.exit(1)
    
