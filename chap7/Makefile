CC = g++
CFLAGS = -g -Wall -O0
TARGET = calc
INCLUDE = /home/nakao/PPPUCPP/

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(TARGET) $(TARGET).cpp

clean:
	-rm $(TARGET)

test: $(TARGET)
	@echo
	./$(TARGET)
	@echo

