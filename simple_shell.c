#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"
#include <fcntl.h>
/**
 * main - main entry point
 *
 * Return: always 0
 */

int main(void)
{
	char *cmd = NULL;
	const char prompt[] = "$ ";
	int isInteractive;
	ssize_t bytesRead;
	int fd;

	isInteractive = isatty(fileno(stdin));

	if (isInteractive)
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

	while ((bytesRead = read(STDIN_FILENO, cmd, sizeof(cmd))) > 0)
	{
		if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0)
			break;

		executeCommand(cmd);

		if (isInteractive)
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	}

	write(STDOUT_FILENO, "\n", 1);

	fd = open("test_ls_2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		write(fd, "/bin/ls\n", strlen("/bin/ls\n"));
		write(fd, "/bin/ls\n", strlen("/bin/ls\n"));
		close(fd);
	}

	return (0);
}
