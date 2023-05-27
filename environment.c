#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * myEnviron - print current ennvironment
 * Return: 0
 */

void myEnviron(char **envp)
{
	char **env = envp;

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
