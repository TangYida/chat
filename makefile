CC=g++
FLAGS=-std=c++0x -Wall -Wextra -g

chat: chat.cpp
	$(CC) -o chat chat.cpp $(FLAGS)

run:
	./chat -u tangyida0 -r htpmqk99
