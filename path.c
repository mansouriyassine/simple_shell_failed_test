#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_path - Get the PATH environment variable
 * @env: The environment variables
 *
 * Return: The PATH variable if found, NULL otherwise
 */
char *(get_path(char **env)) {
return (get_variable("PATH", env));
}

/**
 * split_path - Split the PATH variable into directories
 * @path: The PATH variable value
 *
 * Return: An array of directory strings, or NULL on failure
 */
char **(split_path(char *path)) {
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));

if (!tokens)
return (NULL);

char *token = strtok(path, ":");
while (token) {
tokens[position] = token;
position++;

if (position >= bufsize) {
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens) {
frintf(stderr, "Allocation error\n");
return (NULL);
}
}

token = strtok(NULL, ":");
}

tokens[position] = NULL;
return (tokens);
}

/**
 * find_executable - Find the full path to an executable
 * @command: The name of the command
 * @directories: The array of directory strings from PATH
 *
 * Return: The full path to the executable, or NULL if not found
 */
char *(find_executable(const char *command, char **directories)) {
char *executable;
int i;

if (!command || !directories)
return (NULL);

for (i = 0; directories[i] != NULL; i++) {
executable = _strcat(directories[i], "/");
executable = _strcat(executable, command);
if (access(executable, X_OK) == 0)
return (executable);
free(executable);
}

return (NULL);
}
