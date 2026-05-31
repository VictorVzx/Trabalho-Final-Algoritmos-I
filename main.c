#include <stdio.h>
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "structs/structs.h"

#define MAX_ABELHAS 50
#define MAX_SENSORES 100

int main(void){
    int optionMenu, optionSubMenu;
    do{
        interfaceMenuPrincipal();
        scanf("%d", &optionMenu);
    }while(optionSubMenu != 4);

    return 0;
}