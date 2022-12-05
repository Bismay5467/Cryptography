#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "readFile.h"
#include "writeFile.h"
#include "helperFunction.h"

#define ENCRYPT 0

int *applyKey1(int* asciiArray, long sizeOfArray, char* key){

    int lengthOfkey = strlen(key);

    for(int i = 0, j = 0; i < sizeOfArray; i++, j++) {
        asciiArray[i] = 256 - asciiArray[i] - key[j % lengthOfkey];
    }

    return asciiArray;
}

int *applyKey2(int* asciiArray, long sizeOfArray, char* key){
    int lengthOfkey = strlen(key);
    
}

int *matrixConversion(int *encryptedArray, long sizeOfArray, long dimensions) {

    int *encryptedMatrix = mallocOrDie((dimensions)*(dimensions));

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

int* encryption(int* asciiArray, long sizeOfArray, char* key, long* dimension, char* choice) {

    int *encryptedArray;
    
    if(*choice == '1')
        encryptedArray = applyKey1(asciiArray, sizeOfArray, key);
    else if(*choice == '2')
        encryptedArray = applyKey2(asciiArray, sizeOfArray, key);
    else{
        printf("INVALID CHOICE!\n");
        exit(EXIT_FAILURE);
    }

    *dimension = calculateDimensions(sizeOfArray);

    int *encryptedMatrix = matrixConversion(encryptedArray, sizeOfArray, *dimension);

    encryptedMatrix = transpose(encryptedMatrix, *dimension);

    encryptedMatrix = xorOperation(encryptedMatrix, *dimension, key);

    return encryptedMatrix;
}

void encrypt(char* sourceFile, char* destinationFile, char* choice,  char* key) {

    long sizeOfArray;
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray);
    int* encryptedArray = encryption(asciiArray, sizeOfArray, key, &dimension, choice);
    writeFile(encryptedArray, dimension*dimension, ENCRYPT, destinationFile);

    free(asciiArray);
    free(encryptedArray);

    return;
}