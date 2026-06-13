
// =====================================================
// GERENCIAR SENSORES - ARQUIVO DO CRUD DE SENSORES
// =====================================================

/* INCLUI AS BIBLIOTECAS PADRÃO */
#include <stdio.h>

/* UNISTD PARA USAR A FUNÇÃO SLEEP */
#include <unistd.h>

/* STRING.H PARA MANIPULAR STRINGS */
#include <string.h>

/* INCLUI O CABEÇALHO DO ARQUIVO */
#include "gerenciarSensores.h"

/* INCLUI AS INTERFACES (VISUAL) */
#include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"

/* INCLUI AS FUNÇÕES DE UTILIDADE (LIMPAR BUFFER E LIMPAR TELA) */
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

/* INCLUI AS STRUCTS */
#include "../../structs/structs.h"

/* INCLUI AS CORES */
#include "../../interfaces/cores.h"

/* VARIÁVEIS GLOBAIS */

/* INICIA A QUANTIDADE DE SENSORES COMO ZERO PARA INCREMENTAR POSTERIORMENTE */
int qtdSensores = 0, novosSensores;

/* INICIALIZA OS IDS, INCREMENTA SEMPRE QUE UM NOVO SENSOR É ADICIONADO */
int id = 1;

// =============================================
// IMPLEMENTAÇÃO DA FUNÇÃO DE CADASTRAR SENSORES
// =============================================
void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas){
    limparTela();
    /* MOSTRA A INTERFACE VISUAL DE CADASTRAR SENSORES */
    showCadastrarSensores();

    /* VERIFICA SE EXISTE PELO MENOS UMA ABELHA CADASTRADA */
    if(qtdAbelhas != 0){

        /* DEFINE A QUANTIDADE DE NOVOS SENSORES, APENAS UM SENSOR É ADICIONADO POR VEZ */
        novosSensores = 1;

        /* DEFINE OS TIPOS DE SENSOR DISPONÍVEIS PARA COMPARAÇÃO POSTERIOR */
        char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};
        
        /* VERIFICA SE A QUANTIDADE DE SENSORES A ADICIONAR NÃO ULTRAPASSA O LIMITE (100 SENSORES) */
        if(qtdSensores + novosSensores > 100){
            limparTela();
            printf(RED BOLD " * !!! Não pode ter mais do que 100 sensores !!! *\n" RESET);
            
            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while (getchar() != '\n');
            
            novosSensores = 0;
            return;
        }
        
        /* ADICIONA NOVOS SENSORES COM BASE NA QUANTIDADE DEFINIDA */
        for(int i = qtdSensores; i < qtdSensores + novosSensores; i++){
            
            /* VARIÁVEIS PARA SELEÇÃO DO TIPO DE SENSOR E VALIDAÇÃO */
            int opcaoTipo, isValid = 0;
            do{
                /* EXIBE O MENU DE SELEÇÃO DE TIPOS DE SENSOR */
                limparTela();
                printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                printf(YELLOW BOLD "|         TIPO DE SENSOR          |\n" RESET);
                printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                printf(YELLOW BOLD "|   1 - Temperatura               |\n" RESET);
                printf(YELLOW BOLD "|   2 - Umidade                   |\n" RESET);
                printf(YELLOW BOLD "|   3 - Luminosidade              |\n" RESET);
                printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                printf(YELLOW BOLD "-> " RESET);
                
                /* LÊ A OPÇÃO DIGITADA PELO USUÁRIO */
                scanf("%d", &opcaoTipo);
                limparBuffer();

                limparTela();
                
                /* VALIDA SE A OPÇÃO DIGITADA É UMA DAS OPÇÕES DISPONÍVEIS (1 A 3) */
                for(int j = 1; j <= 3; j++){
                    if(opcaoTipo == j){
                        strcpy(s[i].tipo, tipos[j - 1]);
                        isValid = 1;
                    }
                }
                
                /* CASO A OPÇÃO SEJA INVÁLIDA, EXIBE MENSAGEM DE ERRO E TENTA NOVAMENTE */
                if(isValid == 0){
                    limparTela();
                    printf(RED BOLD "* !!! Tipo inválido, tente novamente !!! *\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');

                    limparTela();
                }
    
            }while(isValid != 1);
            limparTela();

            /* VARIÁVEIS PARA LER E VALIDAR O VALOR DO SENSOR */
            float valorDoSensor, isValueValid;

            int doesLoopEnd;
            
            /* INICIA UM LOOP QUE VERIFICA E VALIDA O VALOR DO SENSOR */
            do{
                limparTela();
                showCadastrarSensores();
                printf(YELLOW BOLD "Digite o valor de leitura do sensor: " RESET);
                isValueValid = scanf("%f", &valorDoSensor);
                limparBuffer();
                /* VALIDA SE O VALOR É VÁLIDO: PARA TEMPERATURA PODE SER NEGATIVO, PARA OUTROS TIPOS NÃO */
                if((strcmp(s[i].tipo, tipos[0]) != 0 && valorDoSensor < 0) || isValueValid != 1){
                    limparTela();
                    printf(RED BOLD "* !!! Valor de leitura inválido, tente novamente !!! *\n" RESET);
                    
                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');
                    doesLoopEnd = 0;
                }else if(strcmp(s[i].tipo, "Umidade") == 0 && valorDoSensor > 100){
                    limparTela();
                    printf(RED BOLD "* !!! Valor de leitura inválido, tente novamente !!! *\n" RESET);
                    
                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');
                    doesLoopEnd = 0;
                }else{
                    limparTela();
                    showCadastrarSensores();
                    s[i].valor = valorDoSensor;
                    printf(GREEN BOLD "Valor adicionado com sucesso!\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar...\n" RESET);
                    while(getchar() != '\n');
                    limparTela();
                    doesLoopEnd = 1;
                }
            }while(doesLoopEnd == 0);
    
            /* VARIÁVEIS PARA VALIDAR O ID DA ABELHA A ASSOCIAR COM O SENSOR */
            int isIdValid = 0, isIdALetter;
            
            do{
                limparTela();
                showCadastrarSensores();
                printf(YELLOW BOLD "\nDigite o ID da abelha: " RESET);
                isIdALetter = scanf("%d", &s[i].idAbelha);
                limparBuffer();
                limparTela();

                /* VERIFICA SE O VALOR DIGITADO É UM NÚMERO */
                if(isIdALetter != 1){
                    printf(RED BOLD "* !!! Inválido, letras não são permitidas, tente novamente !!! *\n" RESET);

                    printf(YELLOW "\nDigite ENTER para continuar..." RESET);
                    while(getchar() != '\n');
                }

            }while(isIdALetter != 1);
    
            /* VALIDA SE O ID DA ABELHA DIGITADO EXISTE NA BASE DE DADOS */
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
            /* CASO O ID DA ABELHA NÃO EXISTA, EXIBE ERRO E SAI DA FUNÇÃO */
            if(isIdValid == 0){
                limparTela();
                printf(RED BOLD "* !!! Id não encontrado !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while (getchar() != '\n');
                limparTela();
                return;
            }
    
            /* ATRIBUI UM ID ÚNICO AO SENSOR E INCREMENTA O CONTADOR */
            s[i].id = id;   
            id++;
        }
        /* INCREMENTA A QUANTIDADE TOTAL DE SENSORES CADASTRADOS */
        qtdSensores++;
    }else{
        /* CASO NÃO EXISTA NENHUMA ABELHA CADASTRADA, EXIBE ERRO */
        limparTela();
        showCadastrarSensores();
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);
        
        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while (getchar() != '\n');
        
        limparTela();
        return;
    }


}

