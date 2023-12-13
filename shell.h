#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
/**
 * struct sepcifiers - to select specifier with the appropriate func
 * @sp: specifier
 * @f: pointer to according func
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 */
typedef struct sepcifiers
{
	char *sp;
	int (*f)(char **argv, char *buff, int status, int round_index);
} specs;
/**
 * struct list_dir - singly linked list
 * @dirname: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * Authors: MahmoudMetwalli && AhMeDMaGDY28
 */
typedef struct list_dir
{
	char *dirname;
	struct list_dir *next;
} list_t;
void check_comment(char *buff);
void print_number(int n);
void print_number_error(int n);
int execute(char **argv, char **list, int round_index);
int (*spec(char *s))(char **argv, char *buff, int status, int round_index);
int main_exit(char **argv, char *buff, int status, int round_index);
void print_exit_error(char *string, int round_index);
int _isdigit(int c);
int _atoi_exit(char *string, int round_index);
int _puts(char *s, int i);
int _putchar(int i);
int _putchar_error(int i);
void cmd_not_found(char *cmd, int round_index);
int _strcmp(char *s1, char *s2);
list_t *add_node_end(list_t **head, char *str);
char *_getenv(const char *name);
char **make_list(void);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *check_cmd(char *cmd, char **list);
int print_env(char **argv, char *buff, int status, int round_index);
void free_list(list_t *head);
#endif
