#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Struct to store shell information */
typedef struct info_struct
{
char **args;
char *command;
char *input_file;
char *output_file;
int background;
} info_t;

/* Struct for built-in commands and their functions */
typedef struct builtin_func
{
char *cmd;
int (*func)(info_t *);
} builtin_func;

/* Utility functions */
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
int _putchar(char c);
void print_number(int n);

/* Built-in command implementations */
int builtin_cd(info_t *info);
int builtin_help(info_t *info);
int builtin_exit(info_t *info);

/* Functions for parsing user input */
char *read_line(void);
info_t *parse_line(char *line);

/* Functions for executing commands */
int launch(info_t *info);
int execute(info_t *info);

/* Utility functions for shell */
void print_prompt(void);
void free_info(info_t *info);

/* Functions for handling command history */
void add_to_history(char *command);
void print_history(void);

/* Functions for handling environment variables and variables */
char *get_env_var(char *var_name);
int set_env_var(char *var_name, char *var_value);
int unset_env_var(char *var_name);

/* Functions for handling the PATH environment variable */
char *get_full_path(char *command);
void free_path_list(void);

/* Signal handling */
void sigint_handler(int signo);
void sigquit_handler(int signo);

/* Error handling functions */
void print_error(char *message);

/* Main loop */
void loop(void);

#endif /* SHELL_H */