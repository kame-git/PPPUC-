CC = g++
CFLAGS = -g -Wall
INCLUDE = /home/nakao/PPPUCPP

TARGET = practice0606

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(TARGET) $(TARGET).cpp
clean:
	rm $(TARGET)

tags: $(TARGET)
	ctags -R

test: $(TARGET)
	@echo
	./$(TARGET) < test.dat
	@echo
	    
