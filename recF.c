#include<stdio.h>
#include<math.h>

int recF(int n){
    if(n <= 2){
        return n;
    }
    else{
        int b = floor(n/2);
        int a = recF(b);
        return a;
    }
}
int main(int argc, char* argv[]){
    char k = gets();

    int x = recF((int)k);

    printf("%d\n", x);
    return 0;
}
