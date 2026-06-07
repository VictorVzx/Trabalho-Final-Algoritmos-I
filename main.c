// standard in out, printf, scanf e as demais funções essenciais
#include <stdio.h>

// para chamar funções do sistema 
#include <stdlib.h>

//unistd para o comando sleep
#include <unistd.h>

//prototipo de funções (interfaces)
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"
#include "interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

//incluindo as funções (modulos)
#include "functions/limparTela/limparTela.h"
#include "functions/limparBuffer/limparBuffer.h"
#include "functions/gerenciarAbelhas/gerenciarAbelhas.h"
#include "functions/gerenciarAbelhas/switchGerenciarAbelhas.h"

#include "functions/gerenciarSensores/switchGerenciarSensores.h"

//prototipo das structs
#include "structs/structs.h"

// limite de abelhas e sensores 
#define MAX_ABELHAS 50
#define MAX_SENSORES 100

// função main (implementação do codigo principal)
int main(void){
    Abelha abelhas[MAX_ABELHAS];
    Sensor sensores[MAX_SENSORES];

    //variaveis de opção, para checar no do while
    int menuOption;

    do{
        //chamando a função de mostrar o menu
        interfaceMenuPrincipal();
        scanf("%d", &menuOption);
        limparBuffer();
        
        limparTela();

        
        switch (menuOption)
        {
            case 1:
                // chamar função de gerenciamento das abelhas
                limparTela();
                switchGerenciarAbelhas(abelhas);
                limparTela();
                break;
            case 2:
                limparTela();
                switchGerenciarSensores(sensores, abelhas);
                limparTela();
                break;
            case 3:
                limparTela();
                printf("Relatorios\n");
                limparTela();
                break;
            case 4:
                limparTela();
                printf("Programa encerrado.\n");
                break;
            default:
                limparTela();
                printf("Opção invalida.\n");
                limparTela();
                break;
        }
    }while(menuOption != 4);

    return 0;
}