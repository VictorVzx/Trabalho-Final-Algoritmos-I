#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "gerenciarAbelhas.h"

// incluir a funções de limpar buffer e limpar tela
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

// incluir a interface de listar todas
#include "../../interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"

#include "../../structs/structs.h"

int qtdAbelhas = 0, novasAbelhas;

void cadastrarAbelha(Abelha a[])
{
    // mostra interface de cadastrar abelhas
    showCadastrarAbelhas();

    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    char tecla;

    // novas abelhas é hardcoded pois sempre vai adicionar apenas UMA abelha
    novasAbelhas = 1;

    if(qtdAbelhas + novasAbelhas > 50){
        limparTela();
        printf("* !!! Não pode ter mais do que 50 abelhas !!! *\n\n");

        printf("\nPressione ENTER para sair...");
        while (getchar() != '\n');

        novasAbelhas = 0;
        return;
    }

    // id é inicializado com a quantidade atual de abelhas (o ID da abelha 50 seria 50)
    int id = qtdAbelhas;

    // loop vai da quantidade atual de abelhas até a nova quantidade que o usuario deseja registrar
    for (int i = qtdAbelhas; i < qtdAbelhas + novasAbelhas; i++)
    {
        limparTela();
        showCadastrarAbelhas();
        sleep(1);
        printf("======== ADICIONAR ABELHA ========\n");

        // pedir o nome popular
        limparTela();
        printf("Digite o nome popular da abelha: ");
        fgets(a[i].nomePopular, sizeof(a[i].nomePopular), stdin);
        a[i].nomePopular[strcspn(a[i].nomePopular, "\n")] = '\0';

        // pedir o nome cientifico
        limparTela();
        printf("Digite o nome cientifico: ");
        fgets(a[i].nomeCientifico, sizeof(a[i].nomeCientifico), stdin);
        a[i].nomeCientifico[strcspn(a[i].nomeCientifico, "\n")] = '\0';

        // pedir a regiao

        int opcaoRegiao, isValid = 0;
        do{
            limparTela();
            printf("+---------------------------------+\n");
            printf("|            SELECIONE            |\n");
            printf("+---------------------------------+\n");
            printf("|   1 - Norte                     |\n");
            printf("|   2 - Nordeste                  |\n");
            printf("|   3 - Centro-oeste              |\n");
            printf("|   4 - Sudeste                   |\n");
            printf("|   5 - Sul                       |\n");
            printf("+---------------------------------+\n");
            printf("-> ");
            scanf("%d", &opcaoRegiao);
            limparBuffer();

            for(int j = 1; j <= 5; j++){
                if(opcaoRegiao == j){
                    strcpy(a[i].regiao, regioes[j - 1]);
                    isValid = 1;
                }
            }

            if(isValid == 0){
                limparTela();
                printf("* !!! Região inválida, tente novamente !!! *\n");
                do
                {
                    printf("\nPressione ENTER para continuar...");
                    while (getchar() != '\n');
                    tecla = '\n';
                } while (tecla != '\n');
                limparTela();
            }

        }while(isValid != 1);

        // pedir a produção media em kg/mes
        limparTela();
        printf("Digite a quantidade média em kg por mês produzida: ");
        scanf("%f", &a[i].producaoMel);
        limparBuffer();

        id++;

        a[i].id = id;

    }
    // quantidade é somado com a quantidade de novas abelhas
    qtdAbelhas++;
}

int contAbelhas(){
    return qtdAbelhas;
}

