#include <stdio.h>
#include <unistd.h>
#include "switchGerenciarRelatorios.h"

#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

#include "../../interfaces/relatoriosInterface/relatoriosInterface.h"

void switchGerenciarRelatorios(){

    int relatoriosOption;

    showGerenciarRelatorios();
    scanf("%d", &relatoriosOption);
    limparBuffer();

    limparTela();
    do{
        switch (relatoriosOption)
        {
        case 4:
            limparTela();
            interfaceProducaoGeral();
            limparTela();
            break;
        case 5:
            limparTela();
            interfaceTemperaturaSensores();
            limparTela();
            break;
        case 6:
            limparTela();
            quantidadeAbelhasPorRegiao();
            limparTela();
            break;
        case 7:
            limparTela();
            sleep(1);
            limparTela();
            break;
        default:
            limparTela();
            break;
        }
    }while(relatoriosOption != 7);
    
}