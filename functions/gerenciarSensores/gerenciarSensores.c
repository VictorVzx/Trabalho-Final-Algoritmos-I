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

            float valorDoSensor, isValueValid;
    
            do{
                limparTela();
                showCadastrarSensores();
                printf(YELLOW BOLD "Digite o valor de leitura do sensor: " RESET);
                isValueValid = scanf("%f", &valorDoSensor);
                limparBuffer();
                if((strcmp(s[i].tipo, tipos[0]) != 0 && valorDoSensor < 0) || isValueValid != 1){
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
            }while((strcmp(s[i].tipo, tipos[0]) != 0 && valorDoSensor < 0) || isValueValid != 1);
    
            int isIdValid = 0, isIdALetter;
            
            do{
                limparTela();
                showCadastrarSensores();
                printf(YELLOW BOLD "\nDigite o ID da abelha: " RESET);
                isIdALetter = scanf("%d", &s[i].idAbelha);
                limparBuffer();
                limparTela();

                if(isIdALetter != 1){
                    printf(RED BOLD "* !!! Inválido, letras não são permitidas, tente novamente !!! *\n" RESET);

                    printf(YELLOW "\nDigite ENTER para continuar..." RESET);
                    while(getchar() != '\n');
                }

            }while(isIdALetter != 1);
    
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

/*
    FUNÇÃO QUE RETORNA A QUANTIDADE DE SENSORES DO TIPO TEMPERATURA
*/

int contSensores(){
    return qtdSensores;
}

int qtdSensoresTemperatura(Sensor s[]){
    char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};

    int qtdSensoresTemperatura = 0;

    for(int i = 0; i < qtdSensores; i++){
        if(strcmp(s[i].tipo, tipos[0]) == 0){
            qtdSensoresTemperatura++;
        }
    }

    return qtdSensoresTemperatura;
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

    int isIdAssociadoALetter;
    do{
        limparTela();
        showBuscarPorIdDaAbelha();
        printf(YELLOW BOLD "Digite o id da abelha associada: " RESET);
        isIdAssociadoALetter = scanf("%d", &idAssociado);
        limparBuffer();

        if(isIdAssociadoALetter != 1){
            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }        
        
    }while(isIdAssociadoALetter != 1);

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
    int idDoSensor, isIdDoSensorALetter;
    char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};

    //inicializa variavel "achou" para saber se o sensor existe ou não
    int achou = 0;

    do{
        limparTela();
        showAlterarLeitura();
        printf(YELLOW BOLD "Digite o id do sensor para editar leitura: " RESET);   
        isIdDoSensorALetter = scanf("%d", &idDoSensor);
        limparBuffer();
        limparTela();

        if(isIdDoSensorALetter != 1){
            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }

    }while(isIdDoSensorALetter != 1);

    // confirmar edição, loop que só acaba quando uma das opções é valida
    int confirmarEdicao = 0, isConfirmarEdicaoALetter;
    do{
        do{
            limparTela();
            printf(YELLOW BOLD "Tem certeza que deseja editar este sensor?\n"RESET YELLOW BOLD "\n1 - Sim\n" RESET GREEN BOLD "2 - Não\n" RESET "\n-> " RESET);
            isConfirmarEdicaoALetter = scanf("%d", &confirmarEdicao);
            limparBuffer();

            if(isConfirmarEdicaoALetter != 1){
                printf("* !!! Inválido, não pode conter letras, tente novamente !!! *\n");

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }

        }while(isConfirmarEdicaoALetter != 1);

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
            int editarOption, isSelecTipoALetter;
            achou = 1;
            do{
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
                isSelecTipoALetter = scanf("%d", &editarOption);
                limparBuffer();
                limparTela();

                if(isSelecTipoALetter != 1){
                    printf(RED BOLD "*!!! Inválido, não pode conter letras, tente novamente !!!*\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while(getchar() != '\n');
                }

            }while(isSelecTipoALetter != 1);

            if(editarOption == 1){
        
                int opcaoTipo, isValid = 0, isOpcaoTipoALetter;
                do{
                    
                    int isTypeEqual = 0;
                    do{
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
                            isOpcaoTipoALetter = scanf("%d", &opcaoTipo);
                            limparBuffer();

                            if(isOpcaoTipoALetter != 1){
                                printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

                                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                                while(getchar() != '\n');
                            }

                        }while(isOpcaoTipoALetter != 1);
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
                int isValorNovoALetter;

                do{
                    int isValueEqual = 0;
                    do{
                        limparTela();
                        showAlterarLeitura();
                        printf(YELLOW BOLD "Digite o novo valor de leitura do sensor: " RESET);
                        isValorNovoALetter = scanf("%f", &valorNovo);
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

                    /*
                        VERIFICA SE O TIPO DE SENSOR É DE TEMPERATURA, CASO SEJA, PODE RECEBER
                        VALORES MENORES DO QUE ZERO, CASO CONTRÁRIO, OU SEJA UMA LETRA, RETORNA UM ERRO.
                    */
                    if((strcmp(s[i].tipo, tipos[0]) != 0 && valorNovo < 0) || isValorNovoALetter != 1){
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
                }while((strcmp(s[i].tipo, tipos[0]) != 0 && valorNovo < 0) || isValorNovoALetter != 1);
            }else if(editarOption == 3){

                int novoIdAbelha, achouAbelha = 0, isNovoIdAbelhaALetter;

                
                int isIdAbelhaEqual = 0;
                do
                {
                    do{
                        limparTela();
                        showAlterarLeitura();
                        printf(YELLOW BOLD "\nDigite o ID da nova abelha: " RESET);
                        isNovoIdAbelhaALetter = scanf("%d", &novoIdAbelha);
                        limparBuffer();

                        if(isNovoIdAbelhaALetter != 1){
                            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

                            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                            while(getchar() != '\n');
                        }
                        
                    }while(isNovoIdAbelhaALetter != 1);

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

    int idRmSensor, isIdRmSensorALetter;
    
    do{
        limparTela();
        showRemoverSensor();
        printf(YELLOW BOLD "Digite o id do sensor a remover: " RESET);
        isIdRmSensorALetter = scanf("%d", &idRmSensor);
        limparBuffer();

        if(isIdRmSensorALetter != 1){
            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }

    }while(isIdRmSensorALetter != 1);

    int confirmarRm = 0, isConfirmarRmALetter;

    do{
        do{
            limparTela();
            showRemoverSensor();
            printf(RED BOLD "Deseja realmente remover este sensor?" RESET RED BOLD "\n\n1 - Sim" RESET YELLOW BOLD "\n2 - Não\n\n" RESET);
            printf("-> ");
            isConfirmarRmALetter = scanf("%d", &confirmarRm);
            limparBuffer();
            limparTela();

            if(isConfirmarRmALetter != 1){
                printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }

        }while(isConfirmarRmALetter != 1);

        if(confirmarRm == 1){
            continue;
        }else if(confirmarRm == 2){
            limparTela();
            showRemoverSensor();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');

            return;
        }else{
            limparTela();
            showRemoverSensor();
            printf(RED BOLD "* !!! Opção inválida, tente novamente! !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
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
