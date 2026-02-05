#ifndef VENDA_H
#define VENDA_H

#include "produto.h"
#include "cliente.h"

#define MAX_VENDAS 100

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    int idCliente; // IDs dos clientes que realizaram a compra
    int idProduto[MAX_PRODUTOS]; // IDs dos produtos vendidos
    int idVenda; // ID da venda
    Data dataVenda;
    int numProdutos; // Número de produtos vendidos
}Venda;



void incluirVenda(Venda vendas[], Cliente cliente[], Produto estoque[], int indiceVenda, int indiceCliente, int indiceProduto);
void listarVendas(Venda vendas[], Cliente cliente[], Produto estoque[], int indiceVenda);

#endif
