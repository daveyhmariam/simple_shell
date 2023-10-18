#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

extern char **environ;

int _strcmp(char *str1, char *str2);
int checkPath(char **arguments);
char *_strdup(char *str);
char *conc(char *dir_path, char *command);
int _exec(char **arguments);
int getArgs(char *entry, char **arguments);
int printNums(int n);
int _strlen(const char *string);
int _perror(char **arguments, int counter);
char *_getenv(char *global_var);
int prompt(const char *prompt, unsigned int size);
int _putchar(char c);
int isFile(char *pathname);
void freeVect(char **grid, int heigth);
void fFree(char *entry);
int checkBltin(char **arguments, int exit_stat);

#endif

