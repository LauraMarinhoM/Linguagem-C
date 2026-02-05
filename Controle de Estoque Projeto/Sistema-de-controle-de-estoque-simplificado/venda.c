// funçoes relacionadas a venda (Modulo 3)

#include <stdio.h>
#include <string.h>
#include "venda.h"
#include "utilitarios.h"

void incluirVenda(Venda vendas[], Cliente cliente[], Produto estoque[], int indiceVenda, int indiceCliente, int indiceProduto) {
    int valido = 1;
    int continuar = 1;
    int quantidadeVendida;
    char cpf[14];
    vendas[indiceVenda].numProdutos = 0; // Inicializa o número de produtos vendidos

    printf("Incluir Venda\n");

    if (indiceVenda < MAX_VENDAS){
        // loop enquanto a data for inválida
        do
        {
            printf("Digite a data da venda\n");
            printf("Dia: ");
            scanf("%d", &vendas[indiceVenda].dataVenda.dia);
            limparBufferEntrada();
            printf("Mes: ");
            scanf("%d", &vendas[indiceVenda].dataVenda.mes);
            limparBufferEntrada();
            printf("Ano: ");
            scanf("%d", &vendas[indiceVenda].dataVenda.ano);
            limparBufferEntrada();

        } while (validarData(vendas[indiceVenda].dataVenda.dia, vendas[indiceVenda].dataVenda.mes, vendas[indiceVenda].dataVenda.ano) == 0);


        do
        {

            printf("Digite o cpf do cliente (Apenas numeros): ");

            fgets(cpf, 14, stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            //verifica se o cpf é de um cliente cadastrado

            for (int i = 0; i < indiceCliente; i++)
            {
                if (strcmp(cliente[i].cpf, cpf) == 0)
                {
                    vendas[indiceVenda].idCliente = i; // Armazena o índice do cliente
                    valido = 1; // Marca como válido se encontrar o CPF
                    break;
                }
                else
                {
                    valido = 0; // Marca como inválido se não encontrar o CPF
                }
            }

            if (valido == 0)
            {
                printf("CPF nao cadastrado, tente novamente.\n");
            }


        } while (valido == 0);


        // loop para incluir os produtos vendidos
        do
        {

            printf("Digite o ID do produto vendido: ");
            scanf("%d", &vendas[indiceVenda].idProduto[vendas[indiceVenda].numProdutos]);

            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantidadeVendida);

            // Verifica se o produto existe no estoque
            for (int i = 0; i < indiceProduto; i++)
            {
                if (estoque[i].id == vendas[indiceVenda].idProduto[vendas[indiceVenda].numProdutos])
                {
                    // Verifica se há estoque suficiente e se o produto está ativo
                    if (estoque[i].quantidade >= quantidadeVendida && estoque[i].ativo == 1)
                    {
                        vendas[indiceVenda].idVenda = indiceVenda; // Atribui o ID da venda
                        estoque[i].quantidade -= quantidadeVendida; // Atualiza a quantidade no estoque
                        vendas[indiceVenda].numProdutos++; // Incrementa o número de produtos vendidos

                    }
                    else
                    {
                        printf("Estoque insuficiente para o produto ID %d. Ou o produto foi excluido\n", vendas[indiceVenda].idProduto[vendas[indiceVenda].numProdutos]);
                    }
                    break;
                }
            }

            printf("Deseja incluir mais produtos na venda? (1-Sim, 0-Nao): ");
            scanf("%d", &continuar);


        } while (continuar == 1);

        vendas[indiceVenda].idVenda = indiceVenda + 1; // Atribui o ID da venda
        cliente[vendas[indiceVenda].idCliente].totalCompras++; // Incrementa o total de compras do cliente

        printf("Venda incluida com sucesso!\n");

    }

}


// funcao para listar as vendas
void listarVendas(Venda vendas[], Cliente cliente[], Produto estoque[], int indiceVenda) {


    for (int i = 0; i < indiceVenda; i++)
    {
        printf("Venda ID: %d\n", vendas[i].idVenda);
        printf("Data da Venda: %d/%d/%d\n", vendas[i].dataVenda.dia, vendas[i].dataVenda.mes, vendas[i].dataVenda.ano);
        printf("Cpf do Cliente: %s\n", cliente[vendas[i].idCliente].cpf);
        printf("Nome do Cliente: %s\n", cliente[vendas[i].idCliente].nome);
        printf("Id dos Produto Vendido: \n");
        // looop para listar os produtos vendidos

        for (int j = 0; j < vendas[i].numProdutos; j++)
        {
            printf("ID Produto: %d\n", vendas[i].idProduto[j]);
            printf("Nome Produto: %s\n", estoque[vendas[i].idProduto[j] - 1].nome);
        }

    }


}
