#include <stdio.h>
#include <string.h>

#include "../gerenciarAbelhas/gerenciarAbelhas.h"
#include "../gerenciarSensores/gerenciarSensores.h"

#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"

#include "../../interfaces/relatoriosInterface/relatoriosInterface.h"
#include "../../interfaces/cores.h"

#include "../../structs/structs.h"

void producaoMediaMel(Abelha a[]){
    float media, somaProducao = 0;
    int qtdAbelhas = contAbelhas();

    if(qtdAbelhas == 0){
        limparTela();
        interfaceProducaoGeral();
        printf(RED BOLD "* !!! Nenhuma abelha encontrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    for(int i = 0; i < qtdAbelhas; i++){
        somaProducao += a[i].producaoMel;
    }

    media = somaProducao / qtdAbelhas;

    limparTela();
    interfaceProducaoGeral();
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    printf(BOLD "   Média geral: %.1fkg\n" RESET, media);
    printf(YELLOW BOLD "-----------------------------\n" RESET);

    printf(YELLOW "\nPressione ENTER para sair..." RESET);

    while(getchar() != '\n');
    return;
}

void mediaTemperaturaSensores(Sensor s[]){
    float media, somaTemperaturaSensores = 0;
    int qtdDeSensoresDeTemperatura = qtdSensoresTemperatura(s);

    if(qtdDeSensoresDeTemperatura == 0){
        limparTela();
        interfaceTemperaturaSensores();
        printf(RED BOLD "* !!! Nenhum sensor de temperatura encontrado !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    for(int i = 0; i < qtdDeSensoresDeTemperatura; i++){
        somaTemperaturaSensores += s[i].valor;
    }

    media = somaTemperaturaSensores / qtdDeSensoresDeTemperatura;

    limparTela();
    interfaceTemperaturaSensores();
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    printf(BOLD "   Média geral: %.1fºC\n" RESET, media);
    printf(YELLOW BOLD "-----------------------------\n" RESET);

    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while(getchar() != '\n');
    return;
}

void qtdAbelhasPorRegiao(Abelha a[]){
    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    int qtdAbelhas = contAbelhas();

    if(qtdAbelhas == 0){
        limparTela();
        quantidadeAbelhasPorRegiao();
        printf(RED BOLD "* !!! Nenhuma abelha encontrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    int qtdNorte = 0, qtdNordeste = 0, qtdCentroOeste = 0, qtdSudeste = 0, qtdSul = 0;

    for(int i = 0; i < qtdAbelhas; i++){
        if(strcmp(a[i].regiao, regioes[0]) == 0){
            qtdNorte++;
        }else if(strcmp(a[i].regiao, regioes[1]) == 0){
            qtdNordeste++;
        }else if(strcmp(a[i].regiao, regioes[2]) == 0){
            qtdCentroOeste++;
        }else if(strcmp(a[i].regiao, regioes[3]) == 0){
            qtdSudeste++;
        }else if(strcmp(a[i].regiao, regioes[4]) == 0){
            qtdSul++;
        }else{
            printf(RED BOLD "* !!! Erro desconhecido !!! *" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');
            return;
        }
    }

    limparTela();
    quantidadeAbelhasPorRegiao();
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    printf(BOLD "   Norte: %d\n"        RESET, qtdNorte);
    printf(BOLD "   Nordeste: %d\n"     RESET, qtdNordeste);
    printf(BOLD "   Centro-oeste: %d\n" RESET, qtdCentroOeste);
    printf(BOLD "   Sudeste: %d\n"      RESET, qtdSudeste);
    printf(BOLD "   Sul: %d\n"          RESET, qtdSul);
    printf(YELLOW BOLD "-----------------------------\n" RESET);

    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while(getchar() != '\n');
}