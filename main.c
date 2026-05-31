// standard in out, printf, scanf e as demais funções essenciais
#include <stdio.h>

//prototipo de funções (interfaces)
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "interfaces/checarSO/checarSistemaInterface.h"

//prototipo de funções (modulos)
#include "functions/limparTela/limparTela.h"
#include "functions/funcChecarSO/checarSO.h"

//prototipo de structs
#include "structs/structs.h"

// limite de abelhas e sensores 
#define MAX_ABELHAS 50
#define MAX_SENSORES 100

// função main (implementação do codigo principal)
int main(void){
    int sistema;
    showChecarSistema();
    checarSO(sistema);

    //variaveis de opção, para checar o do while
    int menuOption, abelhasOption, sensoresOption;

    do{
        //chamando a função de mostrar o menu
        interfaceMenuPrincipal();
        scanf("%d", &menuOption);
        limparTela(sistema);
    }while(menuOption != 4);

    return 0;
}