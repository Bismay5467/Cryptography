#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <errno.h>
#include<unistd.h>


#define ENCRYPT 0
#define DECRYPT 1

void writeFile(int* contentArray, long sizeOfArray, int mode, char* fileName) {

    FILE* filePtr;

    if(mode == ENCRYPT) {
        fprintf(stdout, "\nEncrypting data...\n");
        sleep(1);
        filePtr = fopen(fileName, "wb");
    }
    else if(mode == DECRYPT) {
        fprintf(stdout, "\nDecrypting data...\n");
        sleep(1);
        filePtr = fopen(fileName, "wb");
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