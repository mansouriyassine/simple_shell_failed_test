#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *_strdup(const char *str)
{
size_t len;
char *dup;

if (!str)
return (NULL);

len = strlen(str);
dup = malloc(len + 1);

if (!dup)
return (NULL);

strcpy(dup, str);
return (dup);
}

int _strcmp(const char *s1, const char *s2)
{
while (*s1 && *s1 == *s2)
{
s1++;
s2++;
}
return ((*s1 - *s2));
}

int _putchar(char c)
{
return (write(1, &c, 1));
}

void print_number(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}

if (n / 10)
print_number(n / 10);

_putchar(n % 10 + '0');
}
