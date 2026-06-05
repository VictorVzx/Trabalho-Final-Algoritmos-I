#ifndef GERENCIARABELHAS_H
#define GERENCIARABELHAS_H

#include "../../structs/structs.h"

// prototipo das funções CRUD (abelhas)

//prototipo da função cadastrarAbelha
void cadastrarAbelha(Abelha a[], int sys);

//prototipo da função de listar abelhas
void listarTodas(Abelha a[], int sys);

// prototipo da função de buscar por nome popular
void buscarPorNomePopular(Abelha a[], int sys);

//prototipo da função de editar abelhas
void editarAbelha(Abelha a[], int sys);

//prototipo da função de remover abelhas
void removerAbelha(Abelha a[], int sys);

#endif