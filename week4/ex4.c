#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

char **parsed_line(char* line)
{
    char *command = strtok(line, " ");
    char **commands = malloc(sizeof(char *));
    int size = 1;
    while (command && command[0] != '\n')
    {
        commands[size - 1] = command;
        size++;
        command = strtok(NULL, " ");
        commands = realloc(commands, sizeof(char *) * size);
    }

    if (commands[size - 2][strlen(commands[size - 2]) - 1] == '\n')
    {
        commands[size - 2][strlen(commands[size - 2]) - 1] = '\0';
    }
    commands[size] = NULL;
    return commands;
}

int main()
{
    while(1) 
    {
        printf(">");
        char *line = NULL;
        size_t n = 0;
        getline(&line, &n, stdin);
        char **argv = parsed_line(line);

        int pid = fork();
        if (pid == 0) 
        {
            execvp(argv[0], argv);
            return 0;
        }
        else waitpid(pid, NULL, 0);
    }
}