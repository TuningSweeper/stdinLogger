/*
    stdinLogger

    Simple Windows tool that writes what comes in from the
    stdin to a log file.

    The log file name is  binaryName.stdinLog.txt

    Can be used for example to debug and reverse engineer
    programs that launch other binaries and hand out the
    configurations and settings through standard stream.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFERLEN 1024

int main(int argc, char *argv[])
{
    FILE * fp;
    char buffer[BUFFERLEN];

    if(strlen(argv[0]) > BUFFERLEN-24) return -1;

    strcpy(buffer, argv[0]);
    strcat(buffer, ".stdinLog.txt");

    fp = fopen(buffer, "w");

    while (fgets(buffer, BUFFERLEN, stdin)) {
        fprintf(fp, "%s", buffer);

        if (ferror(stdin)) break;
    }

    fclose(fp);
    return 0;
}