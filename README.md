#Simple Shell

This is a simple shell implementation that supports basic shell functionalities. The shell includes features such as executing commands, handling built-in commands (exit, env), and managing environment variables. Below is an overview of the key functions and features of the shell.

Table of Contents
Overview
Functions
Built-in Commands
Environment Variables
Compilation
Usage
Known Issues
Contributing

#Functions
int (*spec(char *s))(char **argv, char *buff, int status, int round_index)
This function is responsible for selecting the appropriate function based on the specified command. It uses an array of structs (specs) to map commands to their corresponding functions.

void check_comment(char *buff)
This function checks for comments in the input buffer (buff) and removes them by replacing the '#' character with '\0'.

int print_env(char **argv, char *buff, int status, int round_index)
Prints the environment variables to the standard output.

int _isdigit(int c)
Checks if a character is a digit.

int _atoi_exit(char *string, int round_index)
Converts a string to an integer and handles exit-related error cases.

void print_exit_error(char *string, int round_index)
Prints an error message for illegal exit numbers.

int main_exit(char **argv, char *buff, int status, int round_index)
Handles the built-in exit command, allowing the user to exit the shell.

void cmd_not_found(char *cmd, int round_index)
Prints an error message when a command is not found.

char **make_list(void)
Creates a list of directories from the PATH environment variable.

char *_getenv(const char *name)
Gets the value of an environment variable by name.

char *check_cmd(char *cmd, char **list)
Checks if a command is available in the provided list of directories.

int _puts(char *s, int i)
Prints a string to either standard output (i=1) or standard error (i=2).

int _putchar(int i)
Writes a character to standard output.

int _putchar_error(int i)
Writes a character to standard error.

void print_number(int n)
Prints an integer to standard output.

void print_number_error(int n)
Prints an integer to standard error.

int execute(char **argv, char **list, int round_index)
Executes a command with arguments. Handles command not found errors and fork failures.

int main(void)
The main function of the shell that repeatedly takes user input, processes it, and executes commands.

int _strcmp(char *s1, char *s2)
Compares two strings.

char *_strcpy(char *dest, char *src)
Copies a string from source to destination.

char *_strcat(char *dest, char *src)
Concatenates two strings.

int _strlen(char *s)
Calculates the length of a string.

#Built-in Commands
exit: Exits the shell.
env: Prints the environment variables.
Environment Variables
The shell supports environment variables, and the env command can be used to display them.

#Compilation
Compile the shell using a C compiler. For example:
gcc -Wall -Werror -pedantic -Wextra -o shell shell.c

#Usage
Run the compiled executable:
./shell
The shell will display a prompt where you can enter commands.

#Known Issues
Limited support for complex command structures.
...
#Contributing
Contributions are welcome! Please feel free to open issues or submit pull requests.