// implementação da função para listar todas as abelhas
void listarTodas(Abelha a[])
{
    showListarTodas();

    if(qtdAbelhas != 0){
        for (int i = 0; i < qtdAbelhas; i++)
        {
            printf("ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n\n", a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
        }
    }else{
        limparTela();
        printf("* !!! Nenhuma abelha cadastrada !!! *\n\n");
    }
    printf("\nPressione ENTER para sair...");
    while (getchar() != '\n');
    limparTela();
}

void buscarPorNomePopular(Abelha a[])
{
    
    if(qtdAbelhas == 0){
        limparTela();
        showBuscarPorNomePopular();
        printf("* !!! Nenhuma abelha cadastrada !!! *\n");

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n');
        return;
    }

    char nomePopular[40], tecla;

    // inicializo a variavel como falsa (método da negação)
    int achou = 0;

    // pede o nome da abelha para buscar e lê com fgets para reconhecer espaços
    limparTela();
    showBuscarPorNomePopular();
    printf("Digite o nome popular da abelha que você quer buscar: ");
    fgets(nomePopular, sizeof(nomePopular), stdin);
    nomePopular[strcspn(nomePopular, "\n")] = '\0';

    for (int i = 0; i < qtdAbelhas; i++)
    {
        // compara o nome popular digitado com o nome popular das abelhas disponiveis
        if (strcmp(nomePopular, a[i].nomePopular) == 0)
        {
            printf("\nID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n\n", a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
            achou = 1;
        }
    }

    // retorna que não achou a abelha se a variavel "achou" continuar falsa
    if (achou == 0)
    {
        printf("\n* !!! Abelha não encontrada !!! *\n");
    }

    do
    {
        printf("\nPressione ENTER para sair...");
        while (getchar() != '\n');
        tecla = '\n';
    } while (tecla != '\n');
    limparTela();
}

void editarAbelha(Abelha a[]){
    showEditarAbelhas();

    if(qtdAbelhas == 0){
        char op;
        printf("* !!! Nenhuma abelha cadastrada !!! *\n");
        do
        {
            printf("\nPressione ENTER para continuar...");
            while (getchar() != '\n');
            op = '\n';
        } while (op != '\n');
        limparTela();
        return;
    }

    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    int idDaAbelha, isExistent = 0;

    printf("Digite o id da abelha que deseja editar: ");
    scanf("%d", &idDaAbelha);
    limparBuffer();

    int oqEditar;
    limparTela();
    printf("+---------------------------------+\n");
    printf("|            SELECIONE            |\n");
    printf("+---------------------------------+\n");
    printf("|   1 - Nome popular              |\n");
    printf("|   2 - Nome cientifico           |\n");
    printf("|   3 - Região                    |\n");
    printf("|   4 - Qtd de mel produzido/mes  |\n");
    printf("+---------------------------------+\n");
    printf("-> ");
    scanf("%d", &oqEditar);
    limparBuffer();

    limparTela();

    if(oqEditar == 1){
        for(int i = 0; i < qtdAbelhas; i++){
            printf("Aguarde...\n");
            sleep(1);
            limparTela();

            // compara o id digitado com os ids das abelhas
            if(a[i].id == idDaAbelha){
                // editar o nome popular
                printf("Digite o nome popular da abelha: ");
                fgets(a[i].nomePopular, sizeof(a[i].nomePopular), stdin);
                a[i].nomePopular[strcspn(a[i].nomePopular, "\n")] = '\0';
                isExistent = 1;
            }
        }
    }else if(oqEditar == 2){
        for(int i = 0; i < qtdAbelhas; i++){
            printf("Aguarde...\n");
            sleep(1);
            limparTela();

            // compara o id digitado com os ids das abelhas
            if(a[i].id == idDaAbelha){
                // editar o nome popular
                printf("Digite o nome cientifico: ");
                fgets(a[i].nomeCientifico, sizeof(a[i].nomeCientifico), stdin);
                a[i].nomeCientifico[strcspn(a[i].nomeCientifico, "\n")] = '\0';
                isExistent = 1;
            }
        }
    }else if(oqEditar == 3){
        char tecla;
        for(int i = 0; i < qtdAbelhas; i++){
            if(a[i].id == idDaAbelha){
                int opcaoRegiao, isValid = 0;
                do{
                    limparTela();
                    printf("+---------------------------------+\n");
                    printf("|            SELECIONE            |\n");
                    printf("+---------------------------------+\n");
                    printf("|   1 - Norte                     |\n");
                    printf("|   2 - Nordeste                  |\n");
                    printf("|   3 - Centro-oeste              |\n");
                    printf("|   4 - Sudeste                   |\n");
                    printf("|   5 - Sul                       |\n");
                    printf("+---------------------------------+\n");
                    printf("-> ");
                    scanf("%d", &opcaoRegiao);
                    limparBuffer();

                    limparTela();

                    for(int j = 1; j <= 5; j++){
                        if(opcaoRegiao == j){
                            strcpy(a[i].regiao, regioes[j - 1]);
                            isValid = 1;
                        }
                    }

                    if(isValid == 0){
                        printf("* !!! Região inválida, tente novamente !!! *\n");
                        do
                        {
                            printf("\nPressione ENTER para continuar...");
                            while (getchar() != '\n');
                            tecla = '\n';
                        } while (tecla != '\n');
                        limparTela();
                    }
                    
                }while(isValid != 1);
                isExistent = 1;
            }
        }
    }else if(oqEditar == 4){
        // editar a produção media em kg/mes
        for(int i = 0; i < qtdAbelhas; i++){
            if(a[i].id == idDaAbelha){
                printf("Digite a quantidade média em kg por mês produzida: ");
                scanf("%f", &a[i].producaoMel);
                limparBuffer();
                isExistent = 1;
            }
        }
    }
    if(isExistent == 0){
        printf("\n * !!! Abelha não encontrada !!! *.\n");
        limparTela();
        return;
    }else{
        printf("\nDados editados com sucesso!\n\n");
        
        printf("Pressione ENTER para continuar...");
        while(getchar() != '\n');
        limparTela();
    }
}

void removerAbelha(Abelha a[]){
    limparTela();
    showRemoverAbelhas();

    if(qtdAbelhas == 0){
        printf("* !!! Nenhuma abelha cadastrada !!! *\n");

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n');
        limparTela();
        return;
    }

    limparTela();

    int idDaAbelha;
    
    printf("Digite o id da abelha a remover: ");
    scanf("%d", &idDaAbelha);
    limparBuffer();
    
    int indice = -1;
    for(int j = 0; j < qtdAbelhas; j++){
        if(a[j].id == idDaAbelha){
            indice = j;
            break;
        }
    }

    if(indice == -1){
        printf("* !!! Abelha com id %d não encontrada !!! *\n", idDaAbelha);
    } else {
        for(int j = indice; j < qtdAbelhas - 1; j++){
            a[j] = a[j + 1];
        }
        
        qtdAbelhas--;
        printf("Abelha removida com sucesso!\n");
    }

    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    limparTela();

}
