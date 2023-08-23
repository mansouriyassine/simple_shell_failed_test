#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TOK_BUFSIZE 64

char *get_env_var(const char *varname);
int access(const char *pathname, int mode);

/**
 * get_path - Get the PATH environment variable
 * @env: The environment variables
 *
 * Return: The PATH variable if found, NULL otherwise
 */
char *get_path(char **env) {
(void)env;
return (get_env_var("PATH"));
}

/**
 * split_path - Split the PATH variable into directories
 * @path: The PATH variable value
 *
 * Return: An array of directory strings, or NULL on failure
 */
char **split_path(char *path) {
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
return (NULL);

token = strtok(path, ":");
while (token) {
tokens[position] = strdup(token);
position++;

if (position >= bufsize) {
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens) {
perror("Allocation error");
exit(EXIT_FAILURE);
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
char *find_executable(const char *command, char **directories) {
char *executable = NULL;
int i;

if (!command || !directories)
return (NULL);

for (i = 0; directories[i] != NULL; i++) {
char *path = strdup(directories[i]);
char *temp_executable;

temp_executable = strcat(strcat(path, "/"), command);
if (access(temp_executable, X_OK) == 0) {
executable = temp_executable;
break;
}

free(path);
}

return (executable);
}
