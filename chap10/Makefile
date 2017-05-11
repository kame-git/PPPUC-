CC = g++
CFLAGS = -g -Wall -Wno-deprecated
LIBS =
INCLUDES = ..

TARGET = Reading

$(TARGET) : $(TARGET).cpp
	$(CC) $(CFLAGS) $(LIBS) -I$(INCLUDES) -o $@ $^

clean:
	-rm $(TARGET)
	
