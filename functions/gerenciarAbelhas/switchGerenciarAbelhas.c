// BIBLIOTECAS PADRÃO, STDIO E UNISTD
#include <stdio.h>

// UNISTD PARA UTILIZAR A FUNÇÃO SLEEP
#include <unistd.h>

// INCLUI CABEÇALHO DO ARQUIVO
#include "gerenciarAbelhas.h"

// INCLUI CABEÇALHOS DE INTERFACE (VISUAL)
#include "../../interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"
#include "../../interfaces/cores.h"

// INCLUI FUNÇÕES DE UTILIDADE, LIMPAR TELA E LIMPAR BUFFER
#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"

// INCLUI STRUCTS PARA PASSAR COMO PARAMETRO
#include "../../structs/structs.h"

// IMPLEMENTAÇÃO DA FUNÇÃO DE NAVEGAÇÃO DO MENU GERENCIAR ABELHAS
void switchGerenciarAbelhas(Abelha a[])
{   
    // RECEBE VARIAVEL OPÇÃO
    int abelhasOption;  
    do
    { 
        int isAbelhasOptionValid;
        do{
            limparTela();
            showGerenciarAbelhas();
    
            // LÊ A VARIAVEL OPÇÃO
            isAbelhasOptionValid = scanf("%d", &abelhasOption);
            limparBuffer();

            if(isAbelhasOptionValid != 1){
                printf(RED BOLD "* !!! Inválido, letras não são permitidas, tente novamente. !!! *" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }

        }while(isAbelhasOptionValid != 1);

        limparTela();
        
        // ESTRUTURA DE SELEÇÃO DE OPÇÕES COM SWITCH CASE
        switch (abelhasOption)
        {
        // PRIMEIRA OPÇÃO: 6, CADASTRAR ABELHAS
        case 6:
            limparTela();
            cadastrarAbelha(a);
            break;
        // SEGUNDA OPÇÃO: 7, LISTAR TODAS
        case 7:
            printf(YELLOW BOLD "\nAguarde...\n" RESET);
            sleep(1);
            limparTela();
            listarTodas(a);
            break;
        // TERCEIRA OPÇÃO: 8, BUSCAR POR NOME POPULAR
        case 8:
            limparTela();
            buscarPorNomePopular(a);
            break;
        // QUARTA OPÇÃO, 9: LIMPAR TELA
        case 9:
            limparTela();
            editarAbelha(a);
            break;
        // QUINTA OPÇÃO: 10, REMOVER ABELHA
        case 10:
            limparTela();
            removerAbelha(a);
            break;
        // SEXTA OPÇÃO: 11, SAIR DO MENU
        case 11:
            limparTela();
            printf(YELLOW BOLD "\nVoltando...\n" RESET);
            sleep(1);
            limparTela();
            break;
        // PADRÃO: OPÇÃO INVALIDA
        default:
            limparTela();
            printf(RED BOLD "\n* !!! Opção invalida, aguarde... !!! *\n" RESET);
            sleep(1);
            limparTela();
            break;
        }
    // CONDIÇÃO FINAL: ENCERRA O LOOP SE A OPÇÃO SELECIONADA FOR 11
    }while (abelhasOption != 11);
}