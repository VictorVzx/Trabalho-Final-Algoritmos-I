// INCLUINDO BIBLIOTECAS PADRAO

// STDIO PARA ENTRADA E SAIDA
#include <stdio.h>

// STDLIB PARA USAR FUNCIONALIDADES COMO "system("clear")"
#include <stdlib.h>

// INCLUINDO O CABEÇALHO DA FUNÇÃO
#include "limparTela.h"

/////////////////////////////////////////////
//              *UTILIDADE*               ///
/////////////////////////////////////////////
//                                         //
// FUNÇÃO DE LIMPAR TELA,   É USADA  PARA  //
// LIMPAR O TERMINAL,  DEIXANDO MAIS LEGI- //
// VEL E COMPREENSIVEL TODO O CONTEÚDO QUE //
// FOR EXIBIDO NO TERMINAL.                //
//                                         //
/////////////////////////////////////////////

// IMPLEMENTAÇÃO DA FUNÇÃO DE LIMPAR TELA
void limparTela(){
    // DISJUNÇÃO, SE FOR WINDOWS = CLS, SE FOR LINUX = CLEAR
    system("clear || cls");
}