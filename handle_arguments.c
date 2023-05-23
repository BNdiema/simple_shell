#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

char *get_command_path(char *cmd);

void handle_arguments(char *cmd)
{
	char *command_path = get_command_path(cmd);
	
	if(command_path == NULL)
	{
		printf("Command not found: %s\n", cmd);
		return;
	}
	
	char *argv[] = {command_path, cmd, NULL};
  char *envp[] = {NULL};
  execve(command_path, argv, envp);
  
  perror("Command execution failed");
  free(command_path);
  exit(1);
}
