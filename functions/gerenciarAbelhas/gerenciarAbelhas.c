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

int qtdAbelhas, novasAbelhas;

void cadastrarAbelha(Abelha a[])
{
    // mostra interface de cadastrar abelhas
    showCadastrarAbelhas();

    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    char tecla;
    novasAbelhas = 0;

    // pergunta a quantidade de abelhas antes de adicionar
    printf("Quantas abelhas voce quer cadastrar?: ");
    scanf("%d", &novasAbelhas);
    limparBuffer();

    if(qtdAbelhas + novasAbelhas > 50){
        printf("Não pode ter mais do que 50 abelhas.\n\n");
        do
        {
            printf("\nPressione ENTER para sair...");
            while (getchar() != '\n');
            tecla = '\n';
        } while (tecla != '\n');
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
        printf("======== %dª ABELHA ========\n", i + 1);

        // pedir o nome popular
        printf("Digite o nome popular da abelha: ");
        fgets(a[i].nomePopular, sizeof(a[i].nomePopular), stdin);
        a[i].nomePopular[strcspn(a[i].nomePopular, "\n")] = '\0';

        // pedir o nome cientifico
        printf("Digite o nome cientifico: ");
        fgets(a[i].nomeCientifico, sizeof(a[i].nomeCientifico), stdin);
        a[i].nomeCientifico[strcspn(a[i].nomeCientifico, "\n")] = '\0';

        // pedir a regiao

        int opcaoRegiao, isValid = 0;
        do{
            limparTela();
            printf("==== Região ====\n1 - Norte\n2 - Nordeste\n3 - Centro-oeste\n4 - Sudeste\n5 - Sul\n-> ");
            scanf("%d", &opcaoRegiao);
            limparBuffer();

            for(int j = 1; j <= 5; j++){
                if(opcaoRegiao == j){
                    strcpy(a[i].regiao, regioes[j - 1]);
                    isValid = 1;
                }
            }

            if(isValid == 0){
                printf("Região inválida, tente novamente.\n");
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
        printf("Digite a quantidade média em kg por mês produzida: ");
        scanf("%f", &a[i].producaoMel);
        limparBuffer();

        id++;

        a[i].id = id;

    }
    // quantidade é somado com a quantidade de novas abelhas
    qtdAbelhas += novasAbelhas;
}

int contAbelhas(){
    return qtdAbelhas;
}

// implementação da função para listar todas as abelhas
void listarTodas(Abelha a[])
{
    showListarTodas();

    char tecla;

    if(qtdAbelhas != 0){
        for (int i = 0; i < qtdAbelhas; i++)
        {
            printf("ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n\n", a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
        }
    }else{
        printf("Nenhuma abelha cadastrada\n\n");
    }
    do
    {
        printf("\nPressione ENTER para sair...");
        while (getchar() != '\n');
        tecla = '\n';
    } while (tecla != '\n');
    limparTela();
}

void buscarPorNomePopular(Abelha a[])
{
    showBuscarPorNomePopular();

    if(qtdAbelhas == 0){
        char op;
        printf("Nenhuma abelha cadastrada\n");
        do
        {
            printf("\nPressione ENTER para continuar...");
            while (getchar() != '\n');
            op = '\n';
        } while (op != '\n');
        limparTela();
        return;
    }

    char nomePopular[40], tecla;

    // inicializo a variavel como falsa (método da negação)
    int achou = 0;

    // pede o nome da abelha para buscar e lê com fgets para reconhecer espaços
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
        printf("\nAbelha não encontrada.\n");
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
        printf("Nenhuma abelha cadastrada\n");
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
    printf("==== O que você deseja editar? ====\n1 - Nome Popular\n2 - Nome Cientifico\n3 - Região\n4 - Quantidade em kg/mes\n-> ");
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
                    printf("==== Região ====\n1 - Norte\n2 - Nordeste\n3 - Centro-oeste\n4 - Sudeste\n5 - Sul\n-> ");
                    scanf("%d", &opcaoRegiao);
                    limparBuffer();

                    for(int j = 1; j <= 5; j++){
                        if(opcaoRegiao == j){
                            strcpy(a[i].regiao, regioes[j - 1]);
                            isValid = 1;
                        }
                    }

                    if(isValid == 0){
                        printf("Região inválida, tente novamente.\n");
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
        printf("\nAbelha não encontrada.\n");
        limparTela();
        return;
    }
}

void removerAbelha(Abelha a[]){
    limparTela();
    showRemoverAbelhas();

    if(qtdAbelhas == 0){
        char op;
        printf("Nenhuma abelha cadastrada\n");
        do
        {
            printf("\nPressione ENTER para continuar...");
            while (getchar() != '\n');
            op = '\n';
        } while (op != '\n');
        limparTela();
        return;
    }

    int qtdDeAbelhasParaDeletar = 0;

    printf("Digite a quantidade de abelhas para deletar: ");
    scanf("%d", &qtdDeAbelhasParaDeletar);
    limparBuffer();

    limparTela();

    int idDaAbelha[qtdDeAbelhasParaDeletar];
    
    // lê o id da(s) abelha(s) e deleta pelo id
    for(int i = 0; i < qtdDeAbelhasParaDeletar; i++){
        sleep(1);
        printf("Digite o id da %dª abelha: ", i+1);
        scanf("%d", &idDaAbelha[i]);
        limparBuffer();
    }
    
    for(int i = 0; i < qtdDeAbelhasParaDeletar; i++){
        int indice = -1;
        for(int j = 0; j < qtdAbelhas; j++){
            if(a[j].id == idDaAbelha[i]){
                indice = j;
                break;
            }
        }

        if(indice == -1){
            printf("Abelha com id %d não encontrada.\n", idDaAbelha[i]);
            continue;
        }

        for(int j = indice; j < qtdAbelhas - 1; j++){
            a[j] = a[j + 1];
        }
        
        qtdAbelhas--;
    }

}
