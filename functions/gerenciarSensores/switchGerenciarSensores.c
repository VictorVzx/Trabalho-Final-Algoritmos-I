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
            break;
        case 8:
            limparTela();
            buscarSensorPorIdAbelha(s);
            break;
        case 9:
            limparTela();
            alterarLeitura(s, a, contAbelhas());
            break;
        case 10:
            limparTela();
            removerSensor(s);
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
    }while (sensoresOption != 11);
}

