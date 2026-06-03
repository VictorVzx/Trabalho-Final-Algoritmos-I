// standard in out, printf, scanf e as demais funções essenciais
#include <stdio.h>

//unistd para o comando sleep
#include <unistd.h>

//prototipo de funções (interfaces)
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "interfaces/checarSO/checarSistemaInterface.h"
#include "interfaces/gerenciarAbelhas/gerencialAbelhasInterface.h"
#include "interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

//incluindo as funções (modulos)
#include "functions/limparTela/limparTela.h"
#include "functions/limparBuffer/limparBuffer.h"
#include "functions/gerenciarAbelhas/gerenciarAbelhas.h"

//prototipo das structs
#include "structs/structs.h"

// limite de abelhas e sensores 
#define MAX_ABELHAS 50
#define MAX_SENSORES 100

// função main (implementação do codigo principal)
int main(void){
    int sistema;
    showChecarSistema();
    scanf("%d", &sistema);
    limparBuffer();

    if(limparTela(sistema) == 0){
        printf("Sistema inválido.\n");
        return 1;
    }else if(limparTela(sistema) == 4 /*se a função retornar 4, sair do codigo*/){
        printf("Saindo...\n");
        sleep(1);
        return 0;
    }

    //variaveis de opção, para checar no do while
    int menuOption, abelhasOption, sensoresOption;

    do{
        //chamando a função de mostrar o menu
        interfaceMenuPrincipal();
        scanf("%d", &menuOption);
        limparBuffer();
        
        limparTela(sistema);

        switch (menuOption)
        {
        case 1:
            showGerenciarAbelhas();
            scanf("%d", &abelhasOption);
            limparBuffer();
            switch(abelhasOption){
                case 6:
                    
                case 11:
                    printf("Voltando...\n");
                    limparTela(sistema);
                    break;
                default:
                    printf("Opção invalida\n");
                    break;
            }
            break;
        case 2:
            showGerenciarSensores();
            scanf("%d", &sensoresOption);
            limparBuffer();
            break;
        case 3:
            printf("Sensores\n");
            limparTela(sistema);
            break;
        case 4:
            printf("Saindo...\n");
            limparTela(sistema);
            break;
        default:
            printf("Opção invalida.\n");
            limparTela(sistema);
            break;
        }
    }while(menuOption != 4);

    return 0;
}