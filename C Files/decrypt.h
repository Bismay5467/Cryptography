#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ENCRYPT
    #include "D:\PROJECT_SEM1\cryptography\C Files\readFile.h"
    #include "D:\PROJECT_SEM1\cryptography\C Files\writeFile.h"
    #include "D:\PROJECT_SEM1\cryptography\C Files\helperFunction.h"
#endif

#define DECRYPT 1

int* decryption(int* asciiArray, long sizeOfArray, char* key, long* dimension) {

    *dimension = calculateDimensions(sizeOfArray);

    int *decryptedArray = xorOperation(asciiArray, *dimension, key);
    decryptedArray = transpose(decryptedArray, (int)dimension);
    for(long i = 0; i < *dimension; i++){
        for(long j = 0; j < *dimension; j++){
            printf("|%d||%c|\t", decryptedArray[i*(*dimension) + j],decryptedArray[i*(*dimension) + j]);
        }
        printf("\n");
    }

    return NULL;
}

void decrypt(char* sourceFile, char* destinationFile, char* key) {
    
    long sizeOfArray;   
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray); 
    int* decryptedArray = decryption(asciiArray, sizeOfArray, key, &dimension);


    
    // writeFile(asciiArray, sizeOfArray, DECRYPT, destinationFile);

    free(asciiArray);
    free(decryptedArray);

    return;
}