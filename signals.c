#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * signal_handler - Handle signals
 * @sig: The signal number
 */
void signal_handler(int sig)
{
if (sig == SIGINT)
{
_putchar('\n');
print_prompt();
}
}

/**
 * set_signal_handler - Set signal handler for SIGINT
 */
void set_signal_handler(void)
{
signal(SIGINT, signal_handler);
}
