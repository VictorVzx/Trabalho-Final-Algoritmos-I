#include <stdio.h>
#include "relatoriosInterface.h"

#include "../cores.h"

void showGerenciarRelatorios(){
    printf(YELLOW BOLD "+--------------------------------------------+\n" RESET);
    printf(YELLOW BOLD "|            GERENCIAR RELATORIOS            |\n" RESET);
    printf(YELLOW BOLD "+--------------------------------------------+\n" RESET);
    printf(YELLOW BOLD "|  4. Media geral de produção de mel         |\n" RESET);
    printf(YELLOW BOLD "|  5. Média de temperatura dos sensores      |\n" RESET);
    printf(YELLOW BOLD "|  6. Quantidade de abelhas por região       |\n" RESET);
    printf(YELLOW BOLD "|  7. Voltar                                 |\n" RESET);
    printf(YELLOW BOLD "+--------------------------------------------+\n" RESET);
    printf(YELLOW BOLD "-> " RESET);
}

void interfaceProducaoGeral(){
    printf(YELLOW BOLD "+----------------------------------------+\n" RESET);
    printf(YELLOW BOLD "|     MÉDIA GERAL DE PRODUÇÃO DE MEL     |\n" RESET);
    printf(YELLOW BOLD "+----------------------------------------+\n" RESET);
}

void interfaceTemperaturaSensores(){
    printf(YELLOW BOLD "+------------------------------------------+\n" RESET);
    printf(YELLOW BOLD "|     MÉDIA DE TEMPERATURA DOS SENSORES    |\n" RESET);
    printf(YELLOW BOLD "+------------------------------------------+\n" RESET);
}

void quantidadeAbelhasPorRegiao(){
    printf(YELLOW BOLD "+------------------------------------------+\n" RESET);
    printf(YELLOW BOLD "|     QUANTIDADE DE ABELHAS POR REGIÃO     |\n" RESET);
    printf(YELLOW BOLD "+------------------------------------------+\n" RESET);
}

void interfaceAlertasAmbientais(){
    printf(YELLOW BOLD "+------------------------------------------+\n" RESET);
    printf(YELLOW BOLD "|             ALERTAS AMBIENTAIS           |\n" RESET);
    printf(YELLOW BOLD "+------------------------------------------+\n" RESET);
}