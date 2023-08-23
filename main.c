#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
char *line;
info_t *info;
int status;

while (1)
{
print_prompt();
line = read_line();
if (!line)
break;

info = parse_line(line);
if (!info)
{
free(line);
continue;
}

status = execute(info);
if (status == 0)
break;

free_info(info);
free(line);
}

return (0);
}

void print_prompt(void)
{
printf("$ ");
}

char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
getline(&line, &bufsize, stdin);
return (line);
}
