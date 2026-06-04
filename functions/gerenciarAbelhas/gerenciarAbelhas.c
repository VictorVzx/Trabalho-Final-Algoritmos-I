#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "gerenciarAbelhas.h"

// incluir a função de limpar buffer
#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

//incluir a interface de listar todas
#include "../../interfaces/gerenciarAbelhas/gerenciarAbelhasInterface.h"

#include "../../structs/structs.h"

int qtd;

void cadastrarAbelha(Abelha a[], int sys){
    // mostra interface de cadastrar abelhas
    showCadastrarAbelhas();

    //pergunta a quantidade de abelhas antes de adicionar
    printf("Quantas abelhas voce quer cadastrar?: ");
    scanf("%d", &qtd);
    limparBuffer();

    int id = 0;
    
    for(int i = 0; i < qtd; i++){
        limparTela(sys);
        showCadastrarAbelhas();
        sleep(1);
        printf("======== %dª ABELHA ========\n", i+1);
        
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
    
}

void listarTodas(Abelha a[], int sys){
    showListarTodas();

    char tecla;

    for(int i = 0; i < qtd; i++){
        printf("ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n\n", a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
    }
    do{
        printf("\nPressione ENTER para sair...");
        while(getchar() != '\n');
        tecla = '\n';
    }while(tecla != '\n');
    limparTela(sys);
}

void editarAbelhas(){

}