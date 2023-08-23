#include "shell.h"

/**
* main - Entry point of the simple shell
*
* Return: Always 0
*/
void print_prompt(void);
char *read_line(void);

int main(void)
{
char *line;
info_t *info;

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

execute(info);
free_info(info);
free(line);
}

return (0);
}

void print_prompt(void)
{
}

char *read_line(void)
{
return (NULL);
}
