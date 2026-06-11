#include <stdio.h>
#include <unistd.h>
#include "switchGerenciarRelatorios.h"

#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

#include "../../interfaces/relatoriosInterface/relatoriosInterface.h"
#include "../../structs/structs.h"

#include "gerenciarRelatorios.h"

#define MAX_SENSORES 100
#define MAX_ABELHAS 50

void switchGerenciarRelatorios(Abelha a[], Sensor s[]){

    int relatoriosOption;

    do{
        showGerenciarRelatorios();
        scanf("%d", &relatoriosOption);
        limparBuffer();
        limparTela();

        switch (relatoriosOption)
        {
        case 4:
            limparTela();
            producaoMediaMel(a);
            limparTela();
            break;
        case 5:
            limparTela();
            mediaTemperaturaSensores(s);
            limparTela();
            break;
        case 6:
            limparTela();
            qtdAbelhasPorRegiao(a);
            limparTela();
            break;
        case 7:
            limparTela();
            alertasAmbientais(a, s);
            limparTela();
            break;
        case 8:
            limparTela();
            printf("Voltando...\n");
            sleep(1);
            limparTela();
            break;
        default:
            limparTela();
            break;
        }
    }while(relatoriosOption != 8);
    
}