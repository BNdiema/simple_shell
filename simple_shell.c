#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"
#include <fcntl.h>
#include <stddef.h>

#define BUFFER_SIZE 1024


/**
 * main - main entry point
 *
 * Return: always 0
 */

int main(void)
{
	char cmd[BUFFER_SIZE];
	const char prompt[] = "$ ";
	int isInteractive;
	ssize_t bytesRead;

	isInteractive = isatty(fileno(stdin));

	if (isInteractive)
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	else
	{
		bytesRead = read(STDIN_FILENO, cmd, sizeof(cmd));
		if (bytesRead <= 0)
			return (0);
		cmd[bytesRead - 1] = '\0';
		executeCommand(cmd);
		return (0);
	}

	while ((bytesRead = read(STDIN_FILENO, cmd, sizeof(cmd))) > 0)
	{
		cmd[bytesRead - 1] = '\0';

		if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0)
			break;
		executeCommand(cmd);
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	}
	return (0);
}
