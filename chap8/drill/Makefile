CC = g++
CFLAGS = -Wall -g
INCLUDES = /home/nakao/PPPUCPP/
TARGET = drill1

$(TARGET) : use.o my.o
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $^
my.o : my.cpp my.h
	$(CC) -c $(CFLAGS) -I$(INCLUDES) my.cpp
use.o : use.cpp
	$(CC) -c $(CFLAGS) -I$(INCLUDES) use.cpp
clean:
	-rm *.o $(TARGET)
test:
	./$(TARGET)
