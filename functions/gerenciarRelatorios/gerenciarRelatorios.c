// BIBLIOTECLAS PADRÃO, STDIO PARA COMANDOS BASICOS E STRING.H PARA MANIPULAR STRINGS
#include <stdio.h>
#include <string.h>

// INCLUINDO OS CABEÇALHOS DE FUNÇÕES DO CRUD (GERENCIAR ABELHAS, SENSORES E RELATORIOS)
#include "../gerenciarAbelhas/gerenciarAbelhas.h"
#include "../gerenciarSensores/gerenciarSensores.h"
#include "gerenciarRelatorios.h"

// INCLUINDO OS CABEÇALHOS DE FUNÇÕES DE UTILIDADE (LIMPAR TELA E LIMPAR BUFFER)
#include "../limparTela/limparTela.h"
#include "../limparBuffer/limparBuffer.h"

// INCLUINDO OS CABEÇALHOS DE FUNÇÕES DE INTERFACE (VISUAL)
#include "../../interfaces/relatoriosInterface/relatoriosInterface.h"
#include "../../interfaces/cores.h"

#include "../../structs/structs.h"

// IMPLEMENTAÇÃO DA FUNÇÃO DE PRODUÇÃO MÉDIA DE MEL
void producaoMediaMel(Abelha a[]){
    /*
        VARIÁVEIS, INICIALIZA SOMAPRODUCAO
    */
    float media, somaProducao = 0;
    /*
        QUANTIDADE DE SENDO ATRIBUIDA AO VALOR RETORNADO PELA FUNÇÃO CONT ABELHAS
    */
    int qtdAbelhas = contAbelhas();

    // ELIMINA A POSSIBILIDADE DE TER ZERO ABELHAS REGISTRADAS, JOGANDO UM ERRO E SAINDO DA FUNÇÃO
    if(qtdAbelhas == 0){
        limparTela();
        interfaceProducaoGeral();
        printf(RED BOLD "* !!! Nenhuma abelha encontrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    // PERCORRE O A QUANTIDADE DE ABELHAS DISPONIVEIS E SOMA A PRODUÇÃO DE MEL
    for(int i = 0; i < qtdAbelhas; i++){
        somaProducao += a[i].producaoMel;
    }

    // CALCULA A MÉDIA DE PRODUÇÃO DE MEL, ATRIBUINDO O RESULTADO À VARIÁVEL MEDIA
    media = somaProducao / qtdAbelhas;

    // IMPRIME A MÉDIA GERAL NA TELA E MOSTRA UMA MENSAGEM PARA QUE O USUARIO PRESSIONE ENTER PARA SAIR
    limparTela();
    interfaceProducaoGeral();
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    printf(BOLD "   Média geral: %.1fkg\n" RESET, media);
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    
    // SEM ISSO O CÓDIGO SIMPLESMENTE NÃO MOSTRARIA NADA
    printf(YELLOW "\nPressione ENTER para sair..." RESET);

    while(getchar() != '\n');
    return;
}

// IMPLEMENTAÇÃO DA FUNÇÃO DE TEMPERATURA MÉDIA DE SENSORES
void mediaTemperaturaSensores(Sensor s[]){

    // VARIAVEIS, INICIALIZA A VARIAVEL DE SOMA DE TEMPERATURAS PARA FAZER O SOMATORIO
    float media, somaTemperaturaSensores = 0;

    // QTDDESENSORESDETEMPERATURA É ATRIBUIDA AO VALOR RETORNADO PELA FUNÇÃO
    // DO CONTADOR DE SENSORES DE TEMPERATURA
    int qtdDeSensoresDeTemperatura = qtdSensoresTemperatura(s);

    // SE NÃO HOUVER NENHUM SENSOR DE TEMPERATURA, JOGA UM ERRO E SAI DA FUNÇÃO.
    if(qtdDeSensoresDeTemperatura == 0){
        limparTela();
        interfaceTemperaturaSensores();
        printf(RED BOLD "* !!! Nenhum sensor de temperatura encontrado !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    // PERCORRE A QUANTIDADE DE SENSORES DE TEMPERATURA E FAZ O SOMATORIO
    for(int i = 0; i < contSensores(); i++){
        if(strcmp(s[i].tipo, "Temperatura") == 0){
            somaTemperaturaSensores += s[i].valor;
        }
    }   

    // POSTERIORMENTE CALCULA A MÉDIA, DIVIDINDO O SOMATÓRIO DA TEMPERATURA DOS SENSORES PELA
    // QUANTIDADE DE SENSORES DE TEMPERATURA
    media = somaTemperaturaSensores / qtdDeSensoresDeTemperatura;

    // MOSTRA A MÉDIA GERAL, E DA MESMA FORMA DA FUNÇÃO DE CIMA, PEDE PARA
    // O USUARIO PRESSIONAR ENTER PARA SAIR
    limparTela();
    interfaceTemperaturaSensores();
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    printf(BOLD "   Média geral: %.1fºC\n" RESET, media);
    printf(YELLOW BOLD "-----------------------------\n" RESET);

    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while(getchar() != '\n');
    return;
}

void qtdAbelhasPorRegiao(Abelha a[]){
    // A VARIAVEL REGIOES ARMAZENA AS POSSIVEIS REGIOES
    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    // O VALOR RETORNADO PELA FUNCAO CONTABELHAS É ATRIBUIDO À VARIAVEL QTDABELHAS
    int qtdAbelhas = contAbelhas();

    // SE NÃO HOUVER NNEHUMA ABELHA, JOGA UM ERRO E SAI DA FUNÇÃO
    if(qtdAbelhas == 0){
        limparTela();
        quantidadeAbelhasPorRegiao();
        printf(RED BOLD "* !!! Nenhuma abelha encontrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    // INICIALIZA AS VARIAVEIS DE QUANTIDADE COM SUAS RESPECTIVAS REGIOES
    int qtdNorte = 0, qtdNordeste = 0, qtdCentroOeste = 0, qtdSudeste = 0, qtdSul = 0;

    // PERCORRE A QUANTIDADE DE ABELHAS SOMANDO A QUANTIDADE DE ABELHAS DE ACORDO COM SUAS RESPECTIVAS REGIOES
    for(int i = 0; i < qtdAbelhas; i++){

        // SE FOR NORTE, INCREMENTA
        if(strcmp(a[i].regiao, regioes[0]) == 0){
            qtdNorte++;

        // SE FOR NORDESTE, INCREMENTA
        }else if(strcmp(a[i].regiao, regioes[1]) == 0){
            qtdNordeste++;
        
        // SE FOR CENTRO-OESTE, INCREMENTA
        }else if(strcmp(a[i].regiao, regioes[2]) == 0){
            qtdCentroOeste++;
        
        // SE FOR SUDESTE, INCREMENTA
        }else if(strcmp(a[i].regiao, regioes[3]) == 0){
            qtdSudeste++;
        
        // SE FOR SUL, INCREMENTA
        }else if(strcmp(a[i].regiao, regioes[4]) == 0){
            qtdSul++;
        
        // SENAO, OCORREU ALGUM ERRO DESCONHECIDO, SAI DA FUNÇÃO
        }else{
            printf(RED BOLD "* !!! Erro desconhecido !!! *" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');
            return;
        }
    }

    // IMPRIME A QUANTIDADE DE ABELHAS E SUAS RESPECTIVAS REGIÕES
    limparTela();
    quantidadeAbelhasPorRegiao();
    printf(YELLOW BOLD "-----------------------------\n" RESET);
    printf(BOLD "   Norte:        %d abelha(s)\n"        RESET, qtdNorte);
    printf(BOLD "   Nordeste:     %d abelha(s)\n"        RESET, qtdNordeste);
    printf(BOLD "   Centro-oeste: %d abelha(s)\n"        RESET, qtdCentroOeste);
    printf(BOLD "   Sudeste:      %d abelha(s)\n"        RESET, qtdSudeste);
    printf(BOLD "   Sul:          %d abelha(s)\n"        RESET, qtdSul);
    printf(YELLOW BOLD "-----------------------------\n" RESET);

    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while(getchar() != '\n');
}

// IMPLEMENTAÇÃO DA FUNÇÃO DE ALERTAS AMBIENTAIS, FUNÇÃO ATRIBUIDA À NOSSA EQUIPE, HIVEGUARDIAN
void alertasAmbientais(Sensor s[]){

    // ATRIBUI O VALOR RETORNADO PELA FUNÇÃO CONTADORA DE ABELHAS À VARIAVEL QTDABELHAS
    int qtdAbelhas = contAbelhas();
    // ATRIBUI O VALOR RETORNADO PELA FUNÇÃO CONTADORA DE SENSORES À VARIAVEL QTDSENSORES
    int qtdSensores = contSensores();

    // SE NÃO HOUVER NENHUM SENSOR OU NENHUMA ABELHA, JOGA UM ERRO E SAI DO CODIGO
    if(qtdAbelhas == 0 || qtdSensores == 0){
        interfaceAlertasAmbientais();
        printf(RED BOLD " !!! * É necessário pelo menos uma abelha e um sensor !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while(getchar() != '\n');
        return;
    }

    // AS MULTIPLAS CONDIÇÕES QUE NOS FORAM PROPOSTAS

    // AQUI PERCORRE TODA A QUANTIDADE DE SENSORES
    for(int i = 0; i < qtdSensores; i++){

        // COMEÇANDO PELO SENSOR DE TEMPERATURA

        // COMPARA A STRING DE TIPO DE TEMPERATURA COM A STRING "Temperatura"
        if(strcmp(s[i].tipo, "Temperatura") == 0){

            // TEMPERATURA NORMAL: 25ºC A 32ºC
            if(s[i].valor >= 25 && s[i].valor <= 32){
                limparTela();
                interfaceAlertasAmbientais();
                printf(GREEN BOLD "NORMAL: Abelha de id [%d]\n%.1fºC: (Nenhuma Observação)\n" RESET, s[i].idAbelha, s[i].valor );

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            
            // TEMPERATURA DE ATENÇÃO: 20ºC A 24ºC E 33ºC A 35ºC
            }else if(s[i].valor >= 20 && s[i].valor <= 35){
                limparTela();
                interfaceAlertasAmbientais();
                printf(YELLOW BOLD " * !!! ATENÇÃO: Abelha de id [%d]\n%.1fºC: TEMPERATURA INADEQUADA, ABELHA PODE ESTAR EM RISCO !!! *\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            // TEMPERATURA CRÍTICA: MENOS QUE 20ºC E MAIS QUE 35ºC
            }else{
                limparTela();
                interfaceAlertasAmbientais();
                printf(RED BOLD " * !!! CRÍTICO: Abelha de id [%d]\n%.1fºC: TEMPERATURA CRÍTICA, ABELHA ESTÁ CORRENDO PERIGO !!! *\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            }
        // COMPARA O TIPO DE SENSOR DE UMIDADE COM A STRING "Umidade"
        }else if(strcmp(s[i].tipo, "Umidade") == 0){

            // NORMAL: SE A UMIDADE FOR MAIOR DO QUE 60% E MENOR DO QUE 80%
            if(s[i].valor >= 60 && s[i].valor <= 80){
                limparTela();
                interfaceAlertasAmbientais();
                printf(GREEN BOLD "NORMAL: Abelha de ID [%d]:\n%.1f%% (Nenhuma Observação)\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            // ALERTA: SE A UMIDADE FOR MAIOR DO QUE 50% E MENOR DO QUE 59% OU MAIOR DO QUE 81% E MENOR QUE 90%
            }else if(s[i].valor >= 50 && s[i].valor <= 90){
                limparTela();
                interfaceAlertasAmbientais();
                printf(YELLOW BOLD "* !!! ATENÇÃO: Abelha de id [%d]:\n%.1f%% UMIDADE INADEQUADA, PODE ESTAR CORRENDO RISCO !!! *\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            // CRÍTICO: SE A UMIDADE FOR MAIOR DO QUE 90% OU MENOR DO QUE 50%
            }else{
                limparTela();
                interfaceAlertasAmbientais();
                printf(RED BOLD "* !!! CRÍTICO: Abelha de id[%d]:\n%.1f%% ABELHA EM RISCO REAL, UMIDADE EXTREMA !!! *\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            }
        // COMPARA O SENSOR DO TIPO LUMINOSIDADE COM A STRING "Luminosidade"
        }else if(strcmp(s[i].tipo, "Luminosidade") == 0){

            // NORMAL: SE A LUMINOSIDADE FOR MAIOR QUE 100 LUX E MENOR QUE 500 LUX
            if(s[i].valor >= 100 && s[i].valor <= 500){
                limparTela();
                interfaceAlertasAmbientais();
                printf(GREEN BOLD "NORMAL: Abelha de id [%d]:\n%.0f LUX (Nenhuma Observação)\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            // CRÍTICO: SE A LUMINIDADE FOR MAIOR QUE 500 E MENOR OU IGUAL A 700
            }else if(s[i].valor > 500 && s[i].valor <= 700){
                limparTela();
                interfaceAlertasAmbientais();
                printf(YELLOW BOLD "* !!! ATENÇÃO: Abelha de id [%d]:\n%.0f LUX ILUMINAÇÃO INADEQUADA, ABELHAS PODEM ESTAR CORRENDO RISCO !!! *\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            // CRÍTICO: SE A LUMINOSIDADE FOR MAIOR DO QUE 700
            }else{
                limparTela();
                interfaceAlertasAmbientais();
                printf(RED BOLD "* !!! CRÍTICO: Abelha de id [%d]:\n%.0f LUX ABELHAS EM RISCO REAL, ILUMINAÇÃO EXTREMA !!! *\n" RESET, s[i].idAbelha, s[i].valor);

                printf(YELLOW "\nPressione ENTER para sair..." RESET);
                while(getchar() != '\n');
            }
        }
    }
}