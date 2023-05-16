#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 10

char **get_path_directories(char *path);
char *check_path(char *command, char **directories);
void excut_cmd(char* command_path, char** args, char* argv[]);

#endif
