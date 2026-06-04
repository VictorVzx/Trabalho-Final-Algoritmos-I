#include <stdio.h>
#include "gerenciarAbelhasInterface.h"

// prototipo da interface de menu, da seção "gerenciar abelhas"
void showGerenciarAbelhas(){
    printf("6. Cadastrar abelha\n");
    printf("7. Listar todas\n");
    printf("8. Buscar por nome popular\n");
    printf("9. Alterar dados\n");
    printf("10. Remover\n");
    printf("11. Voltar\n");
    printf("-> ");
}

// prototipo da função para cadastrar abelhas
void showCadastrarAbelhas(){
    printf("==============================\n");
    printf("|      CADASTRAR ABELHAS     |\n");
    printf("==============================\n");
    printf("\n\n");
}

// prototipo da função para listar todas as abelhas
void showListarTodas(){
    printf("==============================\n");
    printf("|         LISTAR TODAS       |\n");
    printf("==============================\n");
    printf("\n\n");
}

void showBuscarPorNomePopular(){
    printf("===============================\n");
    printf("|   BUSCAR POR NOME POPULAR   |\n");
    printf("===============================\n");
    printf("\n\n");
}

// prototipo da função interface "editar abelhas"
void showEditarAbelhas(){
    printf("==============================\n");
    printf("|        EDITAR ABELHAS      |\n");
    printf("==============================\n");
    printf("\n\n");
}

// prototipo da função interface "remover abelhas"
void showRemoverAbelhas(){
    printf("==============================\n");
    printf("|       REMOVER ABELHAS      |\n");
    printf("==============================\n");
    printf("\n\n");
}