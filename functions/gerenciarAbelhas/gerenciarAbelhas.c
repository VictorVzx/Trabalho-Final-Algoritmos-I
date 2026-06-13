// =============================================
// GERENCIAR ABELHAS, ARQUIVO DO CRUD DE ABELHAS
// =============================================

// INCLUI AS BIBLIOTECAS PADRAO
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// INCLUI O CABEÇALHO DO ARQUIVO
#include "gerenciarAbelhas.h"

// INCLUI AS FUNÇÕES DE UTILIDADE (LIMPAR BUFFER E LIMPAR TELA)
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

// INCLUI AS INTERFACES (VISUAL)
#include "../../interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"

// INCLUI AS STRUCTS
#include "../../structs/structs.h"

// INCLUI AS CORES
#include "../../interfaces/cores.h"

/* INICIA A QUANTIDADE DE ABELHAS COMO ZERO PARA INCREMENTAR POSTERIORMENTE */
int qtdAbelhas = 0, novasAbelhas;
// INICIALIZA OS IDS
int proxIdAbelha = 1;

void cadastrarAbelha(Abelha a[])
{   
    limparTela();
    // DEFINE AS REGIÕES
    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    // NOVAS ABELHAS, É O TANTO DE ABELHAS QUE SERÁ ADICIONADO, UMA ABELHA
    novasAbelhas = 1;

    // SE A QUANTIDADE DE ABELHAS QUE VAI SE ADICIONADA + A QUANTIDADE DE ABELHAS FOR MAIOR QUE O LIMITE, JOGA UM ERRO E SAI DA FUNÇÃO
    if(qtdAbelhas + novasAbelhas > 50){
        limparTela();
        showCadastrarAbelhas();
        printf(RED BOLD "* !!! Não pode ter mais do que 50 abelhas !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while (getchar() != '\n');

        novasAbelhas = 0;
        return;
    }


    // PERCORRE A QUANTIDADE DE ABELHAS + A QUANTIDADE A ADICIONAR
    for (int i = qtdAbelhas; i < qtdAbelhas + novasAbelhas; i++)
    {
        /*LIMPA A TELA E MOSTRA O CABEÇALHO (INTERFACE DE ADICIONAR ABELHAS)*/
        limparTela();
        showCadastrarAbelhas();

        char nomePopular[40];

        /*VERIFICA SE O USUARIO NÃO DEU APENAS UM ENTER E DEIXOU O NOME POPULAR EM BRANCO
        E LANÇANDO PARA TENTAR NOVAMENTE COM A AJUDA DO LOOP (DO WHILE)*/
        do{
            // USUARIO DIGITA O NOME POPULAR DA ABELHA, LÊ COM FGETS PARA RECONHECER ESPAÇOS
            limparTela();
            showCadastrarAbelhas();
            printf(YELLOW BOLD "Digite o nome popular da abelha: " RESET);
            fgets(nomePopular, sizeof(nomePopular), stdin);
            /*
                ISTO PERCORRE A STRING DA DIREITA PRA ESQUERDA E DA ESQUERDA PRA DIREITA PROCURANDO
                O VALOR DIGITADO NO SEGUNDO PARÂMETRO, E SUBSITUINDO POR '\0' (FIM DA STRING)
                FEITO PARA REMOVER QUEBRAS DE LINHA INDESEJADAS
            */
            nomePopular[strcspn(nomePopular, "\n")] = '\0';

            /* 
                ESTRUTURAS DE CONDIÇÃO PARA VERIFICAR O ESTADO DA STRING, CASO ESTEJA EM BRANCO
                GRITA COM O USUARIO E DÁ A OPÇÃO DE TENTAR NOVAMENTE, ATÉ QUE A STRING TENHA
                ALGUM VALOR DIFERENTE DE '\0' (NADA OU FIM DA STRING)
            */
            if(nomePopular[0] == '\0'){
                printf(RED BOLD "* !!! Não pode ficar em branco, tente novamente !!! *\n" RESET);

                printf(YELLOW "Pressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }else{
                /*
                    PEGA O VALOR DA VARIAVEL LIDA E ARMAZENA NO VALOR DA STRUCT COM STRCPY
                    -> PARAMETROS (strcpy) = (DESTINO, ORIGEM)
                */
                strcpy(a[i].nomePopular, nomePopular);
                break;
            }

        /*
            LOOP SÓ ACABA SE A STRING FOR DIFERENTE DE '\0' (NÃO ESTEJA EM BRANCO)
        */
        }while(nomePopular[0] == '\0');

        /*
            CASO TENHA PASSADO NA CONDIÇÃO, LIMPA O TERMINAL E MOSTRA MENSAGEM DE 
            SUCESSO
        */
        limparTela();
        showCadastrarAbelhas();
        printf(GREEN BOLD "Nome popular adicionado com sucesso!\n" RESET);
        
        printf(YELLOW "Pressione ENTER para continuar..." RESET);
        while(getchar() != '\n');

        // PEDIR O NOME CIENTIFICO
        limparTela();
        showCadastrarAbelhas();

        char nomeCientifico[50];

        // VERIFICA SE NAO DEIXOU O NOME EM BRANCO, CASO TENHA DEIXADO, TENTE NOVAMENTE
        do
        {
            limparTela();
            showCadastrarAbelhas();
            printf(YELLOW BOLD "Digite o nome cientifico: " RESET);
            fgets(nomeCientifico, sizeof(nomeCientifico), stdin);
            // REMOVE QUEBRAS DE LINHA DAS STRINGS, REMOVENDO BUGS INDESEJADOS NAS STRINGS
            nomeCientifico[strcspn(nomeCientifico, "\n")] = '\0';
            if(nomeCientifico[0] == '\0'){
                printf(RED BOLD "* !!! Não pode ficar em branco, tente novamente !!! *\n" RESET);

                printf(YELLOW "Pressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }else{
                // ATRIBUI O VALOR DA VARIAVEL À STRUCT
                strcpy(a[i].nomeCientifico, nomeCientifico);
                break;
            }
        // CONDIÇÃO FINAL DO LOOP, SO PARA SE A VARIAVEL LIDA NAO ESTIVER EM BRANCO
        } while (nomeCientifico[0] == '\0');
        
        limparTela();
        showCadastrarAbelhas();
        // MENSAGEM DE SUCESSO, CASO O NOME CIENTIFICO TENHA SIDO ADICIONADO NORMALMENTE
        printf(GREEN BOLD "Nome cientifico adicionado com sucesso!\n" RESET);
        
        printf(YELLOW "Pressione ENTER para continuar..." RESET);
        while(getchar() != '\n');

        // LÊ A OPÇÃO E VERIFICA SE É VALIDO
        int opcaoRegiao, isValid = 0, isOpcaoValid;
        do{
            limparTela();
            showCadastrarAbelhas();
            printf(YELLOW BOLD "+---------------------------------+\n" RESET);
            printf(YELLOW BOLD "|            SELECIONE            |\n" RESET);
            printf(YELLOW BOLD "+---------------------------------+\n" RESET);
            printf(YELLOW BOLD "|   1 - Norte                     |\n" RESET);
            printf(YELLOW BOLD "|   2 - Nordeste                  |\n" RESET);
            printf(YELLOW BOLD "|   3 - Centro-oeste              |\n" RESET);
            printf(YELLOW BOLD "|   4 - Sudeste                   |\n" RESET);
            printf(YELLOW BOLD "|   5 - Sul                       |\n" RESET);
            printf(YELLOW BOLD "+---------------------------------+\n" RESET);
            printf(YELLOW BOLD "-> " RESET);
            /* VERIFICA SE O VALOR DIGITADO EM OPCAO É VALIDO, SE NÃO É UMA STRING*/
            isOpcaoValid = scanf("%d", &opcaoRegiao);
            limparBuffer();

            // 
            for(int j = 1; j <= 5; j++){
                if(opcaoRegiao == j){
                    strcpy(a[i].regiao, regioes[j - 1]);
                    isValid = 1;
                }
            }

            /*
                CONDIÇÃO PARA VER SE O VALOR DIGITADO É VALIDO OU NÃO, SE FOR UMA STRING
                JÁ RETORNA ERRO
            */
            if(isValid == 0 || isOpcaoValid != 1){
                limparTela();
                showCadastrarAbelhas();
                printf(RED BOLD "* !!! Região inválida, tente novamente !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while (getchar() != '\n');
                limparTela();
            }else{
                limparTela();
                showCadastrarAbelhas();
                printf(GREEN BOLD "Região cadastrada com sucesso!\n" RESET);

                printf(YELLOW "Pressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }

        }while(isValid == 0 || isOpcaoValid != 1);

        float mediaEmKgMes;

        // VARIAVEL PARA VERIFICAR SE NAO FOI DIGITADO UMA STRING OU CHAR
        int isQtdValid;

        // QUANTIDADE DE MEL PRODUZIDA EM KG, LÊ E ARMAZENA
        do
        {
            do{
                limparTela();
                showCadastrarAbelhas();
                printf(YELLOW BOLD "Digite a quantidade de mel kg por mês produzida: " RESET);
                isQtdValid = scanf("%f", &mediaEmKgMes);
                limparBuffer();

                if(isQtdValid != 1){
                    printf(RED BOLD "* !!! Inválido! Não pode conter letras, tente novamente !!! *\n" RESET);

                    printf(YELLOW "\nPressione ENTER para continuar... " RESET);
                    while(getchar() != '\n');
                }

            }while(isQtdValid != 1);

            // CASO A QUANTIDADE DE MEL SEJA MENOR QUE ZERO OU TENHA DIGITADO UMA STRING, RETORNA ERRO
            if(mediaEmKgMes < 0){
                limparTela();
                showCadastrarAbelhas();
                printf(RED BOLD "* !!! Não pode ser menor do que zero !!! *\n" RESET);

                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }else{
                a[i].producaoMel = mediaEmKgMes;

                limparTela();
                showCadastrarAbelhas();
                printf(GREEN BOLD "Produção de mel em kg adicionada com sucesso!\n" RESET);
                printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                while(getchar() != '\n');
            }

        } while (mediaEmKgMes < 0);
        
        // ATRIBUI O ID À ABELHA E INCREMENTA O ID DA PROXIMA
        a[i].id = proxIdAbelha;
        proxIdAbelha++;
    }

    // QUANTIDADE DE ABELHAS INCREMENTA
    qtdAbelhas++;
}

// FUNÇÃO CONTADOR DE ABELHAS, RETORNA A QUANTIDADE DE ABELHAS, FEITA PARA USAR EM OUTROS ARQUIVOS
int contAbelhas(){
    return qtdAbelhas;
}

// IMPLEMENTAÇÃO DA FUNÇÃO DE LISTAR TODAS AS ABELHAS
void listarTodas(Abelha a[])
{
    limparTela();
    showListarTodas();

    // SE NÃO HOUVER NENHUMA ABELHA, MOSTRA QUE NÃO ENCONTROU NENHUMA ABELHA, CASO CONTRARIO 
    // LISTA TODAS AS ABELHAS DISPONIVEIS
    if(qtdAbelhas != 0){
        for (int i = 0; i < qtdAbelhas; i++)
        {
            printf(YELLOW BOLD "----------------------------------\n" RESET);
            printf(BOLD "ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nQuantidade de produzido/mes: %.2fkg\n" RESET, a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
            printf(YELLOW BOLD "----------------------------------\n" RESET);
        }
    }else{
        limparTela();
        showListarTodas();
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);
    }
    printf(YELLOW "\nPressione ENTER para sair..." RESET);
    while (getchar() != '\n');
    limparTela();
}

// IMPLEMENTAÇÃO DA FUNÇÃO DE BUSCAR POR NOME POPULAR
void buscarPorNomePopular(Abelha a[])
{
    limparTela();
    showBuscarPorNomePopular();

    // SE NÃO HOUVER NENHUMA ABELHA CADASTRADA, JOGA UM ERRO E SAI DA FUNÇÃO
    if(qtdAbelhas == 0){
        limparTela();
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        return;
    }

    // VARIAVEL DE LEITURA DO NOME POPULAR
    char nomePopular[40];

    // VARIAVEL BOOLEANA, INICIALIZO COMO FALSA (METODO DA NEGAÇÃO)
    int achou = 0;

    // PEDE O NOME DA ABELHA PARA BUSCAR, LÊ COM FGETS
    do{
        limparTela();
        showBuscarPorNomePopular();
        printf(YELLOW BOLD "Digite o nome popular da abelha que você quer buscar: " RESET);
        fgets(nomePopular, sizeof(nomePopular), stdin);
        nomePopular[strcspn(nomePopular, "\n")] = '\0';
        
        // SE O USUARIO DEIXAR EM BRANCO, RETORNA ERRO E PEDE PARA TENTAR NOVAMENTE
        if(nomePopular[0] == '\0'){
            printf(RED BOLD "* !!! Não pode estar em branco, tente novamente !!! *\n" RESET);
            
            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
        }
    // LOOP SÓ ACABA QUANDO O NOME POPULAR NÃO ESTIVER MAIS EM BRANCO
    }while(nomePopular[0] == '\0');
    
    for (int i = 0; i < qtdAbelhas; i++)
    {
        // COMPARA A VARIAVEL DE NOME POPULAR COM OS NOMES POPULARES DISPONIVEIS
        // SE FOR IGUAL, ACHOU E IMPRIME, SENÃO, NÃO ACHOU
        if (strcmp(nomePopular, a[i].nomePopular) == 0)
        {
            printf(YELLOW BOLD "----------------------------------\n" RESET);
            printf(BOLD "ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n" RESET, a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
            printf(YELLOW BOLD "----------------------------------\n" RESET);
            
            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');
            achou = 1;
        }
    }

    // JOGA UM ERRO SE NÃO ACHAR A ABELHA, (VARIAVEL ACHOU CONTINUAR FALSA (0))
    if (achou == 0)
    {
        limparTela();
        printf(RED BOLD "\n* !!! Abelha não encontrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while (getchar() != '\n');
    }


    limparTela();
}

// IMPLEMENTAÇÃO DA FUNÇÃO DE EDITAR ABELHAS
void editarAbelha(Abelha a[]){
    limparTela();
    showEditarAbelhas();

    // SE NÃO HOUVER NENHUMA ABELHA, JOGA UM ERRO E SAI DA FUNÇÃO
    if(qtdAbelhas == 0){
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);
        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        limparTela();
        return;
    }

    // OPÇÕES DE REGIÃO POSSIVEIS
    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    // VARIAVEIS PARA VALIDAÇÃO
    int idDaAbelha, isExistent = 0;

    // PEDE O ID DA NOVA ABELHA PARA CADASTRAR, E ARMAZENA NA VARIAVEL IdDaAbelha
    printf(YELLOW BOLD "Digite o id da abelha que deseja editar: " RESET);
    scanf("%d", &idDaAbelha);
    limparBuffer();

    // LOOP PARA CONFIRMAR EDIÇÃO DE ABELHAS, SE SIM, CONTINUA, SENÃO SAI DA FUNÇÃO
    int confirmarEdicao = 0;
    do{
        limparTela();
        printf(YELLOW BOLD "Tem certeza que deseja editar esta abelha?" RESET YELLOW BOLD "\n\n1 - Sim\n"RESET GREEN BOLD "2 - Não\n" RESET YELLOW BOLD "\n-> " RESET);
        scanf("%d", &confirmarEdicao);
        limparBuffer();
        // SE A OPÇÃO FOR 2, IMPRIME QUE CANCELOU A OPERAÇÃO E SAI DA FUNÇÃO
        if(confirmarEdicao == 2){
            limparTela();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');
            return;
        // SE FOR 1, CONTINUA PARA EDITAR ABELHA
        }else if(confirmarEdicao == 1){
            limparTela();
        // SE FOR QUALQUER OUTRA OPÇÃO FORA 1 E 2, RETORNA OPÇÃO INVALIDA E TENTA NOVAMENTE
        }else{
            limparTela();
            printf(RED BOLD "* !!! Opção inválida, tente novamente !!! *\n" RESET);
            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            confirmarEdicao = 0;
        }
    // CONDIÇÃO FINAL, LOOP SÓ TERMINA SE CONFIRMAR EDIÇÃO FOR VÁLIDO, CASO CONTRÁRIO, TENTA NOVAMENTE
    }while(confirmarEdicao == 0);

    // VARIÁVEIS DO MENU DE EDITAR, E SABER SE A OPÇÃO LIDA NÃO É UM CHAR
    int oqEditar, isOqEditarValid;
    do{
        // INTERFACE DE MENU PARA EDITAR ABELHAS
        limparTela();
        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
        printf(YELLOW BOLD "|            SELECIONE            |\n" RESET);
        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
        printf(YELLOW BOLD "|   1 - Nome popular              |\n" RESET);
        printf(YELLOW BOLD "|   2 - Nome cientifico           |\n" RESET);
        printf(YELLOW BOLD "|   3 - Região                    |\n" RESET);
        printf(YELLOW BOLD "|   4 - Qtd de mel produzido/mes  |\n" RESET);
        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
        printf(YELLOW BOLD "-> " RESET);

        // AQUI DEFINE SE FOI DIGITADO UM CHAR OU UM NUMERO
        isOqEditarValid = scanf("%d", &oqEditar);
        limparBuffer();

        // JOGA O ERRO CASO SEJA UM CHAR/STRING, ENTRANDO NA CONDIÇÃO DO DO WHILE E TENTANDO NOVAMENTE
        if (isOqEditarValid != 1) {
            printf(RED BOLD "* !!! Entrada inválida! Digite apenas números (letras não são permitidas) !!! *\n" RESET);
            
            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while (getchar() != '\n');
            limparTela();
        }  
    // CONDIÇÃO FINAL, LOOP SÓ ACABA SE O VALOR INSERIOD NÃO FOR UM CHAR/STRING
    }while (isOqEditarValid != 1);
    
    limparTela();

    // AQUI FICA A LÓGICA DAS OPÇÕES DE EDITAR

    // ENTRA NAS CONDIÇÕES COM BASE NOS NUMEROS DO MENU E NA OPÇÃO LIDA
    if(oqEditar == 1){
        for(int i = 0; i < qtdAbelhas; i++){
            limparTela();

            // VARIAVEL PARA ARMAZENAR O NOVO NOME POPULAR, USADA PARA ATRIBUIR O VALOR AO
            // NOME POPULAR DA ABELHA
            char novoNomePopular[40];

            // VERIFICA SE O ID DIGITADO EXISTE, COMPARANDO COM OS IDS DAS ABELHAS
            if(a[i].id == idDaAbelha){
                // SE EXISTE, CONTINUA PARA EDITAR A RESPECTIVA OPÇÃO (NOME POPULAR)
                do{
                    limparTela();
                    showEditarAbelhas();
                    printf(YELLOW BOLD "Digite o novo nome popular: " RESET);
                    fgets(novoNomePopular, sizeof(novoNomePopular), stdin);

                    // ANULA A POSSIBILIDADE DE DIGITAR UMA QUEBRA DE LINHA E ENCERRAR A LEITURA DA STRING
                    novoNomePopular[strcspn(novoNomePopular, "\n")] = '\0';

                    // JOGA UM ERRO SE O USUARIO DEIXAR O CAMPO EM BRANCO E TENTA NOVAMENTE
                    if(novoNomePopular[0] == '\0'){
                        printf(RED BOLD "* !!! Não pode estar vazio, tente novamente !!! *\n" RESET);

                        printf(YELLOW "\nPressione ENTER para sair..." RESET);
                        while(getchar() != '\n');
                        break;
                    }

                    // VERIFICA SE O NOME POPULAR INSERIDO JÁ É O NOME DEFINIDO, CASO SEJA
                    // JOGA UM ERRO E TENTA NOVAMENTE
                    if(strcmp(novoNomePopular, a[i].nomePopular) == 0){
                        limparTela();
                        showEditarAbelhas();
                        printf(RED BOLD "* !!! Já é o nome popular da abelha, tente novamente !!! *\n" RESET);
                        
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while(getchar() != '\n');
                    }else{
                        printf(GREEN BOLD "Nome popular editado com sucesso!\n" RESET);
                        strcpy(a[i].nomePopular, novoNomePopular);

                        printf(YELLOW "\nPressione ENTER para sair..." RESET);
                        while(getchar() != '\n');
                        break;
                    }
                    
                }while(strcmp(novoNomePopular, a[i].nomePopular) == 0 || novoNomePopular[0] == '\0');
                isExistent = 1;
            }
        }
    }else if(oqEditar == 2){
        for(int i = 0; i < qtdAbelhas; i++){
            limparTela();

            // VERIFICA SE A ABELHA DO ID DIGITADO EXISTE
            if(a[i].id == idDaAbelha){

                // VARIAVEL QUE ARMAZENA O NOVO NOME CIENTIFICO, PARA SER ATRIBUIDA DEPOIS
                char novoNomeCientifico[50];

                // LOOP PARA EDITAR O NOME POPULAR, VERIFICANDO SE ESTÁ VAZIO
                do{
                    limparTela();
                    showEditarAbelhas();
                    printf(YELLOW BOLD "Digite o novo nome cientifico: " RESET);
                    fgets(novoNomeCientifico, sizeof(novoNomeCientifico), stdin);
                    novoNomeCientifico[strcspn(novoNomeCientifico, "\n")] = '\0';
                    
                    // SE ESTIVER VAZIO, JOGA UM ERRO E TENTA NOVAMENTE
                    if(novoNomeCientifico[0] == '\0'){
                        printf(RED BOLD "* !!! Não pode estar vazio, tente novamente !!! *\n" RESET);

                        printf(YELLOW "\nPressione ENTER para sair..." RESET);
                        while(getchar() != '\n');
                        break;
                    }

                    // VERIFICA SE O NOME CIENTIFICO DIGITADO JÁ É O NOME CIENTIFICO DA ABELHA
                    // CASO SEJA, JOGA UM ERRO E TENTA NOVAMENTE
                    if(strcmp(novoNomeCientifico, a[i].nomeCientifico) == 0){
                        printf(RED BOLD "* !!! Já é o nome cientifico da abelha, tente novamente !!! *\n" RESET);
                        
                        printf(YELLOW "Pressione ENTER para continuar..." RESET);
                        while(getchar() != '\n');
                    }else{
                        printf(GREEN BOLD "Nome cientifico editado com sucesso!\n" RESET);
                        strcpy(a[i].nomeCientifico, novoNomeCientifico);

                        printf(YELLOW "Pressione ENTER para continuar..." RESET);
                        while(getchar() != '\n');
                        break;
                    }
                
                // CONDIÇÃO FINAL, SAI DO LOOP QUANDO O NOME CIENTIFICO FOR DIFERENTE
                // E O NOME DIGITADO NÃO FOR VAZIO
                }while(strcmp(novoNomeCientifico, a[i].nomeCientifico) == 0 || novoNomeCientifico[0] == '\0');
                // DIZ QUE A ABELHA EXISTE
                isExistent = 1;
            }
        }
    }else if(oqEditar == 3){

        // PERCORRE TODAS AS ABELHAS
        for(int i = 0; i < qtdAbelhas; i++){

            // VERIFICA SE O ID DA ABELHA DIGITADA EXISTE
            if(a[i].id == idDaAbelha){

                // VARIAVEIS DE NAVEGAÇÃO E VALIDAÇÃO
                int opcaoRegiao, isValid = 0, isEditarRegiaoValid;
                do{

                    // INTERFACE DO MENU DE NAVEGAÇÃO PARA SELECIONAR REGIÕES
                    do{
                        limparTela();
                        showEditarAbelhas();
                        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                        printf(YELLOW BOLD "|            SELECIONE            |\n" RESET);
                        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                        printf(YELLOW BOLD "|   1 - Norte                     |\n" RESET);
                        printf(YELLOW BOLD "|   2 - Nordeste                  |\n" RESET);
                        printf(YELLOW BOLD "|   3 - Centro-oeste              |\n" RESET);
                        printf(YELLOW BOLD "|   4 - Sudeste                   |\n" RESET);
                        printf(YELLOW BOLD "|   5 - Sul                       |\n" RESET);
                        printf(YELLOW BOLD "+---------------------------------+\n" RESET);
                        printf(YELLOW BOLD "-> ");
    
                        // VALIDAÇÃO DA LEITURA, VERIFICA SE NÃO É UM CHAR/STRING
                        isEditarRegiaoValid = scanf("%d", &opcaoRegiao);
                        limparBuffer();
                        
                        if(isEditarRegiaoValid != 1){
                            printf(RED BOLD "* !!! Entrada inválida! Digite apenas números (letras não são permitidas) !!! *\n" RESET);
                
                            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                            while (getchar() != '\n');
                            limparTela();     
                        }
                    // CONDIÇÃO FINAL, SAI DO LOOP SE O VALOR DIGITADO NÃO FOR UM CHAR/STRING
                    } while(isEditarRegiaoValid != 1);

                    // VALIDAÇÃO DAS OPÇÕES, SE FOR MENOR QUE 1 OU MAIOR QUE 5 RETORNA ERRO
                    if(opcaoRegiao < 1 || opcaoRegiao > 5){
                        limparTela();
                        showEditarAbelhas();
                        printf(RED BOLD "*!!! Opção inválida, tente novamente !!!*\n" RESET);
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        isValid = 0;
                    }


                    if (strcmp(a[i].regiao, regioes[opcaoRegiao - 1]) == 0) {
                        limparTela();
                        showEditarAbelhas();
                        printf(RED BOLD "* !!! Já é a região definida, tente novamente !!! *\n" RESET);
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        isValid = 0;
                    }

                    strcpy(a[i].regiao, regioes[opcaoRegiao - 1]);
                    limparTela();
                    showEditarAbelhas();
                    printf(GREEN BOLD "Nova região definida com sucesso!\n" RESET);
                    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                    while (getchar() != '\n');
                    isValid = 1;
                    break;
                    
                }while(isValid == 0);

                isExistent = 1;
            }
        }
    }else if(oqEditar == 4){
        // PERCORRE TODAS AS ABELHAS
        for(int i = 0; i < qtdAbelhas; i++){
            // VARIAVEL PARA ATRIBUIR A NOVA QUANTIDADE DE MEL
            float novaQtdMel;

            // VARIAVEL PARA VERIFICAR SE FOI DIGITADO UMA STRING OU CHAR
            int isNovaQtdMelValid;

            // VERIFICA SE A ABELHA EXISTE COM BASE NO ID
            if(a[i].id == idDaAbelha){
                do{
                    // VERIFICA SE FOI DIGITADO UMA STRING OU CHAR
                    do{
                        limparTela();
                        showEditarAbelhas();
                        printf(YELLOW BOLD "Digite a quantidade média em kg por mês produzida: " RESET);
                        isNovaQtdMelValid = scanf("%f", &novaQtdMel);
                        limparBuffer();

                        if(isNovaQtdMelValid != 1){
                            printf(RED BOLD "* !!! Entrada inválida! Digite apenas números (letras não são permitidas) !!! *\n" RESET);
                
                            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                            while (getchar() != '\n');
                            limparTela();
                        }
                    // CONDIÇÃO FINAL, SAI DO LOOP SE NÃO FOR UMA STRING OU CHAR
                    }while(isNovaQtdMelValid != 1);

                    // VERIFICA SE JÁ É A PRODUÇÃO DE MEL ATUAL
                    do{
                        // SE FOR, JOGA UM ERRO E TENTA NOVAMENTE
                        if(novaQtdMel == a[i].producaoMel){
                            limparTela();
                            showEditarAbelhas();
                            printf(RED BOLD "*!!! Já é a quantidade de mel definida, tente novamente !!!*\n" RESET);
    
                            printf(YELLOW "\nPressione ENTER para continuar." RESET);
                            while(getchar() != '\n');
                        }
                    // CONDIÇÃO FINAL, SAI DO LOOP QUANDO A NOVA QTD DE MEL FOR DIFERENTE
                    }while(novaQtdMel == a[i].producaoMel );

                    // VERIFICA SE A QUANTIDADE DE MEL DIGITADA É MENOR DO QUE ZERO
                    if(novaQtdMel < 0){
                        limparTela();
                        showEditarAbelhas();
                        // SE FOR, RETORNA UM ERRO E TENTA NOVAMENTE
                        printf(RED BOLD "*!!! Não pode ser menor do que zero, tente novamente !!!*\n" RESET);

                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                    }else{
                        a[i].producaoMel = novaQtdMel;
                        limparTela();
                        showEditarAbelhas();
                        printf(GREEN BOLD "Nova quantidade de mel definida com sucesso!\n" RESET);
                        
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        return;
                    }

                }while(novaQtdMel < 0);
                isExistent = 1;
            }
        }
    }
    // SE NÃO EXISTIREM ABELHAS (BOOLEANO isExistent CONTINUAR COMO 0 (FALSE), JOGA UM ERRO E SAI DA FUNÇÃO)
    if(isExistent == 0){
        limparTela();
        showEditarAbelhas();
        printf(RED BOLD "\n * !!! Abelha não encontrada !!! *.\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while (getchar() != '\n');

        return;
    }
}

// IMPLEMENTAÇÃO DA FUNÇÃO DE REMOVER ABELHAS
void removerAbelha(Abelha a[]){
    limparTela();

    // SE NÃO HOUVER NENHUMA ABELHA, JOGA UM ERRO E SAI DA FUNÇÃO
    if(qtdAbelhas == 0){
        limparTela();
        showRemoverAbelhas();
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        limparTela();
        return;
    }

    // VARIÁVEIS DE ID DA ABELHA A REMOVER E VERIFICAR SE O ID É UMA STRING OU UM CHAR
    int idDaAbelha, isIdValid;

    do{
        limparTela();
        showRemoverAbelhas();
        printf(YELLOW BOLD "Digite o id da abelha a remover: " RESET);
        // AQUI VERIFICA SE É UMA STRING OU CHAR
        isIdValid = scanf("%d", &idDaAbelha);
        limparBuffer();
        // SE FOR STRING OU CHAR, RETORNA ID INVALIDO E TENTA NOVAMENTE    
        if(isIdValid != 1){
            printf(RED BOLD "* !!! ID inválido, tente novamente !!! *\n" RESET);
        
            printf(YELLOW "\nPressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            limparTela();
        }
    }while(isIdValid != 1);

    limparTela();

    // INICIALIZAÇÃO DA VARIAVEL DE CONFIRMAR PARA REMOVER
    int confirmar = 0;
    
    // LOOP DE CONFIRMAR PARA REMOVER
    do{
        limparTela();
        showRemoverAbelhas();
        printf(RED BOLD "Deseja realmente remover abelha?" RESET RED BOLD "\n\n1 - Sim" RESET YELLOW BOLD "\n2 - Não\n\n" RESET);
        printf(YELLOW BOLD "-> " RESET);
        scanf("%d", &confirmar);
        limparBuffer();

        limparTela();
        
        // SE A OPÇÃO FOR 1 CONTINUA PARA REMOVER
        if(confirmar == 1){
            continue;
        // SE FOR 2, CANCELA
        }else if(confirmar == 2){
            limparTela();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "Pressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            return;
        // SE FOR OUTRO VALOR, ATRIBUI 0 E ENTRA NA CONDIÇÃO DO WHILE, TENTA NOVAMENTE
        }else{
            limparTela();
            printf(RED BOLD "* !!! Opção inválida, tente novamente !!! *\n" RESET);

            printf(YELLOW "Pressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            confirmar = 0;
        }
    // CONDIÇÃO FINAL: SAI DO LOOP APENAS SE A OPÇÃO DE CONFIRMAR FOR 1 OU 2
    }while(confirmar == 0);

    // INICIALIZA O INDICE COMO -1 (INEXISTENTE)
    int indice = -1;
    for(int j = 0; j < qtdAbelhas; j++){

        // VERIFICA SE A ABELHA EXISTE, SE EXISTIR, INDICE PASSA A SER EXISTENTE
        if(a[j].id == idDaAbelha){ 
            indice = j;
            break;
        }
    }

    // SE O INDICE FOR INEXISTENTE, JOGA UM ERRO E SAI DA FUNÇÃO
    if(indice == -1){
        limparTela();
        showRemoverAbelhas();
        printf(RED BOLD "* !!! Abelha com id %d não encontrada !!! *\n" RESET, idDaAbelha);
    // SENÃO, REMOVE ABELHA
    } else {
        // MOVE OS VALORES À FRENTE E DECREMENTA A QUANTIDADE DE ABELHAS
        for(int j = indice; j < qtdAbelhas - 1; j++){
            a[j] = a[j + 1];
        }
        
        qtdAbelhas--;
        limparTela();
        showRemoverAbelhas();
        printf(GREEN BOLD "Abelha removida com sucesso!\n" RESET);
    }

    printf(YELLOW "\nPressione ENTER para continuar..." RESET);
    while (getchar() != '\n');
    limparTela();

}
