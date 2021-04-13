# simple_shell
This simple_shell project is about making a command interpreter as similar as possible to the original shell UNIX command interpreter
## Overview
This simple_shell version of ours acts as a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.
## Invocation
If no args are present and if the standard input of the shell is connected to a terminal the shell is considered an interactive shell.

An interactive shell generally prompts before each command and handles programming and command errors differently.

### Examples:
#### Interactive Mode:
     $ ./simple_shell
     $ /bin/pwd ||  $pwd
     Output: /home/vagrant/simple_shell
#### OR
     $ ./simple_shell
     $ /bin/ls  ||  $ls
     Output: AUTHORS _built-ins.c _findpath.c _free.c _getenv.c headers.h man_1_simple_shell README.md simple_shell.c str_tools.c tok_tools.c

#### Non-Interactive Mode:
     $ echo "/bin/pwd" | ./simple_shell    ||     echo "pwd" | ./simple_shell
     Output: /home/vagrant/simple_shell

# Composed by:
## PID & PPID
- A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process ID, you can use the system call getpid (man 2 getpid):

## Arguments
- The command line arguments are passed through the main function: int main(int ac, char **av);
&rarr; av is a NULL terminated array of strings
&rarr; ac is the number of items in av
- av[0] usually contains the name used to invoke the current program. av[1] is the first argument of the program, av[2] the second, and so on.

## Program Execution
- The system call execve allows a process to execute another program (man 2 execve). Note that this system call does load the new program into the current process memory in place of the previous program: on success execve does not return to continue the rest of the previous program.

## Process creation
- The system call fork (man 2 fork) creates a new child process, almost identical to the parent (the process that calls fork). Once fork successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.

## Wait
- The wait system call (man 2 wait) suspends execution of the calling process until one of its children terminates.

## File information
- The stat (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.

## Environment
- We have seen earlier that the shell uses an environment list, where environment variables are stored. The list is an array of strings, with the following format: var=value, where var is the name of the variable and value its value.
&rarr; As a reminder, you can list the environment with the command printenv

## Files and Descriptions
|  FILE  |  DESCRIPTION  |
| ------------- | ------------- |
| simple_shell.c | UNIX command line interpreter function |
| headers.h | Header file that contains our prototypes and include libraries |
| _built-ins.c  |  Contains function that executes the built-ins & function that prints the environment |
| _findpath.c | Function that finds the directory of the command |
| _free | Functions to free parent and double pointers |
|  _getenv | Function that gets environment variable |
| _printerror.c | Contains: error_printing, exec_error, print_string, print_number, _write |
| man_1_simple_shell | Our manual with documentation about how our simple_shell works |
| str_tools.c | Contains: _strlen, _strncmp, *str_concat, *_strdup |
| tok_tools.c |  Contains: find_length & **s_tok |