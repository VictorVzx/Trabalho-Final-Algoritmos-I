#include <stdio.h>
#include "interfaceMenuPrincipal.h"

#include "../../functions/limparTela/limparTela.h"

#include "../cores.h"

void interfaceMenuPrincipal(){
    limparTela();
    printf(YELLOW BOLD "+---------------------------+\n" RESET);
    printf(YELLOW BOLD "|    SISTEMA BEE MONITOR    |\n" RESET);
    printf(YELLOW BOLD "+---------------------------+\n" RESET);
    printf(YELLOW BOLD "|  1. Gerenciar Abelhas     |\n" RESET);
    printf(YELLOW BOLD "|  2. Gerenciar Sensores    |\n" RESET);
    printf(YELLOW BOLD "|  3. Relatórios            |\n" RESET);
    printf(YELLOW BOLD "|  4. SAIR                  |\n" RESET);
    printf(YELLOW BOLD "+---------------------------+\n" RESET);
    printf(YELLOW BOLD "Escolha uma opção: " RESET);
}