#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"
#include <stddef.h>

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
	int isInteractive;

	isInteractive = isatty(fileno(stdin));

	if (isInteractive)
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	while ((input_size = getline(&cmd, &buff, stdin)) != -1)
	{

		if (input_size > 0 && cmd[input_size - 1] == '\n')
		{
			cmd[input_size - 1] = '\0';
			input_size--;
		}
		if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0)
			break;

		executeCommand(cmd);
		handlePath(cmd);
		
		if (isInteractive)
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	}

	free(cmd);
	return (0);
}
