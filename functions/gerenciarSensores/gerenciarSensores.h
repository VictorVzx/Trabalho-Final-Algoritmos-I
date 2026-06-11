#ifndef GERENCIARSENSORES_H
#define GERENCIARSENSORES_H

#include "../../structs/structs.h"

void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas);

int qtdSensoresTemperatura(Sensor s[]);

void listarSensores(Sensor s[]);

void buscarSensorPorIdAbelha(Sensor s[]);

void alterarLeitura(Sensor s[], Abelha a[], int qtdAbelhas);

void removerSensor(Sensor s[]);

#endif