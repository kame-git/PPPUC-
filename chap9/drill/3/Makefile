CC=g++
CFLAGS=-Wall -g -Wno-deprecated -fpermissive
INCLUDES=/home/nakao/PPPUCPP/
TARGET=date

$(TARGET): date.cpp
	$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@

clean:
	-rm *.o $(TARGET)

