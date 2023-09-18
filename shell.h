#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* environment */
extern char **environ;
/* global name */
char *name;
/* history counter */
int hist;

/**
 * struct list_s - a linked list.
 * @dir: A dir path.
 * @next: A pointer to another list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - built-in commands struct
 * @name: builin command name
 * @f: A function pointer to command's buitlin function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - aliases struct
 * @name: the alias var name
 * @value: alias value
 * @next:  pointer to next.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases */
alias_t *aliases;

/** env helpers **/
char **_getenv(const char *var);
void free_env(void);
char **_copyenv(void);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);


/** path locator **/
list_t *get_path_dir(char *path);
char *fill_path_dir(char *path);
char *get_location(char *cmd);

/** tokens and line handlers **/
int token_len(char *str, char *del);
int token_tot(char *str, char *del);
char **_strtok(char *line, char *del);

ssize_t _getline(char **lineptr, size_t *nb, FILE *stream);
void assign_lineptr(char **lineptr, size_t *ns, char *buff, size_t nb);
void *_realloc(void *ptnr, unsigned int old_sb, unsigned int new_sb);

/** string handlers **/
char *_strncat(char *dest, const char *src, size_t nb);
int _strlen(const char *st);
char *_strcat(char *fn, const char *src);
char *_strcpy(char *fn, const char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *sf, const char *s2, size_t nb);
int _strspn(char *s, char *accept);
char *_strchr(char *st, char c);

/** alaiseses **/
void print_alias(alias_t *alias);
char **replace_aliases(char **args);
void set_alias(char *var_name, char *value);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);

/** builtins.c **/
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);

/** like man pages **/
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);

/** error handlers **/
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);
int num_len(int num);
char *_itoa(int num);
int create_error(char **args, int err);

/** file handlers **/
int cant_open(char *file_path);
int proc_file_commands(char *file_path, int *exe_ret);


