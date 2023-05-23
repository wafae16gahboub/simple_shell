#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define ARGUMENTS_SIZE 64
#define DELIMITER " \t\n\r\a"
#define PATH_DELIMITER ":"

extern char **environ;

void print_environment(void) {
    int i = 0;

    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
}

int main(void) {
    char buffer[BUFFER_SIZE];
    char *arguments[ARGUMENTS_SIZE];
    char *token;
    int i;
    pid_t pid;
    while (1) {
        printf("$ ");

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;
        }

         i = 0;
        token = strtok(buffer, DELIMITER);

        while (token != NULL) {
            arguments[i] = token;
            i++;
            token = strtok(NULL, DELIMITER);
        }

        arguments[i] = NULL;

        if (i == 0) {
            continue;
        }

        if (strcmp(arguments[0], "exit") == 0) {
            break;
        } else if (strcmp(arguments[0], "env") == 0) {
            print_environment();
            continue;
        }

         pid = fork();

        if (pid == 0) {
            execvp(arguments[0], arguments);
            fprintf(stderr, "%s: command not found\n", arguments[0]);
            exit(1);
        } else if (pid < 0) {
            perror("fork");
        } else {
            wait(NULL);
        }
    }

    return 0;
}

