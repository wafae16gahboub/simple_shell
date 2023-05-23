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
#define MAX_ARGS 256

char **split_path(char *ptr);
char *detect_find(char *grid, char **dest);
void ecut_com(char *comme_pathe, char **argc, char *argv[]);
extern char **environ;
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif
