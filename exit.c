#include "main.h"
void exit_status(int status)
{
    free(buffer_line);
    buffer_line = NULL;
    exit(status);
}
