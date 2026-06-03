#include <stdio.h>
#include "limparBuffer.h"

// função para limpar o buffer
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
