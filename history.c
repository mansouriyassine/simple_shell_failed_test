#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_history - Add a command to the history
 * @history: The history array
 * @command: The command to add
 */
void add_history(char **history, char *command) {
int i = 0;

while (history[i] != NULL)
i++;

history[i] = _strdup(command);
}

/**
 * print_history - Print the command history
 * @history: The history array
 */
void print_history(char **history) {
int i = 0;

while (history[i] != NULL) {
printf("%d: %s\n", i + 1, history[i]);
i++;
}
}

/**
 * free_history - Free the memory allocated for the history
 * @history: The history array
 */
void free_history(char **history) {
int i = 0;

while (history[i] != NULL) {
free(history[i]);
i++;
}

free(history);
}
