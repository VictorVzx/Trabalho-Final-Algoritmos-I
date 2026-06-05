#ifndef GERENCIARSENSORES_H
#define GERENCIARSENSORES_H

#include "../../structs/structs.h"

void cadastrarSensor(Sensor s[], int sys);

void listarSensores(Sensor s[], int sys);

void buscarSensorPorIdAbelha(Sensor s[], int sys);

void alterarLeitura(Sensor s[], int sys);

void removerSensor(Sensor s[], int sys);

#endif