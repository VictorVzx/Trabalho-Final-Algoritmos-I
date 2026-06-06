#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "gerenciarSensores.h"

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

#include "../../structs/structs.h"

// variaveis globais de quantidade, são usadas em todas as funções do crud
int qtdSensores = 0, novosSensores;

// implementação da função de cadastrar sensores
void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas){
    
    if(qtdAbelhas != 0){
        showCadastrarSensores();

        novosSensores = 1;
    
        char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};
        char tecla;
    
        if(qtdSensores + novosSensores > 100){
            printf("Não pode ter mais do que 100 sensores.\n");
            
            printf("\nPressione ENTER para sair...");
            while (getchar() != '\n');
            
            novosSensores = 0;
            return;
        }
    
        int id = qtdSensores;
        for(int i = qtdSensores; i < qtdSensores + novosSensores; i++){
            
            limparTela();
            showGerenciarSensores();
    
            printf("====== ADICIONAR SENSOR ======");
    
            int opcaoTipo, isValid = 0;
            do{
                printf("+---------------------------------+\n");
                printf("|         TIPO DE SENSOR          |\n");
                printf("+---------------------------------+\n");
                printf("|   1 - Temperatura               |\n");
                printf("|   2 - Umidade                   |\n");
                printf("|   3 - Luminosidade              |\n");
                printf("+---------------------------------+\n");
                printf("-> ");
                
                scanf("%d", &opcaoTipo);
                limparBuffer();
                limparTela();
    
                for(int j = 1; j <= 3; j++){
                    if(opcaoTipo == j){
                        strcpy(s[i].tipo, tipos[j - 1]);
                        isValid = 1;
                    }
                }
    
                if(isValid == 0){
                    printf("Tipo inválido, tente novamente.\n");
                    do
                    {
                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                        tecla = '\n';
                    } while (tecla != '\n');
                    limparTela();
                }
    
            }while(isValid != 1);
            limparTela();
    
            do{
                limparTela();
                printf("Digite o valor de leitura do sensor: ");
                scanf("%f", &s[i].valor);
                limparBuffer();
                if(s[i].valor < 0){
                    printf("Valor de leitura inválido, tente novamente.\n");
                    do
                    {
                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                        tecla = '\n';
                    } while (tecla != '\n');
                }
            }while(s[i].valor < 0);
    
            int isIdValid = 0;
            
            printf("Digite o ID da abelha: ");
            scanf("%d", &s[i].idAbelha);
            limparBuffer();
    
            for(int j = 0; j < qtdAbelhas; j++){
                if(a[j].id == s[i].idAbelha){
                    printf("Sensor associado à abelha de id %d\n", a[j].id);
                    do
                    {
                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                        tecla = '\n';
                    } while (tecla != '\n');
                    limparTela();
                    isIdValid = 1;
                }
            }
            if(isIdValid == 0){
                printf("* !!! Id não encontrado !!! *\n");

                printf("\nPressione ENTER para sair...");
                while (getchar() != '\n');
                return;
            }
    
            id++;
            s[i].id = id;   
        }
        qtdSensores++;
    }else{
        limparTela();
        printf("* !!! Nenhuma abelha cadastrada !!! *\n");
        
        printf("\nPressione ENTER para sair...");
        while (getchar() != '\n');
        
        limparTela();
        return;
    }


}

void listarSensores(Sensor s[], int qtdAbelhas){
    limparTela();
    showListarSensores();

    if(qtdSensores == 0){
        printf("* !!! Nenhum sensor cadastrado !!! *\n");

        printf("Pressione ENTER para sair...");
        while(getchar() != '\n');
        limparTela();
        return;
    }
    
    for(int i = 0; i < qtdAbelhas; i++){
        printf("ID: %d\nTipo do sensor: %s\nId da Abelha %d\nValor de leitura: %f\n", s[i].id, s[i].tipo, s[i].idAbelha, s[i].valor);
    }

    printf("Pressione ENTER para sair...");
    while(getchar() != '\n');
    printf("Aguarde...");
    sleep(1);
    limparTela();
    return;
}

// void buscarSensorPorIdAbelha(Sensor s[]);

// void alterarLeitura(Sensor s[]);

// void removerSensor(Sensor s[]);
