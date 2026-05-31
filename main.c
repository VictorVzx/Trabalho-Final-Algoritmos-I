#include <stdio.h>
#include "interfaces/menuPrincipal/interfaceMenuPrincipal.h"
#include "structs/structs.h"

#define MAX_ABELHAS 50
#define MAX_SENSORES 100

int main(void){
    int menuOption, abelhasOption, sensoresOption;
    do{
        interfaceMenuPrincipal();
        scanf("%d", &menuOption);
    }while(menuOption != 4);

    return 0;
}