#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "D:\PROJECT_SEM1\cryptography\C Files\readFile.h"
#include "D:\PROJECT_SEM1\cryptography\C Files\writeFile.h"
#include "D:\PROJECT_SEM1\cryptography\C Files\helperFunction.h"

#define ENCRYPT 0

int *applyKey(int* asciiArray, long sizeOfArray, char* key){

    int lengthOfkey = strlen(key);

    for(int i = 0, j = 0; i < sizeOfArray; i++, j++) {
        asciiArray[i] = 256 - asciiArray[i] - key[j % lengthOfkey];
    }

    return asciiArray;
}

int *matrixConversion(int *encryptedArray, long sizeOfArray, long dimensions) {

    int *encryptedMatrix = mallocOrDie(dimensions);

    long i = 0L,k = 0L;

    while(k < sizeOfArray) {
        *(encryptedMatrix+i) = *(encryptedArray+k);
        i++, k++;
    }

    if(i < dimensions*dimensions) {

        encryptedMatrix[i++] = '^';
    }

    while(i < dimensions*dimensions) {
        encryptedMatrix[i++] = (rand() % 93);
    }

    return encryptedMatrix;
}

int* encryption(int* asciiArray, long sizeOfArray, char* key, long* dimension) {

    int *encryptedArray = applyKey(asciiArray, sizeOfArray, key);

    *dimension = calculateDimensions(sizeOfArray);

    int *encryptedMatrix = matrixConversion(encryptedArray, sizeOfArray, *dimension);

    encryptedMatrix = transpose(encryptedMatrix, *dimension);
    encryptedMatrix = xorOperation(encryptedMatrix, *dimension, key);

    return encryptedMatrix;
}

void encrypt(char* sourceFile, char* destinationFile, char* key) {

    long sizeOfArray;
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray);
    int* encryptedArray = encryption(asciiArray, sizeOfArray, key, &dimension);
    writeFile(encryptedArray, dimension*dimension, ENCRYPT, destinationFile);

    free(asciiArray);
    free(encryptedArray);

    return;
}