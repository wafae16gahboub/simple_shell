#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX_WORDS 100
extern char **environ;

int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
void set_arr_to_zeros(unsigned int *arr, size_t size);
bool is_delimiter(char c, char *delims);
char *_getenv(char *name);
void free_vector(char **vector, size_t len);
void exit_handler(char **args, size_t nbr_of_args);
void execute_cmd(char **args, size_t nbr_of_args);
int count_words(char *str, char *separats, unsigned int *arr);
bool does_file_exist(char *path, struct stat *buffer_status);
void env_handler(char **args, size_t nbr_of_args);
char *find_file_in_path(char *filename, struct stat *statbuf);
int _atoi(char *s);
bool builtin_handler(char **args, size_t nbr_of_args, char **buffer);
char **str_split_arr(char *str, char *separators, size_t *word_count);
char *concatStrings(const char *str1, const char *str2, const char *str3);
void read_input(char **buffer, size_t *buffer_size, bool *is_from_pipe);

#endif
