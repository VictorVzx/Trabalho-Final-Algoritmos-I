#ifndef STRUCTS_H
#define STRUCTS_H

// todas as structs ficam armazenadas aqui.

typedef struct{
    int id;
    char nomePopular[40];
    char nomeCientifico[50];
    char regiao[30];
    float producaoMel;
} Abelha;

typedef struct{
    int id;
    char tipo[30];
    float valor;
    int idAbelha;
} Sensor;

#endif