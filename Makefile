CC=gcc
CFLAGS= -Werror -Wall -g
TARGET= 1c

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
