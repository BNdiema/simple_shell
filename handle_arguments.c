#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * grt_command_path - gets the path of files or folders
 * @cmd: command passed the requre path handling
 * Return: the path requred
 */

char *get_command_path(char *cmd);
{
	char *command_path = get_command_path(cmd);
	char *argv[];
	char *envp[];

	if (command_path == NULL)
	{
		printf("Command not found: %s\n", cmd);
		return;
	}

	argv[] = {command_path, cmd, NULL};
	envp[] = {NULL};

	execve(command_path, argv, envp);

	perror("Command execution failed");
	free(command_path);
	exit(1);
}
