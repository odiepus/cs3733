int z;

void frameFinder(int *physBits, int*pAddress, unsigned long*decimal){
    int t = 63;
    int w = 0;
    int cc = 0;
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    for(int s = 3; s >= 0; s--){
        int u = t - 3;
        z = 0;
        w = 0;
        for(; t >= u; t--){
            if(physBits[t] == 1){
                z += (int) pow(2, w);
                decimal += (int) pow(2, cc);
            }
            w++;
            cc++;
        }
        pAddress[s] = hex[z];
    }
    printf("\n");
    printf("Other  2Address %d: ", i);
    for(int l = 0; l < 64; l++){
        printf("%d", physBits[l]);
    }
    printf("\n");

}
