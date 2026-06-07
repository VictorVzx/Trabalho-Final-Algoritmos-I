#include <stdio.h>
#include "gerenciarAbelhasInterface.h"

#include "../cores.h"

// interface de menu, da seção "gerenciar abelhas"
void showGerenciarAbelhas(){
    printf(YELLOW BOLD "+------------------------------+\n" RESET);
    printf(YELLOW BOLD "|       GERENCIAR ABELHAS      |\n" RESET);
    printf(YELLOW BOLD "+------------------------------+\n" RESET);
    printf(YELLOW BOLD "|  6. Cadastrar abelha         |\n" RESET);
    printf(YELLOW BOLD "|  7. Listar todas             |\n" RESET);
    printf(YELLOW BOLD "|  8. Buscar por nome popular  |\n" RESET);
    printf(YELLOW BOLD "|  9. Alterar dados            |\n" RESET);
    printf(YELLOW BOLD "|  10. Remover                 |\n" RESET);
    printf(YELLOW BOLD "|  11. Voltar                  |\n" RESET);
    printf(YELLOW BOLD "+------------------------------+\n" RESET);
    printf(YELLOW BOLD "-> " RESET);
}

// interface cadastrar abelhas
void showCadastrarAbelhas(){
    printf(YELLOW BOLD "==============================\n" RESET);
    printf(YELLOW BOLD "|      CADASTRAR ABELHAS     |\n" RESET);
    printf(YELLOW BOLD "==============================\n" RESET);
    printf("\n");
}

// interface listar todas
void showListarTodas(){
    printf(YELLOW BOLD "==============================\n" RESET);
    printf(YELLOW BOLD "|         LISTAR TODAS       |\n" RESET);
    printf(YELLOW BOLD "==============================\n" RESET);
    printf("\n");
}

// interface de busca por nome popular
void showBuscarPorNomePopular(){
    printf(YELLOW BOLD "===============================\n" RESET);
    printf(YELLOW BOLD "|   BUSCAR POR NOME POPULAR   |\n" RESET);
    printf(YELLOW BOLD "===============================\n" RESET);
    printf("\n");
}

// interface do menu editar abelhas
void showEditarAbelhas(){
    printf(YELLOW BOLD "==============================\n" RESET);
    printf(YELLOW BOLD "|        EDITAR ABELHAS      |\n" RESET);
    printf(YELLOW BOLD "==============================\n" RESET);
    printf("\n");
}

// interface do menu remover abelhas
void showRemoverAbelhas(){
    printf(YELLOW BOLD "==============================\n" RESET);
    printf(YELLOW BOLD "|       REMOVER ABELHAS      |\n" RESET);
    printf(YELLOW BOLD "==============================\n" RESET);
    printf("\n");
}