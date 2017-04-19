CC=g++
CFLAGS=-Wall -g -Wno-deprecated
INCLUDES=/home/nakao/PPPUCPP/
TARGET=date

$(TARGET): date.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@

clean:
	-rm *.o $(TARGET)

