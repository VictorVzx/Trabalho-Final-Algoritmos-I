#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "limparTela.h"

int limparTela(int sys){
    // se for windows = cls
    if(sys == 1){
        printf("Limpando");
        for(int i = 0; i < 3; i++){
            printf(".");
        }
        printf("\n");
        sleep(1);
        system("cls");
    }
    // se for linux ou mac = clear
    else if (sys == 2 || sys == 3){
        printf("Limpando");
        for(int i = 0; i < 3; i++){
            printf(".");
        }
        printf("\n");
        sleep(1);
        system("clear");
    }
    // nenhum dos três: função retorna 0 (false)
    else{
        return 0;
    }
    // função retorna 1 (true) se for um sistema valido
    return 1;
}