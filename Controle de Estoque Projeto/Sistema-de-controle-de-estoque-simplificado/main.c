// programa principal

#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "cliente.h"
#include "venda.h"
#include "utilitarios.h"

int main(){


    // Variável para controlar o índice do produto
    int indiceProduto = 0;

    // Variável para controlar o índice do cliente
    int indiceCliente = 0;

    // Variável para controlar o índice da venda
    int indiceVenda = 0;

    Produto estoque[MAX_PRODUTOS];
    Cliente cliente[MAX_CLIENTES];
    Venda vendas[MAX_VENDAS];

    int opcao, opcaoSubmenu;
    int idParaExcluir;
    int pode_excluir; // Variável para controlar se o produto pode ser excluído

    do
    {
        printf("Menu Principal:\n");
        printf("1 - Produtos\n");
        printf("2 - Clientes\n");
        printf("3 - Vendas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        system("cls");

        switch (opcao)
        {
        case 1:

            printf("Menu de Produtos:\n");
            printf("1 - Incluir Produto\n");
            printf("2 - Excluir Produto\n");
            printf("3 - Listar Produtos\n");
            printf("4 - Atualizar Estoque\n");
            printf("5 - Buscar Produto\n");
            printf("6 - Calcular Valor Total Do Estoque\n");
            printf("7 - Relatorio De Estoque Baixo\n");
            printf("0 - Sair\n");
            scanf("%d", &opcaoSubmenu);
            limparBufferEntrada();

            switch (opcaoSubmenu)
            {
            case 1:

                //Função Incluir produto
                incluirProduto(estoque, indiceProduto);
                indiceProduto++; // Incrementa o índice de produtos após a inclusão do produto
                break;

            case 2 :

                printf("Digite o ID do produto que deseja excluir: ");
                scanf("%d", &idParaExcluir);
                limparBufferEntrada();

                pode_excluir = 1; // Reseta a variável para cada tentativa de exclusão

                // Verifica se o produto está vinculado a alguma venda
                for (int i = 0; i < indiceVenda; i++) {
                    for (int j = 0; j < vendas[i].numProdutos; j++) {
                        if (vendas[i].idProduto[j] == idParaExcluir) {
                            pode_excluir = 0; // Encontrou o produto numa venda, não pode excluir
                            break;
                        }
                    }
                    if (pode_excluir == 0) {
                        break;
                    }
                }

                if (pode_excluir == 1) {
                    // Se pode excluir, chama a função simplificada
                    excluirProduto(estoque, idParaExcluir);
                } else {
                    printf("Erro: Este produto esta vinculado a uma venda e nao pode ser excluido.\n");
                }

                break;

            case 3 :

                //Função Listar produto
                listarProdutos(estoque, indiceProduto);
                break;

            case 4 :

                //Função Atualizar estoque
                atualizarEstoque(estoque, indiceProduto);
                break;

            case 5 :

                //Função Buscar produto
                buscarProduto(estoque, indiceProduto);
                break;

            case 6 :

                //Função Calcular Valor Total do estoque
                calcularValorTotal(estoque, indiceProduto);
                break;

            case 7 :

                //Função Relatorio de Estoque Baixo
                relatorioEstoqueBaixo(estoque, indiceProduto);
                break;

            case 8 :

                //Função Sair do programa
                printf("Saindo...");
                break;



            default:
                break;
            }

            break;

        case 2:

            printf("1 - Incluir Cliente\n");
            printf("2 - Listar Clientes\n");
            printf("0 - Sair\n");
            scanf("%d", &opcaoSubmenu);
            limparBufferEntrada();

            switch (opcaoSubmenu)
            {
            case 1 :

                //Função incluir clientes
                incluirCliente(cliente, indiceCliente);
                indiceCliente++; // Incrementa o índice de clientes após a inclusão do cliente
                break;

            case 2 :

                //Função Listar clientes
                listarClientes(cliente, indiceCliente);
                break;

            case 3 :

                //Função Sair do programa
                printf("Saindo...");
                break;

            default:
                break;
            }

            break;

        case 3:

            printf("1 - Incluir Venda\n");
            printf("2 - Listar Vendas\n");
            printf("0 - Sair\n");
            scanf("%d", &opcaoSubmenu);
            limparBufferEntrada();

            switch (opcaoSubmenu)
            {
            case 1 :

                //Função Incluir vendas
                incluirVenda(vendas, cliente, estoque, indiceVenda, indiceCliente, indiceProduto);
                indiceVenda++; // Incrementa o índice de vendas após a inclusão da venda
                break;

            case 2 :

                //Função Listar vendas
                listarVendas(vendas, cliente, estoque, indiceVenda);
                break;

            case 3 :

                //Função sair do programa
                printf("Saindo...");
                break;

            default:
                break;
            }

            break;

        case 0:
            printf("Saindo...");
            break;
        default:

            printf("Opcao invalida");
            break;
        }

    } while (opcao != 0);

    return 0;

}
