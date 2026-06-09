#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "gerenciarSensores.h"

#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

#include "../../structs/structs.h"

#include "../../interfaces/cores.h"

// variaveis globais de quantidade, são usadas em todas as funções do crud
int qtdSensores = 0, novosSensores;

// implementação da função de cadastrar sensores
void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas){
    limparTela();
    
    showCadastrarSensores();

    if(qtdAbelhas != 0){

        novosSensores = 1;
    
        char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};
    
        if(qtdSensores + novosSensores > 100){
            limparTela();
            printf(RED BOLD " * !!! Não pode ter mais do que 100 sensores !!! *\n" RESET);
            
            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while (getchar() != '\n');
            
            novosSensores = 0;
            return;
        }
    
        int id = qtdSensores;
        for(int i = qtdSensores; i < qtdSensores + novosSensores; i++){
    
            int opcaoTipo, isValid = 0;
            do{
                limparTela();
                printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                printf(YELLOW BOLD "|         TIPO DE SENSOR          |\n" RESET);
                printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                printf(YELLOW BOLD "|   1 - Temperatura               |\n" RESET);
                printf(YELLOW BOLD "|   2 - Umidade                   |\n" RESET);
                printf(YELLOW BOLD "|   3 - Luminosidade              |\n" RESET);
                printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                printf(YELLOW BOLD "");
                
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
                    printf(RED BOLD "* !!! Tipo inválido, tente novamente !!! *\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');

                    limparTela();
                }
    
            }while(isValid != 1);
            limparTela();

            float valorDoSensor;
    
            do{
                limparTela();
                showCadastrarSensores();
                printf(YELLOW BOLD "Digite o valor de leitura do sensor: " RESET);
                scanf("%f", &valorDoSensor);
                limparBuffer();
                if(strcmp(s[i].tipo, tipos[0]) != 0 && valorDoSensor < 0){
                    limparTela();
                    printf(RED BOLD "* !!! Valor de leitura inválido, tente novamente !!! *\n" RESET);
                    
                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');
                }else{
                    limparTela();
                    showCadastrarSensores();
                    s[i].valor = valorDoSensor;
                    printf(GREEN BOLD "Valor adicionado com sucesso!\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar...\n" RESET);
                    while(getchar() != '\n');
                    limparTela();
                }
            }while(strcmp(s[i].tipo, tipos[0]) != 0 && valorDoSensor < 0);
    
            int isIdValid = 0;
            
            limparTela();
            showCadastrarSensores();
            printf(YELLOW BOLD "\nDigite o ID da abelha: " RESET);
            scanf("%d", &s[i].idAbelha);
            limparBuffer();
            limparTela();
    
            for(int j = 0; j < qtdAbelhas; j++){
                if(a[j].id == s[i].idAbelha){
                    limparTela();
                    showCadastrarSensores();
                    printf(GREEN BOLD "Sensor associado à abelha de id %d\n" RESET, a[j].id);

                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');
                    limparTela();
                    isIdValid = 1;
                }
            }
            if(isIdValid == 0){
                limparTela();
                printf(RED BOLD "* !!! Id não encontrado !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
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
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);
        
        printf(YELLOW "\nPressione ENTER para sair..." RESET);
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
        printf(RED BOLD "* !!! Nenhum sensor cadastrado !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        limparTela();
        return;
    }
    
    for(int i = 0; i < qtdSensores; i++){
        printf(YELLOW BOLD "-------------------------------------------\n" RESET);
        printf(BOLD "ID: %d\nTipo do sensor: %s\nId da Abelha %d\nValor de leitura: %.2f\n" RESET, s[i].id, s[i].tipo, s[i].idAbelha, s[i].valor);
        printf(YELLOW BOLD "-------------------------------------------\n" RESET);
    }

    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while(getchar() != '\n');
    limparTela();
    return;
}

void buscarSensorPorIdAbelha(Sensor s[]){
    limparTela();
    showBuscarPorIdDaAbelha();

    int idAssociado, achou = 0;
    printf(YELLOW BOLD "Digite o id da abelha associada: " RESET);
    scanf("%d", &idAssociado);
    limparBuffer();

    for(int i = 0; i < qtdSensores; i++){
        if(s[i].idAbelha == idAssociado){
            printf(YELLOW BOLD "-------------------------------------------\n" RESET);
            printf(BOLD "ID: %d\nTipo do sensor: %s\nId da Abelha %d\nValor de leitura: %.2f\n" RESET, s[i].id, s[i].tipo, s[i].idAbelha, s[i].valor);
            printf(YELLOW BOLD "-------------------------------------------\n" RESET);

            achou = 1;
        }
    }
    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while(getchar() != '\n');
    
    limparTela();
    
    if(achou == 0){
        limparTela();
        showBuscarPorIdDaAbelha();
        printf(RED BOLD "* !!! Nenhum sensor associado à abelha de id %d !!! *\n" RESET, idAssociado);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        limparTela();
        return;
    }

}

void alterarLeitura(Sensor s[], Abelha a[], int qtdAbelhas){
    int idDoSensor;
    char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};

    //inicializa variavel "achou" para saber se o sensor existe ou não
    int achou = 0;

    limparTela();
    showAlterarLeitura();
    printf(YELLOW BOLD "Digite o id do sensor para editar leitura: " RESET);   
    scanf("%d", &idDoSensor);
    limparBuffer();
    limparTela();

    // confirmar edição, loop que só acaba quando uma das opções é valida
    int confirmarEdicao = 0;
    do{
        limparTela();
        printf(YELLOW BOLD "Tem certeza que deseja editar este sensor?\n"RESET YELLOW BOLD "\n1 - Sim\n" RESET GREEN BOLD "2 - Não\n" RESET "\n-> " RESET);
        scanf("%d", &confirmarEdicao);
        limparBuffer();
        if(confirmarEdicao == 2){
            limparTela();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != 0);
            return;
        }else if(confirmarEdicao == 1){
            limparTela();
        }else{
            limparTela();
            printf(RED BOLD "* !!! Opção inválida !!! *\n" RESET);
            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != 0);
            confirmarEdicao = 0;
        }
    }while(confirmarEdicao == 0);

    
    for(int i = 0; i < qtdSensores; i++){
        
        if(idDoSensor == s[i].id){
            int editarOption;
            achou = 1;
            limparTela();
            showAlterarLeitura();
            printf(YELLOW BOLD "+---------------------------------+\n" RESET);
            printf(YELLOW BOLD "|            SELECIONE            |\n" RESET);
            printf(YELLOW BOLD "+---------------------------------+\n" RESET);
            printf(YELLOW BOLD "|   1 - Editar Tipo               |\n" RESET);
            printf(YELLOW BOLD "|   2 - Valor de leitura          |\n" RESET);
            printf(YELLOW BOLD "|   3 - ID da Abelha              |\n" RESET);
            printf(YELLOW BOLD "+---------------------------------+\n" RESET);
            printf(YELLOW BOLD "-> " RESET);
            scanf("%d", &editarOption);
            limparBuffer();
            limparTela();

            if(editarOption == 1){
        
                int opcaoTipo, isValid = 0;
                do{
                    
                    int isTypeEqual = 0;
                    do{
                        limparTela();
                        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                        printf(YELLOW BOLD "|         TIPO DE SENSOR          |\n" RESET);
                        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                        printf(YELLOW BOLD "|   1 - Temperatura               |\n" RESET);
                        printf(YELLOW BOLD "|   2 - Umidade                   |\n" RESET);
                        printf(YELLOW BOLD "|   3 - Luminosidade              |\n" RESET);
                        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                        printf(YELLOW BOLD "-> " RESET);
                        scanf("%d", &opcaoTipo);
                        limparBuffer();
                        if(strcmp(s[i].tipo, tipos[opcaoTipo - 1]) == 0){
                            printf(RED BOLD"* !!! Já é o tipo do sensor, tente novamente. !!! *\n" RESET);
                            isTypeEqual = 1;
                            
                            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                            while(getchar() != '\n');
                        }else{
                            isTypeEqual = 0;
                            break;
                        }
                    }while(isTypeEqual == 1);
                    
                    for(int j = 1; j <= 3; j++){
                        if(opcaoTipo == j){
                            strcpy(s[i].tipo, tipos[j - 1]);
                            isValid = 1;
                        }
                    }
        
                    if(isValid == 0){
                        limparTela();
                        showAlterarLeitura();
                        printf(RED BOLD "* !!! Tipo inválido, tente novamente !!! *\n" RESET);
    
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
    
                        limparTela();
                    }else{
                        limparTela();
                        showAlterarLeitura();
                        printf(GREEN BOLD "Novo tipo definido com sucesso!\n" RESET);

                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                    }
        
                }while(isValid != 1);
                limparTela();
            }else if(editarOption == 2){
                float valorNovo;

                do{
                    int isValueEqual = 0;
                    do{
                        limparTela();
                        showAlterarLeitura();
                        printf(YELLOW BOLD "Digite o novo valor de leitura do sensor: " RESET);
                        scanf("%f", &valorNovo);
                        limparBuffer();
                        
                        if(s[i].valor == valorNovo){
                            isValueEqual = 1;
                            printf(RED BOLD "* !!! Já é o valor de leitura do sensor, tente novamente !!! *\n" RESET);
                            
                            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                            while (getchar() != '\n');
                        }else{
                            isValueEqual = 0;
                            break;
                        }

                    }while(isValueEqual == 1);

                    if(strcmp(s[i].tipo, tipos[0]) != 0 && valorNovo < 0){
                        limparTela();
                        printf(RED BOLD "* !!! Valor de leitura inválido, tente novamente !!! *\n" RESET);
                        
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        limparTela();
                    }else{
                        s[i].valor = valorNovo;
                        limparTela();
                        showAlterarLeitura();
                        printf(GREEN BOLD "Valor de leitura alterado com sucesso!\n" RESET);

                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        limparTela();
                        return;
                    }
                }while(strcmp(s[i].tipo, tipos[0]) != 0 && valorNovo < 0);
            }else if(editarOption == 3){

                int novoIdAbelha, achouAbelha = 0;

                
                int isIdAbelhaEqual = 0;
                do
                {
                    limparTela();
                    showAlterarLeitura();
                    printf(YELLOW BOLD "\nDigite o ID da nova abelha: " RESET);
                    scanf("%d", &novoIdAbelha);
                    limparBuffer();
                    if(novoIdAbelha == s[i].idAbelha){
                        isIdAbelhaEqual = 1;
                        printf(RED BOLD "* !!! Já é o ID da abelha atual, tente novamente !!! *\n" RESET);
                        printf(YELLOW "\nPressione ENTER para sair..." RESET);
                    }else{
                        isIdAbelhaEqual = 0;
                        break;
                    }
                } while (isIdAbelhaEqual == 1);
                


                for(int j = 0; j < qtdAbelhas; j++){
                    if(a[j].id == novoIdAbelha){
                        limparTela();
                        s[i].idAbelha = novoIdAbelha;
                        showAlterarLeitura();
                        printf(GREEN BOLD "Nova abelha associada com sucesso!\n" RESET);
                        
                        printf(YELLOW "\nPressione ENTER para sair..." RESET);
                        while(getchar() != '\n');
                        limparTela();

                        achouAbelha = 1;
                        
                        return;
                    }
                }

                if(achouAbelha == 0){
                    limparTela();
                    showAlterarLeitura();

                    printf(RED BOLD "* !!! Abelha não encontrada !!! *\n" RESET);

                    printf(YELLOW "\nPressione ENTER para sair..." RESET);
                    while(getchar() != '\n');
                    limparTela();
                    return;
                }
            }else{
                limparTela();
                showAlterarLeitura();
                printf(RED BOLD "* !!! Opção inválida !!! *" RESET);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
                limparTela();
                return;
            }
            break;
        }
        
    }
    if(achou == 0){
        limparTela();
        showAlterarLeitura();
        printf(RED BOLD "* !!! Sensor de id %d não encontrado !!! *\n" RESET, idDoSensor);

        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
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
        printf(RED BOLD "* !!! Nenhum sensor cadastrado !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        limparTela();
        return;
    }

    int idRmSensor;
    
    limparTela();
    showRemoverSensor();
    printf(YELLOW BOLD "Digite o id do sensor a remover: " RESET);
    scanf("%d", &idRmSensor);
    limparBuffer();

    int confirmarRm = 0;

    do{
        limparTela();
        showRemoverSensor();
        printf(RED BOLD "Deseja realmente remover este sensor?" RESET RED BOLD "\n\n1 - Sim" RESET YELLOW BOLD "\n2 - Não\n\n" RESET);
        printf("-> ");
        scanf("%d", &confirmarRm);
        limparBuffer();
        limparTela();

        if(confirmarRm == 1){
            continue;
        }else if(confirmarRm == 2){
            limparTela();
            showRemoverSensor();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "Pressione ENTER para sair...\n" RESET);
            while(getchar() != '\n');

            return;
        }else{
            limparTela();
            showRemoverSensor();
            printf(RED BOLD "* !!! Opção inválida, tente novamente! !!! *" RESET);

            printf(YELLOW "Pressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            confirmarRm = 0;
        }

    }while(confirmarRm == 0);

    int indice = -1;
    for(int j = 0; j < qtdSensores; j++){
        if(s[j].id == idRmSensor){
            indice = j;
            break;
        }
    }

    if(indice == -1){
        limparTela();
        showRemoverSensor();
        printf(RED BOLD "* !!! Sensor com id %d não encontrado !!! *\n" RESET, idRmSensor);
    } else {
        for(int j = indice; j < qtdSensores - 1; j++){
            s[j] = s[j + 1];
        }
        
        qtdSensores--;

        limparTela();
        showRemoverSensor();
        printf(GREEN BOLD "Sensor removido com sucesso!\n" RESET);
    }

    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
    while (getchar() != '\n');
    limparTela();
}
