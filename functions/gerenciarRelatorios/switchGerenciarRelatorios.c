// SWITCH DO MENU DE RELATORIOS, MENU DE NAVEGAÇÃO

// BIBLIOTECAS PADRÃO
// STDIO PARA FUNÇÕES BASICAS COMO IMPRIMIR E LER
#include <stdio.h>

// UNISTD PARA UTILIAZAR A FUNÇÃO SLEEP 
#include <unistd.h>

// INCLUI O CABEÇALHO DO ARQUIVO
#include "switchGerenciarRelatorios.h"

// INCLUI FUNÇÕES DE UTILIDADE (LIMPAR BUFFER E LIMPAR TELA)
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

// INCLUI FUNÇÕES DE INTERFACE (VISUAL)
#include "../../interfaces/relatoriosInterface/relatoriosInterface.h"
#include "../../structs/structs.h"

// INCLUI A FUNÇÃO DE GERENCIAR RELATORIOS
#include "gerenciarRelatorios.h"

// DEFININDO O LIMITE DE SENSORES E ABELHAS
#define MAX_SENSORES 100
#define MAX_ABELHAS 50

// IMPLEMENTAÇÃO DA FUNÇÃO DO MENU DE NAVEGAÇÃO
void switchGerenciarRelatorios(Abelha a[], Sensor s[]){

    // VARIAVEL DE OPÇÃO
    int relatoriosOption;

    // LOOP (DO WHILE) MOSTRA PELO MENOS UMA VEZ, CASO DIGITE 8, SAI DO MENU
    do{
        showGerenciarRelatorios();
        scanf("%d", &relatoriosOption);
        limparBuffer();
        limparTela();

        // SWITCH CASE COM AS CONSTANTES DE OPÇÃO
        switch (relatoriosOption)
        {
        // CASO USUARIO DIGITE 4, MOSTRA A PRODUÇÃO MEDIA DE MEL
        case 4:
            limparTela();
            producaoMediaMel(a);
            limparTela();
            break;
        // CASO O USUARIO DIGITE 5, MOSTRA A MEDIA DE TEMPERATURA DOS SENSORES
        case 5:
            limparTela();
            mediaTemperaturaSensores(s);
            limparTela();
            break;
        // CASO O USUARIO DIGITE 6, MOSTRA A QUANTIDADE DE ABELHAS POR REGIAO 
        case 6:
            limparTela();
            qtdAbelhasPorRegiao(a);
            limparTela();
            break;
        // CASO O USUARIO DIGITE 7, MOSTRA OS ALERTAS AMBIENTAIS
        case 7:
            limparTela();
            alertasAmbientais(a, s);
            limparTela();
            break;
        // CASO O USUARIO DIGITE 8, AVISA QUE ESTÁ SAINDO DO LOOP
        case 8:
            limparTela();
            printf("Voltando...\n");
            sleep(1);
            limparTela();
            break;
        // PADRÃO: NÃO MOSTRA NADA
        default:
            limparTela();
            break;
        }
    // CONDIÇÃO FINAL, SAI DO LOOP
    }while(relatoriosOption != 8);
    
}