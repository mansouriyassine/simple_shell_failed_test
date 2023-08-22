#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * print_error - Print an error message
 * @format: The format string
 * @...: Additional arguments
 */
void print_error(const char *format, ...) {
va_list args;
va_start(args, format);
vfprintf(stderr, format, args);
va_end(args);
}

/**
 * error_exit - Print an error message and exit
 * @format: The format string
 * @...: Additional arguments
 */
void error_exit(const char *format, ...) {
va_list args;
va_start(args, format);
vfprintf(stderr, format, args);
va_end(args);
exit(1);
}
