#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ENCRYPT 0
#define DECRYPT 1

void writeFile(int* contentArray, long sizeOfArray, int mode, char* fileName) {

    FILE* filePtr;

    if(mode == ENCRYPT) {
        filePtr = fopen(fileName, "w");
    }
    else if(mode == DECRYPT) {
        filePtr = fopen(fileName, "w");
    }

    if(filePtr == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return;
    }
    
    for(long i = 0; i < sizeOfArray; i++) {
        if(fputc((char)contentArray[i], filePtr) != contentArray[i]) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return;
        } 
    }

    mode == DECRYPT ? fprintf(stderr, "\nData successfully decrypted\n") : fprintf(stderr, "\nData successfully encrypted\n");

    fclose(filePtr);

    return;
}