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
    int bias = 127;

    for(int i = 0, j = 0; i < sizeOfArray; i++, j++) {
        asciiArray[i] = 256 - asciiArray[i] - key[j % lengthOfkey] - bias;
    }

    return asciiArray;
}

int *matrixConversion(int *encryptedArray, long sizeOfArray, long dimensions) {

    int *matrix = mallocOrDie(dimensions);

    // printf("\n%p\n", encryptedMatrix);

    // if(encryptedMatrix == NULL) {
    //     printf("\nCouldn't allocate memory for matrix conversion\n");
    //     exit(EXIT_FAILURE);
    // }

    // long i,k;
    
    // for(i = 0, k = 0; i < dimensions*dimensions; i++) {
    //     *(encryptedMatrix+i) = *(encryptedArray+k);
    //     k++;
    //     if(k == sizeOfArray) {
    //         break;
    //     }
    // }

    // if(i < dimensions*dimensions) {
    //     encryptedMatrix[i++] = '^';
    // }

    // while(i < dimensions*dimensions) {
    //     encryptedMatrix[i++] = (rand() % 93);
    // }

    for(int ii = 0; ii < dimensions; ii++) {
        for(int jj = 0; jj < dimensions; jj++) {
            printf("\nhere\n");
        }
        printf("\n");
    }
    

    // return encryptedMatrix;
    return NULL;
}

int* encryption(int* asciiArray, long sizeOfArray, char* key, long* dimension) {    

    int *encryptedArray = applyKey(asciiArray, sizeOfArray, key);

    *dimension = calculateDimensions(sizeOfArray);

    int *encryptedMatrix = matrixConversion(encryptedArray, sizeOfArray, *dimension);

    



    // for(int i = 0; i < sizeOfArray; i++) {
    //     printf("|%d| |%c|\t", encryptedArray[i], encryptedArray[i] );
    // }

    
    
    
    // encryptedMatrix = transpose(encryptedMatrix, dimensions);
    // encryptedMatrix = xorOperation(encryptedMatrix, dimensions, key);

    // return encryptedMatrix;
    return NULL;
}

void encrypt(char* sourceFile, char* destinationFile, char* key) {
    
    long sizeOfArray;
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray); 
    int* encryptedArray = encryption(asciiArray, sizeOfArray, key, &dimension);
    //writeFile(encryptedArray, sizeOfArray, ENCRYPT, destinationFile);

    free(asciiArray);
    free(encryptedArray);

    return;
}