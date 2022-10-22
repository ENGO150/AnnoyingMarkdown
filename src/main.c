#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MISSING_ARG 1
#define SUCCESS 0
#define MAX_GET 512

int main(int argc, char **argv)
{
    char *completeArgs = malloc(MAX_GET + 1);

    //MISSING ARGS
    if (argc < 2)
    {
        /*printf("Sorry, you must enter text as args... \"./AnnoyingMarkdown TEXT HERE\"\n");
        return MISSING_ARG;*/

        printf("Please enter text:\n>>> ");

        fgets(completeArgs, MAX_GET, stdin);
        completeArgs[strlen(completeArgs) - 1] = '\0';

        printf("\n");
    } else
    {
        int completeArgsLength = 0;

        //COUNT completeArgsLength
        for (int i = 1; i < argc; i++)
        {
            if (i != 1) completeArgsLength++; //ONE FOR SPACE

            completeArgsLength += strlen(argv[i]);
        }

        completeArgs = realloc(completeArgs, completeArgsLength);

        //LOAD completeArgs
        for (int i = 1; i < argc; i++)
        {
            if (i != 1) strcat(completeArgs, " "); //SPACE

            strcat(completeArgs, argv[i]);
        }
    }

    //VARIABLES
    int outputSize = strlen(completeArgs) * 5; //SIZE CALCULATION ≈ 5x
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
            //if (completeArgs[indexNumberBuffer] == '_') completeArgs[indexNumberBuffer] = ' ';

            output[i] = completeArgs[indexNumberBuffer];
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

    //DEALLOCATION
    free(completeArgs);
    free(output);

    return SUCCESS;
}
