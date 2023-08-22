#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * num_builtins - Get the number of built-in commands
 *
 * Return: The number of built-in commands
 */
int num_builtins(void) {
return (sizeof(builtin_functions) / sizeof(builtin_func));
}

/**
 * builtin_cd - Change the current working directory
 * @info: Pointer to shell_info struct
 *
 * Return: 1 on success, 0 on failure
 */
int builtin_cd(info_t *info) {
if (!info->args[1]) {
fprintf(stderr, "cd: expected argument\n");
return (1);
}

if (chdir(info->args[1]) != 0) {
perror("cd");
return (0);
}

return (1);
}

/**
 * builtin_exit - Exit the shell
 * @info: Pointer to shell_info struct
 *
 * Return: 0 on success, -1 on failure
 */
int builtin_exit(info_t *info) {
if (info->args[1]) {
int status = atoi(info->args[1]);
exit(status);
}
exit(0);
}

/**
 * builtin_alias - Implement the alias builtin command
 * @info: Pointer to shell_info struct
 *
 * Return: 0 on success, 1 on failure
 */
int builtin_alias(info_t *info) {
/* Implementation for task 13 - Alias builtin command */
return (0);
}

/**
 * builtin_variable - Handle environment and shell variables
 * @info: Pointer to shell_info struct
 *
 * Return: 0 on success, 1 on failure
 */
int builtin_variable(info_t *info) {
/* Implementation for task 3 - Handle variables */
return (0);
}

/**
 * execute_builtin - Execute a built-in command
 * @info: Pointer to shell_info struct
 *
 * Return: 1 if a built-in was executed, 0 otherwise
 */
int execute_builtin(info_t *info) {
int i, num_builtins;
builtin_func builtin_functions[] = {
{"cd", builtin_cd},
{"exit", builtin_exit},
{"alias", builtin_alias},
{"variable", builtin_variable},
};

num_builtins = sizeof(builtin_functions) / sizeof(builtin_func);

for (i = 0; i < num_builtins; i++) {
if (strcmp(info->args[0], builtin_functions[i].cmd) == 0) {
return (builtin_functions[i].func(info));
}
}

return (0);
}
