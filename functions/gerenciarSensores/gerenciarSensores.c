// #include <stdio.h>
// #include <unistd.h>

// #include "gerenciarSensores.h"

// #include "../../interfaces/gerenciarSensores/gerenciarSensoresInterface.h"
// #include "../limparBuffer/limparBuffer.h"
// #include "../limparTela/limparTela.h"

// #include "../../structs/structs.h"


// int qtd, novosSensores;

// void cadastrarSensor(Sensor s[])
// {
//     // mostra interface de cadastrar abelhas
//     showCadastrarSensores();

//     char tecla;
//     novosSensores = 0;

//     // pergunta a quantidade de abelhas antes de adicionar
//     printf("Quantos sensores voce quer cadastrar?: ");
//     scanf("%d", &novosSensores);
//     limparBuffer();

//     if(qtd > 100){
//         printf("Não pode ter mais do que 100 sensores.\n\n");
//         do
//         {
//             printf("\nPressione ENTER para sair...");
//             while (getchar() != '\n');
//             tecla = '\n';
//         } while (tecla != '\n');
//         novosSensores = 0;
//         return;
//     }

//     // id é inicializado com a quantidade atual de sensores
//     int id = qtd;

//     // loop vai da quantidade atual de sensores até a nova quantidade que o usuario deseja registrar
//     for (int i = qtd; i < qtd + novosSensores; i++)
//     {
//         limparTela();
//         showGerenciarSensores();
//         sleep(1);
//         printf("======== %dº SENSOR ========\n", i + 1);


//         id++;

//         s[i].id = id;

//     }
//     // quantidade é somado com a quantidade de novas abelhas
//     qtd += novosSensores;
// }

// void listarSensores(Sensor s[]);

// void buscarSensorPorIdAbelha(Sensor s[]);

// void alterarLeitura(Sensor s[]);

// void removerSensor(Sensor s[]);
