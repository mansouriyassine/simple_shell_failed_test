#include "shell.h"
#include <string.h>
#include <stdlib.h>

#define TOK_BUFSIZE 64

/**
 * split_line - Split input line into tokens
 * @line: The input line
 *
 * Return: Array of tokens
 */
static char **split_line(char *line)
{
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\n\r");
while (token)
{
tokens[position] = token;
position++;

if (position >= bufsize)
{
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\n\r");
}

tokens[position] = NULL;
return (tokens);
}

/**
 * create_info - Create and initialize info_t struct
 *
 * Return: Pointer to initialized info_t struct
 */
static info_t *create_info(void)
{
info_t *info = malloc(sizeof(info_t));
if (!info)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
info->args = NULL;
info->command = NULL;
info->input_file = NULL;
info->output_file = NULL;
info->background = 0;
return (info);
}

/**
 * parse_line - Parse input line into info_t struct
 * @line: The input line
 *
 * Return: Pointer to info_t struct containing parsed information
 */
info_t *parse_line(char *line)
{
char **tokens = split_line(line);
info_t *info = create_info();
info->args = tokens;
return (info);
}
