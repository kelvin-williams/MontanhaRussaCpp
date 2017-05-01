CC = g++


all:
	$(CC) Main.cpp -pthread -o montruss -std=gnu++11

