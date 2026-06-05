#ifndef GERENCIARABELHAS_H
#define GERENCIARABELHAS_H

#include "../../structs/structs.h"

// prototipo das funções CRUD (abelhas)

//prototipo da função cadastrarAbelha
void cadastrarAbelha(Abelha a[]);

// prototipo da função do contador abelhas
int contAbelhas();

//prototipo da função de listar abelhas
void listarTodas(Abelha a[]);

// prototipo da função de buscar por nome popular
void buscarPorNomePopular(Abelha a[]);

//prototipo da função de editar abelhas
void editarAbelha(Abelha a[]);

//prototipo da função de remover abelhas
void removerAbelha(Abelha a[]);

#endif