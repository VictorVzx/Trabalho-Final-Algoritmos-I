#include <stdio.h>
#include "gerenciarSensoresInterface.h"

#include "../../functions/limparTela/limparTela.h"

#include "../cores.h"

void showGerenciarSensores(){
    limparTela();
    printf(YELLOW BOLD "+------------------------------+\n" RESET);
    printf(YELLOW BOLD "|      GERENCIAR SENSORES      |\n" RESET);
    printf(YELLOW BOLD "+------------------------------+\n" RESET);
    printf(YELLOW BOLD "|   6. Cadastrar sensor        |\n" RESET);
    printf(YELLOW BOLD "|   7. Listar sensores         |\n" RESET);
    printf(YELLOW BOLD "|   8. Buscar por ID da abelha |\n" RESET);
    printf(YELLOW BOLD "|   9. Alterar leitura         |\n" RESET);
    printf(YELLOW BOLD "|   10. Remover                |\n" RESET);
    printf(YELLOW BOLD "|   11. Voltar                 |\n" RESET);
    printf(YELLOW BOLD "+------------------------------+\n" RESET);
    printf(YELLOW BOLD "-> " RESET);
}

// interface cadastrar sensores
void showCadastrarSensores(){
    limparTela();
    printf(YELLOW BOLD "===============================\n" RESET);
    printf(YELLOW BOLD "|      CADASTRAR SENSORES     |\n" RESET);
    printf(YELLOW BOLD "===============================\n" RESET);
    printf("\n");
}

// interface listar sensores
void showListarSensores(){
    printf(YELLOW BOLD"=================================\n" RESET);
    printf(YELLOW BOLD"|         LISTAR SENSORES       |\n" RESET);
    printf(YELLOW BOLD"=================================\n" RESET);
    printf(YELLOW BOLD"\n");
}

// interface de busca por id da abelha
void showBuscarPorIdDaAbelha(){
    printf(YELLOW BOLD "===============================\n" RESET);
    printf(YELLOW BOLD "|   BUSCAR POR ID DA ABELHA   |\n" RESET);
    printf(YELLOW BOLD "===============================\n" RESET);
    printf("\n");
}

// interface do menu editar leitura
void showAlterarLeitura(){
    printf(YELLOW BOLD "==============================\n" RESET);
    printf(YELLOW BOLD "|        EDITAR LEITURA      |\n" RESET);
    printf(YELLOW BOLD "==============================\n" RESET);
    printf("\n");
}

// interface do menu remover sensores
void showRemoverSensor(){
    printf(YELLOW BOLD "=============================\n" RESET);
    printf(YELLOW BOLD "|       REMOVER SENSOR      |\n" RESET);
    printf(YELLOW BOLD "=============================\n" RESET);
    printf("\n");
}