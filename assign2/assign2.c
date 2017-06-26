#include <stdio.h>
#include "pslibrary.h"

int main(int argc, char *argv[])
{
    int arraySize = 0;


    if(!(argc == 8)){
        printf("Usage: %s <param1> <param2> ... <param7>\nThe seven parameters must be integers\n", argv[0]);
        return -1;
    }

    printf("Assignment 1 program written by Hector Herrera\n");

    printf("inputs: ");

    int i = 1;
    for(; i < argc; i++){
        printf("%c ", *argv[i]);
        if(i > 1){
            arraySize += *argv[i] - 48;
        }
    }
    int value[arraySize];
    for(i = 2; i < argc; i++){
        value[i-2] = *argv[i] - 48;
    }

    char str1[arraySize];
    char str2[arraySize];

    //part0(str1, str2);
//    proto(str1, str2, 0, value[0], value[1], value[2], value[3], value[4], value[5]);
//    display("FCFS\n", str1, str2);

//    sjf(str1, str2, value[0], value[1], value[2], value[3], value[4], value[5]);
//    display("SJF\n", str1, str2);

    psjf(str1, str2, value[0], value[1], value[2], value[3], value[4], value[5]);
    display("PSJF\n", str1, str2);


    return 0;
}
