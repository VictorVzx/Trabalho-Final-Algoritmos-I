// standard in out, printf, scanf e as demais funções essenciais
#include <stdio.h>

//prototipo de funções (interfaces)
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "interfaces/checarSO/checarSistemaInterface.h"
#include "interfaces/gerenciarAbelhas/gerencialAbelhasInterface.h"
#include "interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

//prototipo de funções (modulos)
#include "functions/limparTela/limparTela.h"

//prototipo de structs
#include "structs/structs.h"

// limite de abelhas e sensores 
#define MAX_ABELHAS 50
#define MAX_SENSORES 100

// função main (implementação do codigo principal)
int main(void){
    int sistema;
    showChecarSistema();
    scanf("%d", &sistema);

    if(limparTela(sistema) == 0){
        printf("Sistema inválido.\n");
        return 1;
    }

    //variaveis de opção, para checar o do while
    int menuOption, abelhasOption, sensoresOption;

    do{
        //chamando a função de mostrar o menu
        interfaceMenuPrincipal();
        scanf("%d", &menuOption);
        limparTela(sistema);

        switch (menuOption)
        {
        case 1:
            showGerenciarAbelhas();
            break;
        case 2:
            showGerenciarSensores();
            break;
        case 3:
            printf("Sensores\n");
            break;
        case 4:
            printf("Saindo...\n");
        default:
            printf("Opção invalida.\n");
            limparTela(sistema);
            break;
        }
    }while(menuOption != 4);

    return 0;
}