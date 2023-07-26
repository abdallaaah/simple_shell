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
#define flag 0
#define MAX_BUFFER_SIZE 1024
char **tokenize_buffer(char *buffer_line);
char *_strcpy(char *dest, const char *src);
void execute_me(char **tokens, char *dot, int num_tokens, char *buffer_line);
void sigint_handler(int sig);
#endif
