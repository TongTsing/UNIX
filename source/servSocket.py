import socket

addr = ('127.0.0.1', 1132)

mainSock = socket.socket(family=socket.AF_INET, type=socket.SOCK_STREAM)

mainSock.bind(addr)
mainSock.listen(10)

while 1:
    cliSock, cliAddr = mainSock.accept()
    print("socket cnned!->{}\n".format(cliAddr))
