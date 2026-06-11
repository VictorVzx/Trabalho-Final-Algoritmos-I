#ifndef GERENCIARRELATORIOS_H
#define GERENCIARRELATORIOS_H

// CABEÇALHO DAS FUNÇÕES DE RELATORIO

// INCLUI AS STRUCTS PARA PASSAR COMO PARAMETRO
#include "../../structs/structs.h"

// CABEÇALHO DA FUNÇÃO DE PRODUÇÃO MEDIA DE MEL
void producaoMediaMel(Abelha a[]);

// CABEÇALHO DA FUNÇÃO DA MEDIA DE TEMPERATURA DOS SENSORES
void mediaTemperaturaSensores(Sensor s[]);

// CABEÇALHO DA FUNÇÃO DE QUANTIDADE DE ABELHAS POR REGIAO
void qtdAbelhasPorRegiao(Abelha a[]);

// CABEÇALHO DA FUNÇÃO DE ALERTAS AMBIENTAIS
void alertasAmbientais(Sensor s[]);

#endif