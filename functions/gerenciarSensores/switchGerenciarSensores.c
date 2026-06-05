#include <stdio.h>

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"



#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"
#include "../../structs/structs.h"

void switchGerenciarSensores(Sensor s[], int sys){
    int abelhasOption;
    do
    {  
        showGerenciarSensores();
        scanf("%d", &abelhasOption);
        limparBuffer();
        
        switch (abelhasOption)
        {
        case 6:
            limparTela(sys);
            cadastrarAbelha(s, sys);
            printf("\nAguarde...\n");
            limparTela(sys);
            break;
        case 7:
            limparTela(sys);
            listarTodas(s, sys);
            printf("\nAguarde...\n");
            limparTela(sys);
            break;
        case 8:
            limparTela(sys);
            buscarPorNomePopular(s, sys);
            break;
        case 9:
            limparTela(sys);
            editarAbelha(s, sys);
            break;
        case 10:
            limparTela(sys);
            removerAbelha(s, sys);
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
    }while (abelhasOption != 11);
}

