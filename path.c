#include "shell.h"

#include <stdlib.h>
#include <unistd.h>

/* Function prototypes */
char *_strdup(const char *str);

/* Functions for handling the PATH environment variable */
char *get_full_path(char *command);
void free_path_list(void);

/* Implement _strdup function from utils.c */
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

/* Implement the get_full_path function */
char *get_full_path(char *command)
{
}

/* Implement the free_path_list function */
void free_path_list(void) 
{
}
