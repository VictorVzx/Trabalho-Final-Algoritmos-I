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

#include "../../interfaces/cores.h"

int qtdAbelhas = 0, novasAbelhas;

void cadastrarAbelha(Abelha a[])
{
    limparTela();
    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    // novas abelhas é hardcoded pois sempre vai adicionar apenas UMA abelha
    novasAbelhas = 1;

    if(qtdAbelhas + novasAbelhas > 50){
        limparTela();
        showCadastrarAbelhas();
        printf(RED BOLD "* !!! Não pode ter mais do que 50 abelhas !!! *\n\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
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

        // pedir o nome popular
        limparTela();
        showCadastrarAbelhas();
        printf(YELLOW BOLD "Digite o nome popular da abelha: " RESET);
        fgets(a[i].nomePopular, sizeof(a[i].nomePopular), stdin);
        a[i].nomePopular[strcspn(a[i].nomePopular, "\n")] = '\0';

        limparTela();
        showCadastrarAbelhas();
        printf(GREEN BOLD "Nome popular adicionado com sucesso!\n" RESET);
        
        printf(YELLOW "Pressione ENTER para continuar..." RESET);
        while(getchar() != '\n');

        // pedir o nome cientifico
        limparTela();
        showCadastrarAbelhas();
        printf(YELLOW BOLD "Digite o nome cientifico: " RESET);
        fgets(a[i].nomeCientifico, sizeof(a[i].nomeCientifico), stdin);
        a[i].nomeCientifico[strcspn(a[i].nomeCientifico, "\n")] = '\0';

        limparTela();
        showCadastrarAbelhas();
        printf(GREEN BOLD "Nome cientifico adicionado com sucesso!\n" RESET);
        
        printf(YELLOW "Pressione ENTER para continuar..." RESET);
        while(getchar() != '\n');

        // pedir a regiao

        int opcaoRegiao, isValid = 0;
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

        }while(isValid == 0);

        float mediaEmKgMes;

        // pedir a produção media em kg/mes
        do
        {
            limparTela();
            showCadastrarAbelhas();
            printf(YELLOW BOLD "Digite a quantidade média em kg por mês produzida: " RESET);
            scanf("%f", &mediaEmKgMes);
            limparBuffer();

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
    limparTela();
    showListarTodas();

    if(qtdAbelhas != 0){
        for (int i = 0; i < qtdAbelhas; i++)
        {
            printf(BOLD "ID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n" RESET, a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);
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

void buscarPorNomePopular(Abelha a[])
{
    limparTela();
    showBuscarPorNomePopular();
    if(qtdAbelhas == 0){
        limparTela();
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        return;
    }

    char nomePopular[40];

    // inicializo a variavel como falsa (método da negação)
    int achou = 0;

    // pede o nome da abelha para buscar e lê com fgets para reconhecer espaços
    limparTela();
    showBuscarPorNomePopular();
    printf(YELLOW BOLD "Digite o nome popular da abelha que você quer buscar: " RESET);
    fgets(nomePopular, sizeof(nomePopular), stdin);
    nomePopular[strcspn(nomePopular, "\n")] = '\0';

    for (int i = 0; i < qtdAbelhas; i++)
    {
        // compara o nome popular digitado com o nome popular das abelhas disponiveis
        if (strcmp(nomePopular, a[i].nomePopular) == 0)
        {
            printf(BOLD "\nID: %d\nNome cientifico: %s\nNome popular: %s\nRegião: %s\nMedia em kg/mes produzida: %.2f\n" RESET, a[i].id, a[i].nomeCientifico, a[i].nomePopular, a[i].regiao, a[i].producaoMel);

            printf(YELLOW "\nPressione ENTER para sair..." RESET);
            while(getchar() != '\n');
            achou = 1;
        }
    }

    // retorna que não achou a abelha se a variavel "achou" continuar falsa
    if (achou == 0)
    {
        limparTela();
        printf(RED BOLD "\n* !!! Abelha não encontrada !!! *\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while (getchar() != '\n');
    }


    limparTela();
}

void editarAbelha(Abelha a[]){
    limparTela();
    showEditarAbelhas();

    if(qtdAbelhas == 0){
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);
        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
        while (getchar() != '\n');
        limparTela();
        return;
    }

    char regioes[5][30] = {"Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul"};

    int idDaAbelha, isExistent = 0;

    printf(YELLOW BOLD "Digite o id da abelha que deseja editar: " RESET);
    scanf("%d", &idDaAbelha);
    limparBuffer();

    // loop para editar abelhas, só acaba quando uma das opções é valida
    int confirmarEdicao = 0;
    do{
        limparTela();
        printf("Tem certeza que deseja editar esta abelha?\n\n1 - Sim\n2 - Não\n\n-> ");
        scanf(confirmarEdicao);
        limparBuffer();
        if(confirmarEdicao == 2){
            limparTela();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf("\nPressione ENTER para sair...");
            while(getchar() != 0);
            return;
        }else if(confirmarEdicao == 1){
            limparTela();
        }else{
            limparTela();
            printf(RED BOLD "* !!! Opção inválida !!! *\n" RESET);
            printf("\nPressione ENTER para sair...");
            while(getchar() != 0);
            confirmarEdicao = 0;
        }
    }while(confirmarEdicao == 0);

    int oqEditar;
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
    scanf("%d", &oqEditar);
    limparBuffer();

    limparTela();

    if(oqEditar == 1){
        for(int i = 0; i < qtdAbelhas; i++){
            limparTela();

            char novoNomePopular[40];

            // compara o id digitado com os ids das abelhas
            if(a[i].id == idDaAbelha){
                // editar o nome popular
                do{
                    limparTela();
                    showEditarAbelhas();
                    printf(YELLOW BOLD "Digite o novo nome popular: " RESET);
                    fgets(novoNomePopular, sizeof(novoNomePopular), stdin);
                    novoNomePopular[strcspn(novoNomePopular, "\n")] = '\0';

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
                    
                }while(strcmp(novoNomePopular, a[i].nomePopular) == 0);
                isExistent = 1;
            }
        }
    }else if(oqEditar == 2){
        for(int i = 0; i < qtdAbelhas; i++){
            limparTela();

            // compara o id digitado com os ids das abelhas
            if(a[i].id == idDaAbelha){
                char novoNomeCientifico[50];

                // editar o nome popular
                do{
                    limparTela();
                    showEditarAbelhas();
                    printf(YELLOW BOLD "Digite o novo nome cientifico: " RESET);
                    fgets(novoNomeCientifico, sizeof(novoNomeCientifico), stdin);
                    novoNomeCientifico[strcspn(novoNomeCientifico, "\n")] = '\0';

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

                }while(strcmp(novoNomeCientifico, a[i].nomeCientifico) == 0);
                isExistent = 1;
            }
        }
    }else if(oqEditar == 3){

        for(int i = 0; i < qtdAbelhas; i++){
            if(a[i].id == idDaAbelha){
                int opcaoRegiao, isValid = 0;
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
                    scanf("%d", &opcaoRegiao);
                    limparBuffer();

                    if(opcaoRegiao < 1 || opcaoRegiao > 5){
                        limparTela();
                        showEditarAbelhas();
                        printf(RED BOLD "*!!! Opção inválida, tente novamente !!!*\n" RESET);
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
                        continue;
                    }


                    if (strcmp(a[i].regiao, regioes[opcaoRegiao - 1]) == 0) {
                        limparTela();
                        showEditarAbelhas();
                        printf(RED BOLD "* !!! Já é a região definida, tente novamente !!! *\n" RESET);
                        printf(YELLOW "\nPressione ENTER para continuar..." RESET);
                        while (getchar() != '\n');
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
        // editar a produção media em kg/mes
        for(int i = 0; i < qtdAbelhas; i++){
            float novaQtdMel;
            if(a[i].id == idDaAbelha){
                do{
                    limparTela();
                    showEditarAbelhas();
                    printf(YELLOW BOLD "Digite a quantidade média em kg por mês produzida: " RESET);
                    scanf("%f", &novaQtdMel);
                    limparBuffer();

                    do{
                        if(novaQtdMel == a[i].producaoMel){
                            limparTela();
                            showEditarAbelhas();
                            printf(RED BOLD "*!!! Já é a quantidade de mel definida, tente novamente !!!*\n" RESET);
    
                            printf(YELLOW "\nPressione ENTER para continuar." RESET);
                            while(getchar() != '\n');
                        }else{
                            limparTela();
                            printf(GREEN BOLD "* !!! Produção de mel editada com sucesso !!! *" RESET);

                            printf(YELLOW "\nPressione ENTER para continuar." RESET);
                            while(getchar() != '\n');
                            limparTela();
                            return;
                        }
                    }while(novaQtdMel == a[i].producaoMel);


                    if(novaQtdMel < 0){
                        limparTela();
                        showEditarAbelhas();
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
    if(isExistent == 0){
        limparTela();
        showEditarAbelhas();
        printf(RED BOLD "\n * !!! Abelha não encontrada !!! *.\n" RESET);

        printf(YELLOW "\nPressione ENTER para sair..." RESET);
        while (getchar() != '\n');

        return;
    }
}

void removerAbelha(Abelha a[]){
    limparTela();

    if(qtdAbelhas == 0){
        limparTela();
        showRemoverAbelhas();
        printf(RED BOLD "* !!! Nenhuma abelha cadastrada !!! *\n" RESET);

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n');
        limparTela();
        return;
    }

    int idDaAbelha;

    limparTela();
    showRemoverAbelhas();
    printf(YELLOW BOLD "Digite o id da abelha a remover: " RESET);
    scanf("%d", &idDaAbelha);
    limparBuffer();

    limparTela();

    int confirmar = 0;

    do{
        limparTela();
        showRemoverAbelhas();
        printf(RED BOLD "Deseja realmente remover abelha?" RESET RED BOLD "\n\n1 - Sim" RESET YELLOW BOLD "\n2 - Não\n\n" RESET);
        printf(YELLOW BOLD "-> " RESET);
        scanf("%d", &confirmar);
        limparBuffer();

        limparTela();
    
        if(confirmar == 1){
            continue;
        }else if(confirmar == 2){
            limparTela();
            printf(GREEN BOLD "* !!! Operação cancelada !!! *\n" RESET);

            printf(YELLOW "Pressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            return;
        }else{
            limparTela();
            printf(RED BOLD "* !!! Opção inválida, tente novamente !!! *\n" RESET);

            printf(YELLOW "Pressione ENTER para continuar..." RESET);
            while(getchar() != '\n');
            confirmar = 0;
        }

    }while(confirmar == 0);

    
    int indice = -1;
    for(int j = 0; j < qtdAbelhas; j++){
        if(a[j].id == idDaAbelha){
            indice = j;
            break;
        }
    }

    if(indice == -1){
        limparTela();
        showRemoverAbelhas();
        printf(RED BOLD "* !!! Abelha com id %d não encontrada !!! *\n" RESET, idDaAbelha);
    } else {
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
