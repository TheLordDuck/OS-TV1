CC=gcc
CFLAGS= -Werror -Wall -pthread -g
TARGET= 2a_process

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
