#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include"pagetable.h"

int main() {

    FILE *fp;
    FILE *fp2;
    fp = fopen("part1sequence", "rb");
    fp2 = fopen("outputtestpart2", "wb");
    if(fp == NULL || fp2 == NULL){
        printf("error\n");
        exit(1);
    }

    unsigned long x;
    int bits[4096][64];
    int physBits[4096][64];
    unsigned char pAddress[4096][4];

    int i = 0;
    int z = 0;
    size_t v;
    while((v = fread(&x, sizeof(x), 1, fp)) > 0){
        for(int k = 63; k >= 0; k--){
            bits[i][k] = x&1;
            x>>=1;
            physBits[i][k] = bits[i][k];
        }

        printf("Logical Address %d: ", i);
        for(int l = 0; l < 64; l++){
            printf("%d", bits[i][l]);
        }

        printf("\n");
        printf("Other   Address %d: ", i);
        for(int l = 0; l < 64; l++){
            printf("%d", physBits[i][l]);
        }
        printf("\n");

        //pass the bits array to frameFinder in pagetable.c
        pageTable(&bits[i][0], &physBits[i][0]);

        unsigned long decimal = 0;
        frameFinder(&physBits[i][0], &pAddress[i][0], &decimal);


        printf("\nPhysical Address in hex: 0x");
        for(int l = 0; l < 4; l++){
            printf("%c", pAddress[i][l]);
        }
        fwrite(&decimal, sizeof(unsigned long), 1, fp2);
        i += (int) v;
        printf("\n\n");
    }
    return 0;
}
