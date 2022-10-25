#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define ENCRYPT 0
#define DECRYPT 1

void writeFile(int* contentArray, long sizeOfArray, int mode, char* fileName) {

    FILE* filePtr;

    if(mode == ENCRYPT) {
        fprintf(stdout, "\nEncrypting data...\n");
        Sleep(1000);
        filePtr = fopen(fileName, "w");
    }
    else if(mode == DECRYPT) {
        fprintf(stdout, "\nDecrypting data...\n");
        Sleep(1000);
        filePtr = fopen(fileName, "w");
    }

    if(filePtr == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return;
    }
    
    for(long i = 0; i < sizeOfArray; i++) {
        fputc((char)contentArray[i], filePtr);
    }

    mode == DECRYPT ? fprintf(stdout, "\nData successfully decrypted\n") : fprintf(stdout, "\nData successfully encrypted\n");

    fclose(filePtr);

    return;
}