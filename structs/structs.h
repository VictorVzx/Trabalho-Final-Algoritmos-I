#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_ABELHAS 50
#define MAX_SENSORES 100

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