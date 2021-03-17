CC=gcc
CFLAGS= -Werror -Wall -g
TARGET= fork_combinations

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
