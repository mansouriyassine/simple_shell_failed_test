#include "shell.h"
#include <string.h>
#include <stdlib.h>

#define TOK_BUFSIZE 64

/**
 * parse_line - Parse input line into info_t struct
 * @line: The input line
 *
 * Return: Pointer to info_t struct containing parsed information
 */
info_t *parse_line(char *line) {
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char*));
char *token;
info_t *info;

if (!tokens) {
perror("Allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\n\r");
while (token) {
tokens[position] = token;
position++;

if (position >= bufsize) {
bufsize += TOK_BUFSIZE;
tokens = realloc(tokens, bufsize * sizeof(char*));
if (!tokens) {
perror("Allocation error");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, " \t\n\r");
}

tokens[position] = NULL;

info = malloc(sizeof(info_t));
if (!info) {
perror("Allocation error");
exit(EXIT_FAILURE);
}

info->args = tokens;
info->command = NULL;
info->input_file = NULL;
info->output_file = NULL;
info->background = 0;

return (info);
}
