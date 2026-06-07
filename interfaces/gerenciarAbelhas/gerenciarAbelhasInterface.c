#include <stdio.h>
#include "gerenciarAbelhasInterface.h"

// interface de menu, da seção "gerenciar abelhas"
void showGerenciarAbelhas(){
    printf("6. Cadastrar abelha\n");
    printf("7. Listar todas\n");
    printf("8. Buscar por nome popular\n");
    printf("9. Alterar dados\n");
    printf("10. Remover\n");
    printf("11. Voltar\n");
    printf("-> ");
}

// interface cadastrar abelhas
void showCadastrarAbelhas(){
    printf("==============================\n");
    printf("|      CADASTRAR ABELHAS     |\n");
    printf("==============================\n");
    printf("\n");
}

// interface listar todas
void showListarTodas(){
    printf("==============================\n");
    printf("|         LISTAR TODAS       |\n");
    printf("==============================\n");
    printf("\n");
}

// interface de busca por nome popular
void showBuscarPorNomePopular(){
    printf("===============================\n");
    printf("|   BUSCAR POR NOME POPULAR   |\n");
    printf("===============================\n");
    printf("\n");
}

// interface do menu editar abelhas
void showEditarAbelhas(){
    printf("==============================\n");
    printf("|        EDITAR ABELHAS      |\n");
    printf("==============================\n");
    printf("\n");
}

// interface do menu remover abelhas
void showRemoverAbelhas(){
    printf("==============================\n");
    printf("|       REMOVER ABELHAS      |\n");
    printf("==============================\n");
    printf("\n");
}