/* =====================================================
   FUNÇÃO CONTADORA DE SENSORES
   RETORNA A QUANTIDADE TOTAL DE SENSORES CADASTRADOS
   ===================================================== */
int contSensores(){
    return qtdSensores;
}

/* =====================================================
   FUNÇÃO QUE CONTA A QUANTIDADE DE SENSORES DE TEMPERATURA
   PERCORRE TODOS OS SENSORES E CONTA QUANTOS SÃO DO TIPO TEMPERATURA
   ===================================================== */
int qtdSensoresTemperatura(Sensor s[]){
    char tipos[3][30] = {"Temperatura", "Umidade", "Luminosidade"};

    int qtdSensoresTemperatura = 0;

    /* PERCORRE TODOS OS SENSORES CADASTRADOS */
    for(int i = 0; i < qtdSensores; i++){
        /* COMPARA SE O TIPO DO SENSOR ATUAL É "TEMPERATURA" */
        if(strcmp(s[i].tipo, tipos[0]) == 0){
            qtdSensoresTemperatura++;
        }
    }

    return qtdSensoresTemperatura;
}

/* =====================================================
   IMPLEMENTAÇÃO DA FUNÇÃO DE LISTAR TODOS OS SENSORES
   ===================================================== */
void listarSensores(Sensor s[]){
    limparTela();
    showListarSensores();

    /* VERIFICA SE EXISTEM SENSORES CADASTRADOS */
    if(qtdSensores == 0){
        limparTela();
        printf(RED BOLD "* !!! Nenhum sensor cadastrado !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        limparTela();
        return;
    }
    
    /* EXIBE TODOS OS SENSORES COM SUAS INFORMAÇÕES */
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

    /* VARIÁVEL PARA VALIDAR SE FOI DIGITADO UM NÚMERO */
    int isIdAssociadoALetter;
    do{
        limparTela();
        showBuscarPorIdDaAbelha();
        printf(YELLOW BOLD "Digite o id da abelha associada: " RESET);
        isIdAssociadoALetter = scanf("%d", &idAssociado);
        limparBuffer();

        /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
        if(isIdAssociadoALetter != 1){
            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }        
        
    }while(isIdAssociadoALetter != 1);

    /* PERCORRE TODOS OS SENSORES E LISTA OS QUE ESTÃO ASSOCIADOS AO ID DA ABELHA INFORMADO */
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
    
    /* CASO NENHUM SENSOR TENHA SIDO ENCONTRADO, EXIBE MENSAGEM DE ERRO */
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

    /* VARIÁVEL BOOLEANA PARA SABER SE O SENSOR FOI ENCONTRADO OU NÃO */
    int achou = 0;

    do{
        limparTela();
        showAlterarLeitura();
        printf(YELLOW BOLD "Digite o id do sensor para editar leitura: " RESET);   
        isIdDoSensorALetter = scanf("%d", &idDoSensor);
        limparBuffer();
        limparTela();

        /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
        if(isIdDoSensorALetter != 1){
            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }

    }while(isIdDoSensorALetter != 1);

    /* LOOP DE CONFIRMAÇÃO DE EDIÇÃO, SÓ TERMINA COM UMA OPÇÃO VÁLIDA */
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

        /* USUARIO ESCOLHEU OPÇÃO 2 (NÃO), CANCELA A OPERAÇÃO */
        if(confirmarEdicao == 2){
            limparTela();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != 0);
            return;
        }else if(confirmarEdicao == 1){
            /* USUARIO CONFIRMOU A EDIÇÃO (OPÇÃO 1) */
            limparTela();
        }else{
            /* OPÇÃO INVÁLIDA */
            limparTela();
            printf(RED BOLD "* !!! Opção inválida !!! *\n" RESET);
            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != 0);
            confirmarEdicao = 0;
        }
    }while(confirmarEdicao == 0);

    /* PERCORRE TODOS OS SENSORES PROCURANDO PELO ID INFORMADO */
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
                /* LÊ A OPÇÃO DE EDIÇÃO */
                isSelecTipoALetter = scanf("%d", &editarOption);
                limparBuffer();
                limparTela();

                /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
                if(isSelecTipoALetter != 1){
                    printf(RED BOLD "*!!! Inválido, não pode conter letras, tente novamente !!!*\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while(getchar() != '\n');
                }

            }while(isSelecTipoALetter != 1);

            /* OPÇÃO 1: EDITAR O TIPO DO SENSOR */
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
                            /* LÊ A OPÇÃO DE TIPO */
                            isOpcaoTipoALetter = scanf("%d", &opcaoTipo);
                            limparBuffer();

                            /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
                            if(isOpcaoTipoALetter != 1){
                                printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

                                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                                while(getchar() != '\n');
                            }

                        }while(isOpcaoTipoALetter != 1);
                        /* VERIFICA SE O NOVO TIPO JÁ NÃO É O TIPO ATUAL DO SENSOR */
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
                    
                    /* VALIDA E ATRIBUI O NOVO TIPO */
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
                /* OPÇÃO 2: EDITAR O VALOR DE LEITURA DO SENSOR */
                float valorNovo;
                int isValorNovoALetter;

                int doesThisLoopEnd;

                do{
                    int isValueEqual = 0;
                    do{
                        limparTela();
                        showAlterarLeitura();
                        printf(YELLOW BOLD "Digite o novo valor de leitura do sensor: " RESET);
                        /* LÊ O NOVO VALOR */
                        isValorNovoALetter = scanf("%f", &valorNovo);
                        limparBuffer();
                        
                        /* VERIFICA SE O NOVO VALOR JÁ NÃO É O VALOR ATUAL */
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

                    /* VALIDA SE O TIPO DE SENSOR É DE TEMPERATURA, CASO SEJA, PODE RECEBER
                       VALORES MENORES DO QUE ZERO, CASO CONTRÁRIO, OU SEJA UMA LETRA, RETORNA UM ERRO. */
                    if((strcmp(s[i].tipo, tipos[0]) != 0 && valorNovo < 0) || isValorNovoALetter != 1){
                        limparTela();
                        printf(RED BOLD "* !!! Valor de leitura inválido, tente novamente !!! *\n" RESET);
                        
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        limparTela();

                        doesThisLoopEnd = 0;
                    }else if(strcmp(s[i].tipo, "Umidade") == 0 && valorNovo > 100){
                        limparTela();
                        printf(RED BOLD "* !!! Valor de leitura inválido, tente novamente !!! *\n" RESET);
                        
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        doesThisLoopEnd = 0;
                    }else{
                        /* ATRIBUI O NOVO VALOR AO SENSOR */
                        s[i].valor = valorNovo;
                        limparTela();
                        showAlterarLeitura();
                        printf(GREEN BOLD "Valor de leitura alterado com sucesso!\n" RESET);

                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        limparTela();
                        doesThisLoopEnd = 1;
                    }
                }while(doesThisLoopEnd == 0);
            }else if(editarOption == 3){
                /* OPÇÃO 3: EDITAR O ID DA ABELHA ASSOCIADA AO SENSOR */

                int novoIdAbelha, achouAbelha = 0, isNovoIdAbelhaALetter;

                
                int isIdAbelhaEqual = 0;
                do
                {
                    do{
                        limparTela();
                        showAlterarLeitura();
                        printf(YELLOW BOLD "\nDigite o ID da nova abelha: " RESET);
                        /* LÊ O NOVO ID DA ABELHA */
                        isNovoIdAbelhaALetter = scanf("%d", &novoIdAbelha);
                        limparBuffer();

                        /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
                        if(isNovoIdAbelhaALetter != 1){
                            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

                            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                            while(getchar() != '\n');
                        }
                        
                    }while(isNovoIdAbelhaALetter != 1);

                    /* VERIFICA SE O NOVO ID DE ABELHA JÁ NÃO É O ATUAL */
                    if(novoIdAbelha == s[i].idAbelha){
                        isIdAbelhaEqual = 1;
                        printf(RED BOLD "* !!! Já é o ID da abelha atual, tente novamente !!! *\n" RESET);
                        printf(YELLOW "\nPressione ENTER para sair..." RESET);
                    }else{
                        isIdAbelhaEqual = 0;
                        break;
                    }
                } while (isIdAbelhaEqual == 1);
                

                /* PROCURA SE O NOVO ID DE ABELHA EXISTE NA BASE DE DADOS */
                for(int j = 0; j < qtdAbelhas; j++){
                    if(a[j].id == novoIdAbelha){
                        limparTela();
                        /* ATRIBUI O NOVO ID DE ABELHA AO SENSOR */
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

                /* CASO O ID DA ABELHA NÃO EXISTA, EXIBE ERRO */
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
                /* OPÇÃO INVÁLIDA */
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
    /* CASO O SENSOR NÃO TENHA SIDO ENCONTRADO, EXIBE ERRO */
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

/* =====================================================
   IMPLEMENTAÇÃO DA FUNÇÃO DE REMOVER SENSOR
   ===================================================== */
void removerSensor(Sensor s[]){
    limparTela();

    /* VERIFICA SE EXISTE ALGUM SENSOR CADASTRADO */
    if(qtdSensores == 0){
        limparTela();
        showRemoverSensor();
        printf(RED BOLD "* !!! Nenhum sensor cadastrado !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        limparTela();
        return;
    }

    /* VARIÁVEIS PARA RECEBER O ID DO SENSOR A REMOVER E VALIDAR */
    int idRmSensor, isIdRmSensorALetter;
    
    do{
        limparTela();
        showRemoverSensor();
        printf(YELLOW BOLD "Digite o id do sensor a remover: " RESET);
        isIdRmSensorALetter = scanf("%d", &idRmSensor);
        limparBuffer();

        /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
        if(isIdRmSensorALetter != 1){
            printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }

    }while(isIdRmSensorALetter != 1);

    /* LOOP DE CONFIRMAÇÃO DE REMOÇÃO, SÓ TERMINA COM UMA OPÇÃO VÁLIDA */
    int confirmarRm = 0, isConfirmarRmALetter;

    do{
        do{
            limparTela();
            showRemoverSensor();
            printf(RED BOLD "Deseja realmente remover este sensor?" RESET RED BOLD "\n\n1 - Sim" RESET YELLOW BOLD "\n2 - Não\n\n" RESET);
            printf("-> ");
            /* LÊ A OPÇÃO DE CONFIRMAÇÃO */
            isConfirmarRmALetter = scanf("%d", &confirmarRm);
            limparBuffer();
            limparTela();

            /* VALIDA SE O VALOR DIGITADO É UM NÚMERO */
            if(isConfirmarRmALetter != 1){
                printf(RED BOLD "* !!! Inválido, não pode conter letras, tente novamente !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }

        }while(isConfirmarRmALetter != 1);

        /* USUARIO CONFIRMOU A REMOÇÃO (OPÇÃO 1) */
        if(confirmarRm == 1){
            continue;
        }else if(confirmarRm == 2){
            /* USUARIO CANCELOU A REMOÇÃO (OPÇÃO 2) */
            limparTela();
            showRemoverSensor();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');

            return;
        }else{
            /* OPÇÃO INVÁLIDA */
            limparTela();
            showRemoverSensor();
            printf(RED BOLD "* !!! Opção inválida, tente novamente! !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            confirmarRm = 0;
        }

    }while(confirmarRm == 0);

    /* PROCURA O ÍNDICE DO SENSOR A REMOVER */
    int indice = -1;
    for(int j = 0; j < qtdSensores; j++){
        if(s[j].id == idRmSensor){
            indice = j;
            break;
        }
    }

    /* VALIDA SE O SENSOR FOI ENCONTRADO */
    if(indice == -1){
        limparTela();
        showRemoverSensor();
        printf(RED BOLD "* !!! Sensor com id %d não encontrado !!! *\n" RESET, idRmSensor);
    } else {
        /* REMOVE O SENSOR DO ARRAY DESLOCANDO OS POSTERIORES UMA POSIÇÃO */
        for(int j = indice; j < qtdSensores - 1; j++){
            s[j] = s[j + 1];
        }
        
        /* DECREMENTA A QUANTIDADE TOTAL DE SENSORES */
        qtdSensores--;

        limparTela();
        showRemoverSensor();
        printf(GREEN BOLD "Sensor removido com sucesso!\n" RESET);
    }

    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
    while (getchar() != '\n');
    limparTela();
}
