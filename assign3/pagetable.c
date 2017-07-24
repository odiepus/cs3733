#include <stdio.h>
#include<stdlib.h>
#include <math.h>



int table[7] = {2, 4, 1, 7, 3, 5, 6};



void pageTable(int *bit, int *physBits){

    int d = 0;
    int p = 0;
    int m = 0;
    for(int o = 56; o >=52; o--){
        if(bit[o] == 1){
            p += (int) pow(2, m);
        }
        m++;
    }

    int q = 0;
    for(int o = 63; o >=57; o--){
        if(bit[o] == 1){
            d += (int) pow(2, q);
        }
        q++;
    }
    int shiftBit = table[p];
    for(int r = 56; r >= 53; r--){
        physBits[r] = shiftBit&1;
        shiftBit>>=1;
    }

    printf("page table index: %d\n", p);
    printf("frame #: %d\n", table[p]);
    printf("frame offset: %d", d);


    printf("\nPhysical  Address: ");
    for(int l = 0; l < 64; l++){
        int output = physBits[l];
        printf("%d", output);
    }
}
