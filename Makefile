CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJS = shell.o builtin.o parser.o executor.o utils.o history.o variables.o path.o signals.o error_handling.o print_prompt.o read_line.o free_info.o
TARGET = simple_shell

all: $(TARGET)

$(TARGET): $(OBJS)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

shell.o: shell.h shell.c
$(CC) $(CFLAGS) -c shell.c

builtin.o: shell.h builtin.c
$(CC) $(CFLAGS) -c builtin.c

parser.o: shell.h parser.c
$(CC) $(CFLAGS) -c parser.c

executor.o: shell.h executor.c
$(CC) $(CFLAGS) -c executor.c

utils.o: shell.h utils.c
$(CC) $(CFLAGS) -c utils.c

history.o: shell.h history.c
$(CC) $(CFLAGS) -c history.c

variables.o: shell.h variables.c
$(CC) $(CFLAGS) -c variables.c

path.o: shell.h path.c
$(CC) $(CFLAGS) -c path.c

signals.o: shell.h signals.c
$(CC) $(CFLAGS) -c signals.c

error_handling.o: shell.h error_handling.c
$(CC) $(CFLAGS) -c error_handling.c

print_prompt.o: shell.h print_prompt.c
$(CC) $(CFLAGS) -c print_prompt.c

read_line.o: shell.h read_line.c
$(CC) $(CFLAGS) -c read_line.c

free_info.o: shell.h free_info.c
$(CC) $(CFLAGS) -c free_info.c

clean:
rm -f $(OBJS)

fclean: clean
rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
