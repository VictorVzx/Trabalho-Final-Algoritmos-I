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
    
    showCadastrarSensores();

    if(qtdAbelhas != 0){
        limparTela();

        novosSensores = 1;
    
        char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};
    
        if(qtdSensores + novosSensores > 100){
            limparTela();
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
    
            int opcaoTipo, isValid = 0;
            do{
                limparTela();
                showCadastrarSensores();
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
                    limparTela();
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
                showCadastrarSensores();
                printf("Digite o valor de leitura do sensor: ");
                scanf("%f", &valorDoSensor);
                limparBuffer();
                if(s[i].valor < 0){
                    limparTela();
                    printf("* !!! Valor de leitura inválido, tente novamente !!! *\n");
                    
                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');
                }else{
                    limparTela();
                    showCadastrarSensores();
                    s[i].valor = valorDoSensor;
                    printf("Valor adicionado com sucesso!\n");

                    printf("Pressione ENTER para continuar...\n");
                    while(getchar() != '\n');
                    limparTela();
                }
            }while(s[i].valor < 0);
    
            int isIdValid = 0;
            
            limparTela();
            showCadastrarSensores();
            printf("\nDigite o ID da abelha: ");
            scanf("%d", &s[i].idAbelha);
            limparBuffer();
            limparTela();
    
            for(int j = 0; j < qtdAbelhas; j++){
                if(a[j].id == s[i].idAbelha){
                    limparTela();
                    showCadastrarSensores();
                    printf("Sensor associado à abelha de id %d\n", a[j].id);

                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');
                    limparTela();
                    isIdValid = 1;
                }
            }
            if(isIdValid == 0){
                limparTela();
                printf("* !!! Id não encontrado !!! *\n");

                printf("\nPressione ENTER para sair...");
                while (getchar() != '\n');
                limparTela();
                return;
            }
    
            id++;
            s[i].id = id;   
        }
        qtdSensores++;
    }else{
        limparTela();
        showCadastrarSensores();
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
        limparTela();
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
    limparTela();
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
        showBuscarPorIdDaAbelha();
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

    limparTela();
    showAlterarLeitura();
    printf("Digite o id do sensor para editar leitura: ");   
    scanf("%d", &idDoSensor);
    limparBuffer();
    limparTela();

    int editarOption;

    for(int i = 0; i < qtdSensores; i++){
        
        if(idDoSensor == s[i].id){
            achou = 1;
            limparTela();
            showAlterarLeitura();
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
            limparTela();

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
                        limparTela();
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
                    showAlterarLeitura();
                    printf("Digite o novo valor de leitura do sensor: ");
                    scanf("%f", &valorNovo);
                    limparBuffer();
                    if(s[i].valor < 0){
                        limparTela();
                        printf("* !!! Valor de leitura inválido, tente novamente !!! *\n");
                        
                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                        limparTela();
                    }else{
                        s[i].valor = valorNovo;
                        limparTela();
                        showAlterarLeitura();
                        printf("Valor de leitura alterado com sucesso!\n");

                        printf("\nPressione ENTER para continuar...");
                        while (getchar() != '\n');
                        limparTela();
                        return;
                    }
                }while(s[i].valor < 0);
            }else if(editarOption == 3){

                int novoIdAbelha, achouAbelha = 0;

                limparTela();
                showAlterarLeitura();
                printf("\nDigite o ID da nova abelha: ");
                scanf("%d", &novoIdAbelha);
                limparBuffer();

                for(int j = 0; j < qtdAbelhas; j++){
                    if(a[j].id == novoIdAbelha){
                        limparTela();
                        s[i].idAbelha = novoIdAbelha;
                        showAlterarLeitura();
                        printf("Nova abelha associada com sucesso!\n");
                        
                        printf("\nPressione ENTER para sair...");
                        while(getchar() != '\n');
                        limparTela();

                        achouAbelha = 1;
                    }
                }

                if(achouAbelha == 0){
                    limparTela();
                    showAlterarLeitura();

                    printf("* !!! Abelha não encontrada !!! *\n");

                    printf("\nPressione ENTER para sair...");
                    while(getchar() != '\n');
                    limparTela();
                    return;
                }
            }else{
                limparTela();
                showAlterarLeitura();
                printf("* !!! Opção inválida !!! *");

                printf("\nPressione ENTER para sair...");
                while(getchar() != '\n');
                limparTela();
                return;
            }
        }
        
    }
    if(achou == 0){
        limparTela();
        showAlterarLeitura();
        printf("* !!! Sensor de id %d não encontrado !!! *\n", idDoSensor);

        printf("\nPressione ENTER para continuar...");
        while(getchar() != '\n');
        limparTela();
        return;
    }
}

void removerSensor(Sensor s[]){
    limparTela();

    if(qtdSensores == 0){
        limparTela();
        showRemoverSensor();
        printf("* !!! Nenhum sensor cadastrado !!! *\n");

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n');
        limparTela();
        return;
    }

    int idRmSensor;
    
    limparTela();
    showRemoverSensor();
    printf("Digite o id do sensor a remover: ");
    scanf("%d", &idRmSensor);
    limparBuffer();

    int confirmarRm = 0;

    do{
        limparTela();
        showRemoverSensor();
        printf("Deseja realmente remover este sensor?\n1 - Sim\n2 - Não\n");
        printf("-> ");
        scanf("%d", &confirmarRm);
        limparBuffer();
        limparTela();

        if(confirmarRm == 1){
            continue;
        }else if(confirmarRm == 2){
            limparTela();
            printf("* !!! Operação cancelada !!! *\n");

            printf("Pressione ENTER para sair...\n");
            while(getchar() != '\n');

            return;
        }else{
            limparTela();
            printf("* !!! Opção inválida, tente novamente! !!! *");

            printf("Pressione ENTER para continuar...");
            while(getchar() != '\n');
            confirmarRm = 0;
        }

    }while(confirmarRm == 0);

    int indice = -1;
    for(int j = 0; j < qtdSensores; j++){
        if(s[j].id == qtdSensores){
            indice = j;
            break;
        }
    }

    if(indice == -1){
        limparTela();
        showRemoverSensor();
        printf("* !!! Sensor com id %d não encontrado !!! *\n", idRmSensor);
    } else {
        for(int j = indice; j < qtdSensores - 1; j++){
            s[j] = s[j + 1];
        }
        
        qtdSensores--;

        limparTela();
        printf("Sensor removido com sucesso!\n");
    }

    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    limparTela();
}
