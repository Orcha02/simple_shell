#ifndef HEADERS_H
#define HEADERS_H

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


char *_getenv(const char *name);
char *findpath(char *command);

/*str_tools*/
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *str_concat(char *s1, char *s2);
char *_strdup(char *str);

#endif /*HEADERS*/
