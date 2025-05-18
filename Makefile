
CC = gcc 

CFLAGS = -Wall -Wextra -std=c99 -g

LDLIBS = -lm

SRCS = main.c vector.c utils.c collisions.c shape.c

TARGET = main

all: $(TARGET)
	@chmod +x $(TARGET)
	@./$(TARGET)
	@echo "Finished executing."

$(TARGET): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)
	@echo "Finished compile."

clean:
	@rm -f $(TARGET)
	@echo "Cleaned all targets."

.PHONY: all clean

