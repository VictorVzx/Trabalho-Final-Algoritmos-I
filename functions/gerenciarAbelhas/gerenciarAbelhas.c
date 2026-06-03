#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "gerenciarAbelhas.h"

#include "../limparBuffer/limparBuffer.h"
#include "../limparTela/limparTela.h"

#include "../../structs/structs.h"


void cadastrarAbelha(Abelha a[], int sys){

    //pergunta a quantidade de abelhas antes de adicionar
    int qtd;
    printf("Quantas abelhas voce quer cadastrar?: ");
    scanf("%d", &qtd);
    limparBuffer();
    
    for(int i = 0; i < qtd; i++){
        limparTela(sys);
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
    }
    
}