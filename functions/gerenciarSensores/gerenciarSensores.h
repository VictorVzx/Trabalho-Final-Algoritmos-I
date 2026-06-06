#ifndef GERENCIARSENSORES_H
#define GERENCIARSENSORES_H

#include "../../structs/structs.h"

void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas);

void listarSensores(Sensor s[], int qtdAbelhas);

void buscarSensorPorIdAbelha(Sensor s[]);

void alterarLeitura(Sensor s[]);

void removerSensor(Sensor s[]);

#endif