all : 
	gcc -o client client.c utils.c
	gcc -o server server.c utils.c