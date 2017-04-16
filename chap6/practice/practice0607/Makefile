CPP = g++
CFLAGS = -Wall -g -Wno-deprecated
LIBS = 
INCLUDES = /home/nakao/PPPUCPP/
TARGET = logical_calculator

$(TARGET): main.o token_stream.o
	$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $(TARGET)

token_stream.o: token_stream.cpp token.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -c token_stream.cpp -o token_stream.o

main.o: main.cpp token.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -c main.cpp -o main.o

clean:
	-rm *.o $(TARGET)
