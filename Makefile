CC=gcc
CFLAGS= -Werror -Wall -g
TARGET= 1d

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
