#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

extern char **environ;
int wc(char *string, const char *delim);
char **tokenizer(char *string, const char *delim);
char **_getenv(char *env);
int characters(char *str);
char **envtokenizer(char *name);
void terminated(char *str, char *str1);
int execute(char *str, char **argv);
char *_which(char **tknstring);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
void free_array(char **string);
int env(char *str, char *str1);
#endif
