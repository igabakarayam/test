#include <stdio.h>

int terbesar(int soal[],int ukuran){
    int paling = soal[ukuran];    
    if(ukuran==0){
        return paling;
    }
    printf("msauk");
    if(soal[ukuran]<soal[ukuran-1]){
        paling = soal[ukuran-1];
    }
    if(paling<terbesar(soal,ukuran-1)){
        paling = terbesar(soal, ukuran - 1);
    }
    return paling;
}


int main(){
    int soal[] = {4, 23, 5, 3, 100, 8, 9};
    int besararray=sizeof(soal)/sizeof(soal[0]);
    int jawaban = terbesar(soal, besararray);
    printf("%i", jawaban);
}