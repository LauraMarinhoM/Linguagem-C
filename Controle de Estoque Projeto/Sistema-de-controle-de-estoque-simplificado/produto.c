// funções relacionadas ao produto (Modulo 1)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "produto.h"
#include "utilitarios.h"



// Declaração do vetor de quantidades


void incluirProduto(Produto estoque[], int indiceProduto){

    // verifica se o maximo de produtos foi atingido
    if (indiceProduto < MAX_PRODUTOS)
    {
        char nomeTemp[TAM_MAX_NOME_PRODUTO];
        int nomeExiste;

        do
        {
            nomeExiste = 0; // Reseta a variável para cada nova tentativa de inclusão

            printf("Digite o nome do produto: ");
            fgets(nomeTemp, TAM_MAX_NOME_PRODUTO, stdin);
            nomeTemp[strcspn(nomeTemp, "\n")] = 0;

            // Verifica se o nome já existe no estoque
            for (int i = 0; i < indiceProduto; i++) {
            if (estoque[i].ativo && strcmp(estoque[i].nome, nomeTemp) == 0) {
                nomeExiste = 1;
                break;
            }
            }

            if (nomeExiste) {
                printf("Erro: já existe um produto com esse nome no estoque.\n");
            }
        } while (nomeExiste == 1);


        // Copia o nome validado para o estoque
        strcpy(estoque[indiceProduto].nome, nomeTemp);

        printf("Digite a quantidade: ");
        scanf("%d", &estoque[indiceProduto].quantidade);

        printf("Digite o preco: ");
        scanf("%f", &estoque[indiceProduto].preco);

        estoque[indiceProduto].ativo = 1;
        estoque[indiceProduto].id = indiceProduto + 1;


    }else
    {
        printf("O quantidade maxima de produtos foi atingida!");
    }


}


void excluirProduto(Produto estoque[], int idDoProdutoParaExcluir){
    int encontrado = 0;

    // O ID do produto é o índice + 1. Então o índice é ID - 1.
    int indice = idDoProdutoParaExcluir - 1;

    // Valida se o índice está dentro dos limites e se o produto está ativo
    if (indice >= 0 && indice < MAX_PRODUTOS && estoque[indice].id == idDoProdutoParaExcluir && estoque[indice].ativo == 1) {
        estoque[indice].ativo = 0; // Apenas marca como inativo
        printf("Produto '%s' (ID: %d) foi excluído com sucesso.\n", estoque[indice].nome, idDoProdutoParaExcluir);
        encontrado = 1;
    }

    if (encontrado == 0) {
        printf("Erro: Produto com ID %d não encontrado ou já está inativo.\n", idDoProdutoParaExcluir);
    }
}



void listarProdutos(Produto estoque[], int indiceProduto){

    printf("Lista de produtos cadastrados\n");
    printf("\n");

    if(indiceProduto == 0){
        printf("Nenhum produto cadastrado ainda\n");
    }else{

        // Percorre o vetor até o último produto cadastrado
        for(int i = 0; i < indiceProduto; i++){
            printf("ID: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f | Situacao: %s\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco, estoque[i].ativo ? "Ativo" : "Inativo");
        }
    }
}

void atualizarEstoque(Produto estoque[], int indiceProduto){

    int id_produto;
    int qnt_movimento;

    printf("Atualizar estoque\n");
    printf("\n");
    printf("Digite o ID do produto que deseja atualizar:");
    scanf("%d", &id_produto);
    limparBufferEntrada();


    // Validação: verifica se o ID é válido (está dentro dos limites dos produtos cadastrados)
    if(id_produto >= 0 && id_produto < (indiceProduto + 1)  ){
        id_produto = id_produto - 1; // Ajusta o ID para o índice do vetor
        printf("Produto selecionado: %s\n", estoque[id_produto].nome);
        printf("Estoque atual: %d\n", estoque[id_produto].quantidade);
        printf("Digite a quantidade a ser selecionada ou removida: ");
        scanf("%d", &qnt_movimento);
        limparBufferEntrada();
    }


    // Validação: impede que o estoque se torne negativo
    if((estoque[id_produto].quantidade + qnt_movimento) >= 0){
        estoque[id_produto].quantidade = estoque[id_produto].quantidade + qnt_movimento;
        printf("Estoque atualizado com sucesso! Novo estoque: %d\n", estoque[id_produto].quantidade);
    }else{
        printf("Erro:Operacao invalida! O estoque nao pode ficar negativo\n");
    }
}

void buscarProduto(Produto estoque[], int indiceProduto){


    // Implementação simplificada da busca por nome (conter texto)
   char texto[TAM_MAX_NOME];
   int id_busca;
   char *encontrado = NULL;
   int verificar;



   printf("Buscar produto\n");
   printf("\n");
   printf("Digite o ID ou parte do nome do produto\n");
   scanf("%s", texto);
   limparBufferEntrada();

   verificar = sscanf(texto,"%d", &id_busca);


    // Tenta converter o termo para um número para checar se é um ID
    if(verificar == 1){

       printf("Produto encontrado por ID\n");
       printf("ID: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f\n", id_busca, estoque[id_busca].nome, estoque[id_busca].quantidade, estoque[id_busca].preco);

    }else{

       // Se não encontrou por ID, busca por nome
        for(int i = 0; i < indiceProduto; i++){

            encontrado = strstr(estoque[i].nome, texto);

            if(encontrado){

               printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
            }

        }

    }

}

void calcularValorTotal(Produto estoque[], int indiceProduto){
    float valor_total_estoque = 0.0;
    float valor_produto_atual;

    for(int i = 0; i < indiceProduto; i++){

        valor_produto_atual = estoque[i].quantidade * estoque[i].preco;
        valor_total_estoque = valor_total_estoque + valor_produto_atual;
    }

    printf("Valor total estoque:\n");
    printf("\n");
    printf("Valor total de todos os produtos em estoque: R$ %.2f\n", valor_total_estoque);


}

void relatorioEstoqueBaixo(Produto estoque[], int indiceProduto){

    int limite_estoque;
    bool encontrou_item_abaixo = false;

    printf("Relatorio de estoque baixo\n");
    printf("\n");
    printf("Digite a quantidade limite para considerar o estoque baixo (ex: 5)\n");
    scanf("%d", &limite_estoque);
    limparBufferEntrada();
    printf("\n");

    printf("Produtos com estoque igual ou inferior a %d:\n", limite_estoque);

    for(int i = 0; i < indiceProduto; i++){
        if(estoque[i].quantidade <= limite_estoque){
            printf("ALERTA | ID: %d | Nome: %s | Estoque atual: %d\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade);

            encontrou_item_abaixo = true;

        }
    }

    if(encontrou_item_abaixo == false){
        printf("Nenhum produto com estoque baixo encontrado.\n");
    }
}
