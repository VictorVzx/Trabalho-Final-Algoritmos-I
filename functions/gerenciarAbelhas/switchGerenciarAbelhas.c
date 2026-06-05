#include <stdio.h>
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
        showGerenciarAbelhas();
        scanf("%d", &abelhasOption);
        limparBuffer();
        
        switch (abelhasOption)
        {
        case 6:
            limparTela();
            // chama a função de cadastrar abelhas passando como parametro o sistema para chamar a função "limparTela()", que recebe como parametro o numero do sistema operacional
            cadastrarAbelha(a);
            printf("\nAguarde...\n");
            limparTela();
            break;
        case 7:
            limparTela();
            listarTodas(a);
            printf("\nAguarde...\n");
            limparTela();
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
    }while (abelhasOption != 11);
}