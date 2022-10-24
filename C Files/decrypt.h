#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ENCRYPT
    #include "D:\PROJECT_SEM1\cryptography\C Files\readFile.h"
    #include "D:\PROJECT_SEM1\cryptography\C Files\writeFile.h"
    #include "D:\PROJECT_SEM1\cryptography\C Files\helperFunction.h"
#endif

#define DECRYPT 1

int* arrayConversion(int* matrix, long dimension, long* sizeOfArray) {
    
    int flag = 0;
    long posI, posJ;

    for(long i = dimension-1; i >= 0; i--) {
        for(long j = dimension-1; j >= 0; j--) {
            if(matrix[i*dimension+j] == '^') {
                flag = 1;
                posJ = j;
                break;
            }
        }
        if(flag == 1) {
            posI = i;
            break;
        }
    }

    *sizeOfArray = (posI*dimension+posJ);
    
    int* asciiArray = (int*)malloc(sizeof(int)*(*sizeOfArray));
    if(asciiArray == NULL) {
        printf("\nCouldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    for(long i = posI, j = posJ, k = *sizeOfArray; i >= 0;) {
        asciiArray[k--] = matrix[i*dimension+j];
        j--;
        if(j == -1) {
            j = dimension-1;
            i--;
        }
    }

    return asciiArray;
}

int* reApplyKey(int* array, long sizeOfArray, char* key) {

    long lengthOfkey = strlen(key);
    
    for(long i = 0, j = 0; i < sizeOfArray; i++, j++) {
        array[i] = 256 - array[i] - key[j % lengthOfkey];
    }

    return array;
}

int* decryption(int* asciiArray, long *sizeOfArray, char* key, long* dimension) {

    *dimension = calculateDimensions(*sizeOfArray);

    int *decryptedArray = xorOperation(asciiArray, *dimension, key);
    decryptedArray = transpose(decryptedArray, *dimension);
    int* array = arrayConversion(decryptedArray, *dimension, sizeOfArray);
    array = reApplyKey(array, *sizeOfArray, key);

    free(decryptedArray);
    return array;
}

void decrypt(char* sourceFile, char* destinationFile, char* key) {
    
    long sizeOfArray;   
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray); 
    int* decryptedArray = decryption(asciiArray, &sizeOfArray, key, &dimension);    
    writeFile(decryptedArray, sizeOfArray, DECRYPT, destinationFile);

    free(asciiArray);
    free(decryptedArray);

    return;
}