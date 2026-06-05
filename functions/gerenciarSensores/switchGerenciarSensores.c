#include <stdio.h>
#include <unistd.h>

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"
#include "../../structs/structs.h"

void switchGerenciarSensores(Sensor s[]){
    int sensoresOption;
    do
    {  
        showGerenciarSensores();
        scanf("%d", &sensoresOption);
        limparBuffer();
        
        switch (sensoresOption)
        {
        case 6:
            limparTela();
            printf("\nAguarde...\n");
            limparTela();
            break;
        case 7:
            limparTela();
            limparTela();
            break;
        case 8:
            limparTela();
            break;
        case 9:
            limparTela();
            break;
        case 10:
            limparTela();
            limparTela();
            break;
        case 11:
            limparTela();
            printf("\nVoltando...\n");
            limparTela();
            break;
        default:
            limparTela();
            printf("\nOpção invalida\n");
            break;
        }
    }while (sensoresOption != 11);
}

