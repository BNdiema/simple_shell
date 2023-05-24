#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - main entry point
 *
 * Return: always 0
 */

int main(void)
{
	char *cmd = NULL;
	const char prompt[] = "$ ";
	size_t buff = 10;
	ssize_t input_size;
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1), input_size
			= getline(&cmd, &buff, stdin);

		if (input_size > 0 && cmd[input_size - 1] == '\n')
		{
			cmd[input_size - 1] = '\0';
			input_size--;
		}
		if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0)
			break;

		pid = fork();


		if (pid == -1)
		{
			perror("Forking faild");
			exit(1);
		}
		else
			wait(NULL);
	}
	free(cmd);

	return (0);
}
