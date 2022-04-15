#include <stdio.h>

#define MISSING_ARG 1

int
main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Sorry, you must enter text as arg... \"./AnnoyingMarkdown TEXT_HERE\"");
        exit(MISSING_ARG);
    }

    return 0;
}