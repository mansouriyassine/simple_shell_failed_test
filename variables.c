#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_variable - Set an environment variable
 * @name: The name of the variable
 * @value: The value to set
 * @env: The environment variables
 *
 * Return: (0) on success, (-1) on failure
 */
int set_variable(const char *name, const char *value, char ***env)
{
int i, len;
char *new_var;
char **new_env;

if (!name || !value || !env)
return (-1);

len = strlen(name) + strlen(value) + 2; /* for = and \0 */
new_var = malloc(len *sizeof(char));
if (!new_var)
return (-1);

strcpy(new_var, name);
strcat(new_var, "=");
strcat(new_var, value);

for (i = 0; (*env)[i] != NULL; i++)
{
if (strncmp((*env)[i], name, strlen(name)) == 0)
{
free((*env)[i]);
(*env)[i] = new_var;
return (0);
}
}

new_env = realloc(*env, (i + 2) * sizeof(char *));
if (!new_env)
{
free(new_var);
return (-1);
}

new_env[i] = new_var;
new_env[i + 1] = NULL;
*env = new_env;

return (0);
}

/**
 * get_variable - Get the value of an environment variable
 * @name: The name of the variable
 * @env: The environment variables
 *
 * Return: The value of the variable, or NULL if not found
 */
char *get_variable(const char *name, char **env)
{
int i, len;

if (!name || !env)
return (NULL);

len = strlen(name);

for (i = 0; env[i] != NULL; i++)
{
if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
{
return (&(env[i][len + 1]));
}
}

return (NULL);
}
