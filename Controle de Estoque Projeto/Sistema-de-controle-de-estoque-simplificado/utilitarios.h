#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "cliente.h"

int validarCPF(Cliente cliente[], int indiceCliente);
void limparBufferEntrada();
void aguardarTecla();
int validarData(int dia, int mes, int ano);

#endif
