#include <stdio.h>
#include "gerenciarSensoresInterface.h"

void showGerenciarSensores(){
    printf("6. Cadastrar sensor\n");
    printf("7. Listar sensores\n");
    printf("8. Buscar por ID da abelha\n");
    printf("9. Alterar leitura\n");
    printf("10. Remover\n");
    printf("11. Voltar\n");
    printf("-> ");
}

// interface cadastrar sensores
void showCadastrarSensores(){
    printf("===============================\n");
    printf("|      CADASTRAR SENSORES     |\n");
    printf("===============================\n");
    printf("\n\n");
}

// interface listar sensores
void showListarSensores(){
    printf("=================================\n");
    printf("|         LISTAR SENSORES       |\n");
    printf("=================================\n");
    printf("\n\n");
}

// interface de busca por id da abelha
void showBuscarPorIdDaAbelha(){
    printf("===============================\n");
    printf("|   BUSCAR POR ID DA ABELHA   |\n");
    printf("===============================\n");
    printf("\n\n");
}

// interface do menu editar leitura
void showAlterarLeitura(){
    printf("==============================\n");
    printf("|        EDITAR LEITURA      |\n");
    printf("==============================\n");
    printf("\n\n");
}

// interface do menu remover sensores
void showRemoverSensor(){
    printf("=============================\n");
    printf("|       REMOVER SENSOR      |\n");
    printf("=============================\n");
    printf("\n\n");
}