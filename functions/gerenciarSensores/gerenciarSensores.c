#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "gerenciarSensores.h"

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

#include "../../structs/structs.h"


int qtdSensores, novosSensores;

void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas){
    showCadastrarSensores();

    novosSensores = 0;

    char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};

    printf("Quantos sensores você quer cadastrar?: ");
    scanf("%d", &novosSensores);
    limparBuffer();
    char tecla;

    if(novosSensores > 100){
        printf("Não pode ter mais do que 100 sensores.\n");
        do
        {
            printf("\nPressione ENTER para sair...");
            while (getchar() != '\n');
            tecla = '\n';
        } while (tecla != '\n');
        novosSensores = 0;
        return;
    }

    int id = qtdSensores;
    for(int i = qtdSensores; i < qtdSensores + novosSensores; i++){
        limparTela();
        showGerenciarSensores();
        sleep(1);

        printf("====== %dº Sensor ======", i+1);

        int opcaoTipo, isValid = 0;
        do{
            limparTela();
            printf("==== Tipo de Sensor ====\n1 - Temperatura\n2 - Umidade\n3 - Luminosidade\n-> ");
            scanf("%d", &opcaoTipo);
            limparBuffer();

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
        
        do{
            printf("Digite o ID da abelha: ");
            scanf("%d", &s[i].idAbelha);
            limparBuffer();
    
            for(int j = 0; j < qtdAbelhas; j++){
                if(a[j].id == s[i].idAbelha){
                    printf("Sensor associado à abelha de id %d\n", a[i].id);
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
            limparTela();
            if(isIdValid == 0){
                printf("Id não encontrado...\n");
                do
                {
                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');
                    tecla = '\n';
                } while (tecla != '\n');
            }

        }while(isIdValid == 0);

        id++;
        s[i].id = id;   
    }

}

// void cadastrarSensor(Sensor s[])
// {
//     // mostra interface de cadastrar abelhas
//     showCadastrarSensores();

//     char tecla;
//     novosSensores = 0;

//     // pergunta a quantidade de abelhas antes de adicionar
//     printf("Quantos sensores voce quer cadastrar?: ");
//     scanf("%d", &novosSensores);
//     limparBuffer();

//     if(qtd > 100){
//         printf("Não pode ter mais do que 100 sensores.\n\n");
//         do
//         {
//             printf("\nPressione ENTER para sair...");
//             while (getchar() != '\n');
//             tecla = '\n';
//         } while (tecla != '\n');
//         novosSensores = 0;
//         return;
//     }

//     // id é inicializado com a quantidade atual de sensores
//     int id = qtd;

//     // loop vai da quantidade atual de sensores até a nova quantidade que o usuario deseja registrar
//     for (int i = qtd; i < qtd + novosSensores; i++)
//     {
//         limparTela();
//         showGerenciarSensores();
//         sleep(1);
//         printf("======== %dº SENSOR ========\n", i + 1);


//         id++;

//         s[i].id = id;

//     }
//     // quantidade é somado com a quantidade de novas abelhas
//     qtd += novosSensores;
// }

// void listarSensores(Sensor s[]);

// void buscarSensorPorIdAbelha(Sensor s[]);

// void alterarLeitura(Sensor s[]);

// void removerSensor(Sensor s[]);
