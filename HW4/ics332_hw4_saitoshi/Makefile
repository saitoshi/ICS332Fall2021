CC = gcc
CFLAGS =  -Wall -g

default: command_executor

command_executor: command_executor.o 
	$(CC) $^ -o $@

command_executor.o: command_executor.c solution.c
	$(CC) -c $(CFLAGS) -o $@ command_executor.c

clean:
	/bin/rm -f command_executor.o command_executor
