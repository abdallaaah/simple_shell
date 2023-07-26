#include "main.h"
void write_env()
{
char **env;
for (env = environ; *env != NULL; env++)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
}
}
