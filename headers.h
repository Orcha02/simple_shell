#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <libgen.h>

extern char **environ;
char *_getenv(const char *name);
char *findpath(char *command);

/*str_tools*/
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

/*free*/
void _free_parent(char *buffer, char **commands);
void _free_double_pointer(char **pointer);

/*tok_tools*/
unsigned int find_length(char *s);
char **s_tok(char *str);

/*_built-ins*/
void built_env(char **environ);

#endif /*HEADERS*/
