CC = g++
CFLAGS = -g -Wall
INCLUDE = /home/nakao/PPPUCPP

TARGET = practice0604

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(TARGET) $(TARGET).cpp
clean:
	-rm *.o $(TARGET)

test: $(TARGET)
	@echo
	./$(TARGET)
	@echo
	    
