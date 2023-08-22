#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
while (1)
{
print_prompt();

char *line = read_line();
if (!line)
break;

info_t *info = parse_line(line);

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
