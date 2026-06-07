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
    
        if(qtdSensores + novosSensores > 100){
            printf(" * !!! Não pode ter mais do que 100 sensores !!! *\n");
            
            printf("\nPressione ENTER para sair...");
            while (getchar() != '\n');
            
            novosSensores = 0;
            return;
        }
    
        int id = qtdSensores;
        for(int i = qtdSensores; i < qtdSensores + novosSensores; i++){
            
            limparTela();
            showGerenciarSensores();
    
            printf("====== ADICIONAR SENSOR ======\n");
    
            int opcaoTipo, isValid = 0;
            do{
                limparTela();
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
    
                for(int j = 1; j <= 3; j++){
                    if(opcaoTipo == j){
                        strcpy(s[i].tipo, tipos[j - 1]);
                        isValid = 1;
                    }
                }
    
                if(isValid == 0){
                    printf("* !!! Tipo inválido, tente novamente !!! *\n");

                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');

                    limparTela();
                }
    
            }while(isValid != 1);
            limparTela();

            float valorDoSensor;
    
            do{
                limparTela();
                printf("Digite o valor de leitura do sensor: ");
                scanf("%f", &valorDoSensor);
                limparBuffer();
                if(s[i].valor < 0){
                    printf("* !!! Valor de leitura inválido, tente novamente !!! *\n");
                    
                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');
                }else{
                    limparTela();
                    s[i].valor = valorDoSensor;
                    printf("Valor adicionado com sucesso!\n");

                    printf("Pressione ENTER para continuar...\n");
                    while(getchar() != '\n');
                }
            }while(s[i].valor < 0);
    
            int isIdValid = 0;
            
            printf("Digite o ID da abelha: ");
            scanf("%d", &s[i].idAbelha);
            limparBuffer();
    
            for(int j = 0; j < qtdAbelhas; j++){
                if(a[j].id == s[i].idAbelha){
                    printf("Sensor associado à abelha de id %d\n", a[j].id);

                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');
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

void listarSensores(Sensor s[]){
    limparTela();
    showListarSensores();

    if(qtdSensores == 0){
        printf("* !!! Nenhum sensor cadastrado !!! *\n");

        printf("Pressione ENTER para sair...");
        while(getchar() != '\n');
        limparTela();
        return;
    }
    
    for(int i = 0; i < qtdSensores; i++){
        printf("-------------------------------------------\n");
        printf("ID: %d\nTipo do sensor: %s\nId da Abelha %d\nValor de leitura: %.2f\n", s[i].id, s[i].tipo, s[i].idAbelha, s[i].valor);
        printf("-------------------------------------------\n");
    }

    printf("\nPressione ENTER para sair...");
    while(getchar() != '\n');
    limparTela();
    return;
}

void buscarSensorPorIdAbelha(Sensor s[]){
    showBuscarPorIdDaAbelha();

    int idAssociado, achou = 0;
    printf("Digite o id da abelha associada: ");
    scanf("%d", &idAssociado);
    limparBuffer();

    for(int i = 0; i < qtdSensores; i++){
        if(s[i].idAbelha == idAssociado){
            printf("-------------------------------------------\n");
            printf("ID: %d\nTipo do sensor: %s\nId da Abelha %d\nValor de leitura: %.2f\n", s[i].id, s[i].tipo, s[i].idAbelha, s[i].valor);
            printf("-------------------------------------------\n");
            achou = 1;
        }
    }
    
    printf("\nPressione ENTER para sair...");
    while(getchar() != '\n');
    limparTela();
    return;
    
    if(achou == 0){
        limparTela();
        printf("* !!! Nenhum sensor associado à abelha de id %d !!! *\n", idAssociado);

        printf("\n\nPressione ENTER para sair...");
        while(getchar() != '\n');
        limparTela();
        return;
    }

}

void alterarLeitura(Sensor s[], Abelha a[], int qtdAbelhas){
    int idDoSensor;

    //inicializa variavel "achou" para saber se o sensor existe ou não
    int achou = 0;

    printf("Digite o id do sensor para editar leitura: ");   
    scanf("%d", &idDoSensor);
    limparBuffer();

    int editarOption;

    for(int i = 0; i < qtdSensores; i++){
        if(s[i].id == idDoSensor){

            limparTela();
            printf("+---------------------------------+\n");
            printf("|            SELECIONE            |\n");
            printf("+---------------------------------+\n");
            printf("|   1 - Editar Tipo               |\n");
            printf("|   2 - Valor de leitura          |\n");
            printf("|   3 - ID da Abelha              |\n");
            printf("+---------------------------------+\n");
            printf("-> ");
            scanf("%d", &editarOption);
            limparBuffer();

            if(editarOption == 1){
                char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};
        
                int opcaoTipo, isValid = 0;
                do{
                    limparTela();
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
        
                    for(int j = 1; j <= 3; j++){
                        if(opcaoTipo == j){
                            strcpy(s[i].tipo, tipos[j - 1]);
                            isValid = 1;
                        }
                    }
        
                    if(isValid == 0){
                        printf("* !!! Tipo inválido, tente novamente !!! *\n");
    
                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
    
                        limparTela();
                    }
        
                }while(isValid != 1);
                limparTela();
                achou = 1;
            }else if(editarOption == 2){
                float valorNovo;

                do{
                    limparTela();
                    printf("Digite o novo valor de leitura do sensor: ");
                    scanf("%f", &valorNovo);
                    limparBuffer();
                    if(s[i].valor < 0){
                        printf("* !!! Valor de leitura inválido, tente novamente !!! *\n");
                        
                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                    }else{
                        limparTela();
                        s[i].valor = valorNovo;
                        printf("Valor de leitura alterado com sucesso!\n");

                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                        return;
                    }
                }while(s[i].valor < 0);
            }else if(editarOption == 3){

                int novoIdAbelha, achou = 0;

                printf("Digite o ID da nova abelha: ");
                scanf("%d", novoIdAbelha);

                for(int i = 0; i < qtdAbelhas; i++){
                    if(a[i].id == novoIdAbelha){
                        limparTela();
                        s[i].idAbelha == novoIdAbelha;
                        printf("Nova abelha associada com sucesso!\n");
                        
                        printf("\nPressione ENTER para sair...");
                        while(getchar() != '\n');

                        achou = 1;
                    }
                }

                if(achou = 0){
                    limparTela();
                    printf("* !!! Abelha não encontrada !!! *\n");
                    printf("\nPressione ENTER para sair...");
                    while(getchar() != '\n');
                    return;
                }
            }else{
                printf("* !!! Opção inválida !!! *");

                printf("\nPressione ENTER para sair...");
                while(getchar() != '\n');
                return;
            }
        }
        
        if(achou == 0){
            limparTela();
            printf("* !!! Sensor de id %d não encontrado !!! *\n", idDoSensor);

            printf("Pressione ENTER para continuar...\n");
            while(getchar() != '\n');
            return;
        }
    }
}

// void removerSensor(Sensor s[]);
