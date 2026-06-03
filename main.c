// standard in out, printf, scanf e as demais funções essenciais
#include <stdio.h>

// para chamar funções do sistema 
#include <stdlib.h>

//unistd para o comando sleep
#include <unistd.h>

//prototipo de funções (interfaces)
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "interfaces/checarSO/checarSistemaInterface.h"
#include "interfaces/gerenciarAbelhas/gerencialAbelhasInterface.h"
#include "interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

//prototipo de funções (modulos)
#include "functions/limparTela/limparTela.h"
#include "functions/limparBuffer/limparBuffer.h"
#include "functions/gerenciarAbelhas/gerenciarAbelhas.h"

//prototipo de structs
#include "structs/structs.h"

// limite de abelhas e sensores 
#define MAX_ABELHAS 50
#define MAX_SENSORES 100

// função main (implementação do codigo principal)
int main(void){
    Abelha abelhas[MAX_ABELHAS];

    int sistema;
    showChecarSistema();
    scanf("%d", &sistema);
    limparBuffer();

    if(sistema == 4){
        sleep(1);
        return 0;
    }

    if(limparTela(sistema) == 0){
        printf("Sistema inválido.\n");
        return 1;
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
                    limparTela(sistema);
                    //chama a função de cadastrar abelhas passando como parametro o sistema para chamar a função "limparTela()", que recebe como parametro o numero do sistema operacional
                    cadastrarAbelha(abelhas, sistema);
                    printf("Aguarde...");
                    limparTela(sistema);
                    break;
                case 11:
                    limparTela(sistema);
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