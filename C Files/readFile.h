#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <errno.h>

int* readFile(char* fileName, long* fileSize) {
    FILE *filePtr = fopen(fileName, "rb");
    
    if(filePtr == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fseek(filePtr, 0, SEEK_END);
    long size = ftell(filePtr);
    *fileSize = size;
    rewind(filePtr);

    int* asciiArray = (int*)malloc(sizeof(int)*size);
    if(asciiArray == NULL) {
        fprintf(stderr, "Couldn't allocate memory for ascii array");
        *fileSize = 0;
        exit(EXIT_FAILURE);
    }

    long i = 0;

    while(!feof(filePtr)) {
        
        if(ferror(filePtr)) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            *fileSize = 0;
            exit(EXIT_FAILURE);
        }

        asciiArray[i++] = fgetc(filePtr);
    }

    fclose(filePtr);

    return asciiArray;
}