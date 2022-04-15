#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MISSING_ARG 1

int
main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Sorry, you must enter text as arg... \"./AnnoyingMarkdown TEXT_HERE\"");
        exit(MISSING_ARG);
    }

    //VARIABLES
    int outputSize = strlen(argv[1]) * 5; //SIZE CALCULATION ≈ 5x
    int textNumberBuffer = 2; //THIS IS FOR COUNTING POSITIONS OF '||'
    int indexNumberBuffer = 0; //THIS IS FOR GETTING TEXT FROM ARG
    char *output = malloc(outputSize);

    //LOAD output
    for (int i = 0; i < outputSize; i++)
    {
        loopStart:

        if (i < textNumberBuffer) //SPACE FOR '|'
        {
            output[i] = '|';
            continue;
        }

        if (i == textNumberBuffer) //SPACE FOR TEXT
        {
            output[i] = argv[1][indexNumberBuffer];
            indexNumberBuffer++;
            continue;
        }

        if (i > textNumberBuffer) //OUT OF BUFFER
        {
            textNumberBuffer += 5;
            goto loopStart;
        }
    }

    printf("%s\n", output); //PRINT OUT OUTPUT
    
    return 0;
}