#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100
#define TAM_MAX_NOME_PRODUTO 50

typedef struct
{
    int id;
    char nome[TAM_MAX_NOME_PRODUTO];
    int quantidade;
    float preco;
    int ativo; // 1 para ativados e 0 para desatidos
}Produto;


// colocar funçoes do produto aqui
void incluirProduto(Produto estoque[], int indiceProduto);
void excluirProduto(Produto estoque[], int idDoProdutoParaExcluir);
void listarProdutos(Produto estoque[], int indiceProduto);
void atualizarEstoque(Produto estoque[], int indiceProduto);
void buscarProduto(Produto estoque[], int indiceProduto);
void calcularValorTotal(Produto estoque[], int indiceProduto);
void relatorioEstoqueBaixo(Produto estoque[], int indiceProduto);


#endif
