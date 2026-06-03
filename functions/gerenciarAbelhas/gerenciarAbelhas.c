#include <stdio.h>
#include "gerenciarAbelhas.h"
#include "../limparBuffer/limparBuffer.h"

void lerOpcaoAbelhas(int *option){
    scanf("%d", option);
    limparBuffer();
}