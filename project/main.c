#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printbit(unsigned long long sum, int size) {
    unsigned long long bit;
    for(bit = pow(2, pow(size, 2) - 1); bit != 0; bit >>= 1) {
        if(sum & bit) printf("1");
        else printf("0");
    }
}

int main() {
    //variables
    int **x, size = 8;
    unsigned long long sum = 0, aux = 0;

    // memory alocation
    x    = malloc(size * sizeof(int*));
    x[0] = malloc(size * size * sizeof(int));

    // memory spaces
    for(int i = 1; i < size; i++) x[i] = x[i - 1] + size;

    srand(time(NULL));
    // rand array elements
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) x[i][j] = rand()%2;
    }

    // output bits sequency
    printf("Bits sequency:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) printf("%d", x[i][j]);
    }

    // bits sum
    for(int i = size - 1; i >= 0; i--) {
        for(int j = size - 1; j >= 0; j--) {
            if(x[i][j] == 1) sum += (unsigned long long)pow(2, aux);
            aux += 1;
        }
    }

    // output of a 64-bit unsigned integer
    printf("\n\nDecimal values of bits:\n%llu\n", sum);

    // return from decimal to bits form
    printf("\nBits from decimal value: \n");
    printbit(sum, size);
    printf("\n");

    // deleting memory alocation
    free(x[0]);
    free(x);

    return 0;
}
