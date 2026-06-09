#include <stdio.h>
#include <unistd.h>

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

#include "gerenciarSensores.h"

#include "../gerenciarAbelhas/gerenciarAbelhas.h"

#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"
#include "../../structs/structs.h"

void switchGerenciarSensores(Sensor s[], Abelha a[]){
    int sensoresOption;
    do
    {  
        showGerenciarSensores();
        scanf("%d", &sensoresOption);
        limparBuffer();

        limparTela();
        
        switch (sensoresOption)
        {
        case 6:
            limparTela();
            cadastrarSensor(s, a, contAbelhas());
            break;
        case 7:
            limparTela();
            printf("Aguarde...\n");
            sleep(1);
            listarSensores(s);
            limparTela();
            break;
        case 8:
            limparTela();
            buscarSensorPorIdAbelha(s);
            limparTela();
            break;
        case 9:
            limparTela();
            alterarLeitura(s, a, contAbelhas());
            limparTela();
            break;
        case 10:
            limparTela();
            removerSensor(s);
            limparTela();
            break;
        case 11:
            limparTela();
            printf("\nVoltando...\n");
            sleep(1);
            limparTela();
            break;
        default:
            limparTela();
            printf("\nOpção invalida\n");
            sleep(1);
            limparTela();
            break;
        }
    }while (sensoresOption != 11);
}

