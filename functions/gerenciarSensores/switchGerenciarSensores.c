// INCLUINDO BIBLIOTECAS PADRAO

// STDIO PARA ENTRADA E SAIDA
#include <stdio.h>

// UNISTD PARA O COMANDO SLEEP
#include <unistd.h>

// INCLUINDO FUNÇÕES DE INTERFACE (VISUAL)
#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"
#include "../../interfaces/cores.h"

// INCLUINDO O CABEÇALHO DO ARQUIVO
#include "gerenciarSensores.h"

// INCLUINDO AS FUNÇÕES DE GERENCIAR ABELHAS
#include "../gerenciarAbelhas/gerenciarAbelhas.h"

// INCLUINDO FUNÇÕES DE UTILIDADE (LIMPAR TELA E LIMPAR BUFFER)
#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"

// INCLUINDO STRUCTS PARA PASSAR COMO PARAMETRO
#include "../../structs/structs.h"

// IMPLEMENTAÇÃO DA FUNÇÃO DE NAVEGAÇÃO DO MENU GERENCIAR SENSORES
void switchGerenciarSensores(Sensor s[], Abelha a[]){
    int sensoresOption;
    do
    {  
        int isSensoresOptionValid;
        do{
            showGerenciarSensores();
            // LÊ A OPÇÃO DO MENU
            isSensoresOptionValid = scanf("%d", &sensoresOption);
            limparBuffer();

            if(isSensoresOptionValid != 1){
                printf(RED BOLD "* !!! Inválido, letras não são permitidas, tente novamente. !!! *" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }
        } while(isSensoresOptionValid != 1);

        limparTela();
        
        // ESTRUTURA DE CONDIÇÃO QUE VERIFICA A OPÇÃO QUE FOI DIGITADA
        switch (sensoresOption)
        {
        // 6: CADASTRAR SENSORES
        case 6:
            limparTela();
            cadastrarSensor(s, a, contAbelhas());
            break;
        // 7: LISTAR SENSORES
        case 7:
            limparTela();
            printf("Aguarde...\n");
            sleep(1);
            listarSensores(s);
            limparTela();
            break;
        // 8: BUSCAR SENSOR POR ID DA ABELHA
        case 8:
            limparTela();
            buscarSensorPorIdAbelha(s);
            limparTela();
            break;
        // 9: ALTERAR LEITURA
        case 9:
            limparTela();
            alterarLeitura(s, a, contAbelhas());
            limparTela();
            break;
        // 10: REMOVER SENSORES
        case 10:
            limparTela();
            removerSensor(s);
            limparTela();
            break;
        // 11: SAIR
        case 11:
            limparTela();
            printf(YELLOW BOLD "\nVoltando...\n" RESET);
            sleep(1);
            limparTela();
            break;
        default:
            limparTela();
            printf(RED BOLD "\n* !!! Opção invalida, aguarde... !!! *\n" RESET);
            sleep(1);
            limparTela();
            break;
        }
    // CONDIÇÃO FINAL: LOOP ACABA QUANDO A OPÇÃO É 11 (SAIR)
    }while (sensoresOption != 11);
}

