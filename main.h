#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <wait.h>
#include <stddef.h>

void executeCommand(char *cmd);
void handle_arguments(char *cmd);
void handlePath(char *cmd);
void exitShell(void);
void myEnviron(char **envp);


#endif
