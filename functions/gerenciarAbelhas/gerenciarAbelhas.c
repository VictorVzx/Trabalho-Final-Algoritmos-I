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

int qtd, novasAbelhas;

void cadastrarAbelha(Abelha a[], int sys)
{
    // mostra interface de cadastrar abelhas
    showCadastrarAbelhas();

    char tecla;
    novasAbelhas = 0;

    // pergunta a quantidade de abelhas antes de adicionar
    printf("Quantas abelhas voce quer cadastrar?: ");
    scanf("%d", &novasAbelhas);
    limparBuffer();

    if(qtd > 50){
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

    int id = 0;

    // loop vai da quantidade atual de abelhas até a nova quantidade que o usuario deseja registrar
    for (int i = qtd; i < qtd + novasAbelhas; i++)
    {
        limparTela(sys);
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
        printf("Digite a região: ");
        fgets(a[i].regiao, sizeof(a[i].regiao), stdin);
        a[i].regiao[strcspn(a[i].regiao, "\n")] = '\0';

        // pedir a produção media em kg/mes
        printf("Digite a quantidade média em kg por mês produzida: ");
        scanf("%f", &a[i].producaoMel);
        limparBuffer();

        id++;

        a[i].id = id;
        id = a[i].id;

    }
    qtd += novasAbelhas;
}

void listarTodas(Abelha a[], int sys)
{
    showListarTodas();

    char tecla;

    for (int i = 0; i < qtd; i++)
    {
        printf("ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n\n", a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
    }
    do
    {
        printf("\nPressione ENTER para sair...");
        while (getchar() != '\n');
        tecla = '\n';
    } while (tecla != '\n');
    limparTela(sys);
}

void buscarPorNomePopular(Abelha a[], int sys)
{
    showBuscarPorNomePopular();
    char nomePopular[40], tecla;

    // inicializo a variavel como falsa (método da negação)
    int achou = 0;

    // pede o nome da abelha para buscar e lê com fgets para reconhecer espaços
    printf("Digite o nome popular da abelha que você quer buscar: ");
    fgets(nomePopular, sizeof(nomePopular), stdin);
    nomePopular[strcspn(nomePopular, "\n")] = '\0';

    for (int i = 0; i < qtd; i++)
    {
        // compara o nome popular digitado com o nome popular das abelhas disponiveis
        if (strcmp(nomePopular, a[i].nomePopular) == 0)
        {
            printf("ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n\n", a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
            achou = 1;
        }
    }

    // retorna que não achou a abelha se a variavel "achou" continuar falsa
    if (achou == 0)
    {
        printf("Abelha não encontrada.\n");
    }

    do
    {
        printf("\nPressione ENTER para sair...");
        while (getchar() != '\n');
        tecla = '\n';
    } while (tecla != '\n');
    limparTela(sys);
}

void removerAbelha(Abelha a[], int sys, int *qtd, int indice){
    limparTela(sys);
    showRemoverAbelhas();
    

}
