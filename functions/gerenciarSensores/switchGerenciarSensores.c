#include <stdio.h>

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"
#include "../../structs/structs.h"

void switchGerenciarSensores(Sensor s[], int sys){
    int sensoresOption;
    do
    {  
        showGerenciarSensores();
        scanf("%d", &sensoresOption);
        limparBuffer();
        
        switch (sensoresOption)
        {
        case 6:
            limparTela(sys);
            printf("\nAguarde...\n");
            limparTela(sys);
            break;
        case 7:
            limparTela(sys);
            limparTela(sys);
            break;
        case 8:
            limparTela(sys);
            break;
        case 9:
            limparTela(sys);
            break;
        case 10:
            limparTela(sys);
            limparTela(sys);
            break;
        case 11:
            limparTela(sys);
            printf("\nVoltando...\n");
            limparTela(sys);
            break;
        default:
            limparTela(sys);
            printf("\nOpção invalida\n");
            break;
        }
    }while (sensoresOption != 11);
}

