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

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file <file>\n");
        exit(EXIT_FAILURE);
    }
    

    while((fgets(line, sizeof(line), file)) != NULL)
    {
        if (parse_line(line) == -1)
        {
            exit(EXIT_FAILURE);
        }

    }
    exit(EXIT_SUCCESS);
}

