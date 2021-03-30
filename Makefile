CC=gcc
CFLAGS= -Werror -Wall -pthread -g
TARGET= prime_number

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
