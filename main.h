#ifndef MIAN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
extern char *buffer_line;
#define MAX_BUFFER_SIZE 1024
char **tokenize_buffer(char *buffer_line);
char *_strcpy(char *dest, const char *src);
int execute_me(char **tokens, char *dot, int num_tokens, char *buffer_line);
void free_tokens(char **tokens, int num_tokens);
int _strcmp(const char *string1, const char *string2);
void write_env();
char *_strtok(char *str, const char *delim, char **last);
void exit_status(int status);

#endif
