CC = g++
TARGET = calculator
INCLUDE = /home/nakao/PPPUCPP/
CFLAGS = -g -Wall
SOURCES = calculator08buggy.cpp

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) -I$(INCLUDE) $^ -o $@

clean:
	-rm $(TARGET) $(TARGET).o 

test:
	./$(TARGET)

tags:
	ctags -R
