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
#include "interfaces/cores.h"

//incluindo as funções (modulos)
#include "functions/limparTela/limparTela.h"
#include "functions/limparBuffer/limparBuffer.h"
#include "functions/gerenciarAbelhas/gerenciarAbelhas.h"
#include "functions/gerenciarAbelhas/switchGerenciarAbelhas.h"
#include "functions/gerenciarRelatorios/switchGerenciarRelatorios.h"
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
    int menuOption, isOptionValid;

    do{
        do{
            limparTela();
            interfaceMenuPrincipal();
            isOptionValid = scanf("%d", &menuOption);
            limparBuffer();

            if(isOptionValid != 1){
                printf(RED BOLD "* !!! Apenas números, tente novamente !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }
        }while(isOptionValid != 1);
        
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
                switchGerenciarRelatorios(abelhas, sensores);
                limparTela();
                break;
            case 4:
                limparTela();
                printf(YELLOW BOLD "Programa encerrado.\n" RESET);
                break;
            default:
                limparTela();
                printf(RED BOLD "* !!! Opção invalida, aguarde... !!! *\n" RESET);
                sleep(1);
                limparTela();
                break;
        }
    }while(menuOption != 4);

    return 0;
}