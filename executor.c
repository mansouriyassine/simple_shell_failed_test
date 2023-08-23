#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int execute_command(info_t *info)
{
pid_t pid;
int status;

pid = fork();
if (pid == 0)
{
if (execvp(info->args[0], info->args) == -1)
{
perror("simple_shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("simple_shell");
}
else
{
waitpid(pid, &status, WUNTRACED);
}

return (1);
}
