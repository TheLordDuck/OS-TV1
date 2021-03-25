CC=gcc
CFLAGS= -Werror -Wall -g
TARGET= 1a

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
