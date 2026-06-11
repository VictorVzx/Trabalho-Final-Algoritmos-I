#ifndef GERENCIARSENSORES_H
#define GERENCIARSENSORES_H

// INCLUI STRUCTS PARA PASSAR COMO PARAMETRO
#include "../../structs/structs.h"

// PROTOTIPO DA FUNÇÃO DE CADASTRAR SENSOR
void cadastrarSensor(Sensor s[], Abelha a[], int qtdAbelhas);

// PROTOTIPO DA FUNÇÃO DE CONTAR SENSORES
int contSensores();

// PROTOTIPO DA FUNÇÃO DE CONTAR OS SENSORES DE TEMPERATURA
int qtdSensoresTemperatura(Sensor s[]);

// PROTOTIPO DA FUNÇÃO DE LISTAR SENSORES
void listarSensores(Sensor s[]);

// PROTOTIPO DA FUNÇÃO DE BUSCAR SENSORES POR ID DA ABELHA
void buscarSensorPorIdAbelha(Sensor s[]);

// PROTOTIPO DA FUNÇÃO DE ALTERAR LEITURA DE SENSORES
void alterarLeitura(Sensor s[], Abelha a[], int qtdAbelhas);

// PROTOTIPO DA FUNÇÃO DE REMOVER SENSORES
void removerSensor(Sensor s[]);

#endif