#include "main.h"

int flag = 0;

void sigint_handler(int sig)
{
(void)sig;
    flag = 1;
    write(STDOUT_FILENO, "\n", 1);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    char *buffer_line = NULL;
    size_t buffer_len = 0;
    char **tokens = NULL;
    char *prompt = "#cisfun$ ";
    ssize_t num;
    int i, num_tokens;
    (void)argc, (void)argv;

    signal(SIGINT, sigint_handler);

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, prompt, strlen(prompt));

        num = getline(&buffer_line, &buffer_len, stdin);

        if (num == -1) {
            if (flag == 1) {
               
            } else {
                perror("Error in getline()");
            }
            break;
        }

        tokens = tokenize_buffer(buffer_line);
        num_tokens = 0;
        while (tokens[num_tokens] != NULL)
            num_tokens++;

        execute_me(tokens, argv[0], num_tokens, buffer_line);

        for (i = 0; i < num_tokens; i++)
        {
            free(tokens[i]);
        }
        free(tokens);
    }

    free(buffer_line);
    buffer_line = NULL;
    tokens = NULL;

    return (0);
}
