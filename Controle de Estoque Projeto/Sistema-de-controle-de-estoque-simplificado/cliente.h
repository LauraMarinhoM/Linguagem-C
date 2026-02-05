#ifndef CLIENTE_H
#define CLIENTE_H

#define TAM_MAX_NOME 100
#define MAX_CLIENTES 50

typedef struct
{
    char cpf[14];
    char nome[TAM_MAX_NOME];
    int totalCompras;
}Cliente;



// colocar as funçoes do cliente aqui
void incluirCliente(Cliente cliente[], int indiceCliente);
void listarClientes(Cliente cliente[], int indiceCliente);

#endif
