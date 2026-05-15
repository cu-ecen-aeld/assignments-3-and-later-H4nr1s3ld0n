CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra

TARGET = writer
SRC = writer.c

$(TARGET) : $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: clean
