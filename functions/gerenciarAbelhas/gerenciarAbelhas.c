#include <stdio.h>
#include <string.h>
#include "gerenciarAbelhas.h"

#include "../../structs/structs.h"

void cadastrarAbelha(Abelha a[]){

    for(int i = 0; i < 50; i++){
        printf("Digite o nome popular da abelha: ");
        fgets(a[i].nomePopular, sizeof(a[i].nomePopular), stdin);
    }

    for(int i = 0; i < 50; i++){
        printf("Digite o nome cientifico: ");
        fgets(a[i].nomeCientifico, sizeof(a[i].nomeCientifico), stdin);
    }
}

void listarTodas(Abelha a[], int quantidade){

}