CC=gcc
CFLAGS= -Werror -Wall -g
TARGET= 2a_test

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
