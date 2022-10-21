#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DECRYPT 1

void decrypt(char* sourceFile, char* destinationFile, char* key) {
    
    long sizeOfArray;

    char* asciiArray = readFile(sourceFile, &sizeOfArray); 
    char* decryptedArray = decryption(asciiArray, sizeOfArray, key);
    writeFile(decryptedArray, sizeOfArray, destinationFile, DECRYPT);

    return;
}