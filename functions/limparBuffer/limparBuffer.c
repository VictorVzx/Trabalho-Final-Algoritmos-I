// INCLUI A BIBLIOTECA STDIO PARA ENTRADA E SAIDA
#include <stdio.h>

// INCLUI O CABEÇALHO DA FUNÇÃO
#include "limparBuffer.h"

////////////////////////////////////////////
//              *UTILIDADE*               //
////////////////////////////////////////////
//                                        //
// FUNÇÃO DE LIMPAR BUFFER, É USADA CASO  //
// PRECISE LER ALGUM VALOR COM SCANF, IM- //
// PEDINDO QUE O CODIGO QUEBRE CASO SEJAM //
// DIGITADOS VALORES STRING/CHAR EM UMA   //
// VARIAVEL DO TIPO INT, E PERMITE USAR   //
// GETCHAR SEM PROBLEMAS                  //
//                                        //
////////////////////////////////////////////

// IMPLEMENTAÇÃO DA FUNÇÃO DE LIMPEZA DO BUFFER
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
