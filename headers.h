#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_getenv(const char *name);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);

#endif /*HEADERS*/
