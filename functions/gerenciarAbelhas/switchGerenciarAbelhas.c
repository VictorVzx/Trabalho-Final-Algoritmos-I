#include <stdio.h>
#include "gerenciarAbelhas.h"
#include "../../interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"
#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"
#include "../../structs/structs.h"

void switchGerenciarAbelhas(Abelha a[], int sys)
{
    int abelhasOption;
    do
    {  
        showGerenciarAbelhas();
        scanf("%d", &abelhasOption);
        limparBuffer();
        
        switch (abelhasOption)
        {
        case 6:
            limparTela(sys);
            // chama a função de cadastrar abelhas passando como parametro o sistema para chamar a função "limparTela()", que recebe como parametro o numero do sistema operacional
            cadastrarAbelha(a, sys);
            printf("\nAguarde...\n");
            limparTela(sys);
            break;
        case 7:
            limparTela(sys);
            listarTodas(a, sys);
            printf("\nAguarde...\n");
            limparTela(sys);
            break;
        case 8:
            limparTela(sys);
            buscarPorNomePopular(a, sys);
            limparTela(sys);
            break;
        case 10:
            limparTela(sys);
            removerAbelha(a, sys);
            limparTela(sys);
            break;
        case 11:
            limparTela(sys);
            printf("\nVoltando...\n");
            limparTela(sys);
            break;
        default:
            printf("\nOpção invalida\n");
            break;
        }
    }while (abelhasOption != 11);
}