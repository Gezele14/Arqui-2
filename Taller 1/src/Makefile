APP = ejercicio
BIN = ../bin
SRC1 = $(APP)1.c 
SRC2 = $(APP)2.c 

CC = gcc

APP: APP_1 APP_2

#Aplicacion con biblioteca estatica
APP_1: $(SRC)
		$(CC) -o $(BIN)/$(APP)1 $(SRC1) -pthread 

APP_2: $(SRC)
		$(CC) -o $(BIN)/$(APP)2 $(SRC2) -pthread


