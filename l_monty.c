#include "l_monty.h"

char *tokens[2];
int line_num;

int main(int argc, char *argv[])
{
    FILE *file;
    char line[50];
    char *tokens[2];

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
}

