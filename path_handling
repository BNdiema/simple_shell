#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <sys/wait.h>

/**
 * handlePath - creates the path requred
 * @cmd: commands passed
 * Return: the path request
 */

void handlePath(char *cmd)
{
	char *path = getenv("PATH");
	char *token;
	char cmmd[100];
	int exists = 0;
	size_t path_len;
	size_t cmd_len;
	char *args[3];

	token = strtok(path, ":");
	while (token != NULL)
	{
		path_len = strlen(token);
		cmd_len = strlen(cmmd);

		if (path_len + 1 + cmd_len < sizeof(cmmd))
		{
			memcpy(cmmd, token, path_len);
			cmd[path_len] = '/';
			memcpy(cmmd + path_len + 1, cmd, cmd_len);
			cmd[path_len + 1 + cmd_len] = '\0';

			if (access(cmmd, X_OK) == 0)
			{
				exists = 1;
				break;
			}
		}
		token = strtok(NULL, ":");
	}
	if (!exists)
	{
		write(STDOUT_FILENO, "Command not found\n", 18);
		return;
	}
	args[0] = cmmd;
	args[1] = cmd;
	args[2] = NULL;
	execve(cmmd, args, NULL);
	write(STDOUT_FILENO, "Command execution failed\n", 24);
	exit(1);
}
