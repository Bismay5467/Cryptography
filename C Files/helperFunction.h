#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int* mallocOrDie(long size) {

    int* memAlloc = (int *)malloc(sizeof(int)*size*size);

    printf("\n%d\n", size);

    if(memAlloc==NULL) {
        printf("\nCouldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    return memAlloc;
}

long calculateDimensions(long sizeOfArray) {
    long dimensions = (long)ceil(sqrt(sizeOfArray));
    return dimensions;
}

int* transpose(int* Matrix, long dimensions) {

    int *transposeMatrix = mallocOrDie(dimensions);

    for(long i = 0; i < dimensions; i++) {
        for(long j = 0; j < dimensions; j++) {
            transposeMatrix[j*dimensions + i] = Matrix[i*dimensions + j];
        }
    }

    return transposeMatrix;
}

int* xorOperation(int* Matrix, long dimensions, char* key) {

    for(long i = 0, k = 0; i < dimensions; i++) {
        for(long j = 0; j < dimensions; j++) {
            Matrix[i*dimensions + j] ^= key[k % strlen(key)];
            k++;
        }
    }

    return Matrix;

}