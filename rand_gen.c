#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE*file=fopen("test_rand.txt","w");
    for(int i=0;i<1000000;i++){
        fprintf(file,"str%d\t%d\n",1+rand()%100000000,1+rand()%100000000);
    }
    fclose(file);
    return 0;
}