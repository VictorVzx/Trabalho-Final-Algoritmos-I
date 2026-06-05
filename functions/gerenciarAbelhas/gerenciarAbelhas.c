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

    // id é inicializado com a quantidade atual de abelhas (o ID da abelha 50 seria 50)
    int id = qtd;

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

    }
    // quantidade é somado com a quantidade de novas abelhas
    qtd += novasAbelhas;
}

// implementação da função para listar todas as abelhas
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
    limparTela(sys);
}

void editarAbelha(Abelha a[], int sys){
    showEditarAbelhas();
    int qtdParaEditar = 0;

    printf("Digite quantas abelhas você quer editar: ");
    scanf("%d", &qtdParaEditar);
    limparBuffer();

    int idDaAbelha[qtdParaEditar], isExistent = 0;

    for(int i = 0; i < qtdParaEditar; i++){
        printf("Digite o id da abelha que deseja editar: ");
        scanf("%d", &idDaAbelha[i]);
        limparBuffer();
    }

    limparTela(sys);

    for(int i = 0; i < qtd; i++){
        printf("Aguarde...\n");
        sleep(1);
        limparTela(sys);

        // compara o id digitado com os ids das abelhas
        if(a[i].id == idDaAbelha[i]){
            // editar o nome popular
            printf("Digite o nome popular da abelha: ");
            fgets(a[i].nomePopular, sizeof(a[i].nomePopular), stdin);
            a[i].nomePopular[strcspn(a[i].nomePopular, "\n")] = '\0';

            // editar o nome cientifico
            printf("Digite o nome cientifico: ");
            fgets(a[i].nomeCientifico, sizeof(a[i].nomeCientifico), stdin);
            a[i].nomeCientifico[strcspn(a[i].nomeCientifico, "\n")] = '\0';

            // editar a regiao
            printf("Digite a região: ");
            fgets(a[i].regiao, sizeof(a[i].regiao), stdin);
            a[i].regiao[strcspn(a[i].regiao, "\n")] = '\0';

            // editar a produção media em kg/mes
            printf("Digite a quantidade média em kg por mês produzida: ");
            scanf("%f", &a[i].producaoMel);
            limparBuffer();

            isExistent = 1;
        }
    }
    if(isExistent == 0){
        printf("\nAbelha não encontrada.\n");
        return;
    }
}

void removerAbelha(Abelha a[], int sys){
    limparTela(sys);
    showRemoverAbelhas();

    int qtdDeAbelhasParaDeletar = 0;

    printf("Digite a quantidade de abelhas para deletar: ");
    scanf("%d", &qtdDeAbelhasParaDeletar);
    limparBuffer();

    limparTela(sys);

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
        for(int j = 0; j < qtd; j++){
            if(a[i].id == idDaAbelha[i]){
                indice = j;
                break;
            }
        }

        if(indice == -1){
            printf("Abelha com id %d não encontrada.\n", idDaAbelha[i]);
            continue;
        }

        for(int j = indice; j < qtd; j++){
            a[j] = a[j + 1];
        }
        
        qtd--;
    }

}
