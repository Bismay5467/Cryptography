#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ENCRYPT 0

void encrypt(char* sourceFile, char* destinationFile, char* key) {
    
    long sizeOfArray;

    char* asciiArray = readFile(sourceFile, &sizeOfArray); 
    char* encryptedArray = encryption(asciiArray, sizeOfArray, key);
    writeFile(encryptedArray, sizeOfArray, destinationFile, ENCRYPT);

    return;
}