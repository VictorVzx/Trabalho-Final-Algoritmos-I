#include <stdio.h>
#include <unistd.h>

#include "gerenciarAbelhas.h"
#include "../../interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"
#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"
#include "../../structs/structs.h"

void switchGerenciarAbelhas(Abelha a[])
{
    int abelhasOption;
    do
    {   
        limparTela();
        showGerenciarAbelhas();
        scanf("%d", &abelhasOption);
        limparBuffer();

        limparTela();
        
        switch (abelhasOption)
        {
        case 6:
            limparTela();
            cadastrarAbelha(a);
            break;
        case 7:
            printf("\nAguarde...\n");
            sleep(1);
            limparTela();
            listarTodas(a);
            break;
        case 8:
            limparTela();
            buscarPorNomePopular(a);
            break;
        case 9:
            limparTela();
            editarAbelha(a);
            break;
        case 10:
            limparTela();
            removerAbelha(a);
            break;
        case 11:
            limparTela();
            printf("\nVoltando...\n");
            break;
        default:
            limparTela();
            printf("\nOpção invalida\n");
            break;
        }
    }while (abelhasOption != 11);
}