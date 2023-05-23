#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

char *create_full_path(const char *dir, const char *cmd)
{
	int dir_length = strlen(dir);
	int cmd_length = strlen(cmd);

	char *full_path = malloc(dir_length + cmd_length + 2);

	if (full_path == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	memcpy(full_path, dir, dir_length);
	full_path[dir_length] = '/';
	memcpy(full_path + dir_length + 1, cmd, cmd_length);
	full_path[dir_length + cmd_length + 1] = '\0';

	return (full_path);
}

char *get_path(const char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path = NULL;

	while (token != NULL)
	{
		full_path = create_full_path(token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
