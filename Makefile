CC=gcc
CFLAGS= -Werror -Wall -pthread -g
TARGET= prime_number_mutex

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
