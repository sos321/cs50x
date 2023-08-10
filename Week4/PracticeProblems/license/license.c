#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLATESAMMOUNT 8

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {
        printf("Could not open file!\n");
        return 2;
    }

    // Create array to store plate numbers
    char *plates[PLATESAMMOUNT];

    for (int i = 0; i < PLATESAMMOUNT; i++) {
        char* buffer = calloc(7, sizeof(char));
        fread(buffer, 7, 1, infile);

        buffer[6] = '\0';

        plates[i] = buffer;

        free(buffer);
    }

    // Print to console
    for (int i = 0; i < PLATESAMMOUNT; i++)
    {
        printf("%s\n", plates[i]);
    }

    fclose(infile);

    return 0;
}
