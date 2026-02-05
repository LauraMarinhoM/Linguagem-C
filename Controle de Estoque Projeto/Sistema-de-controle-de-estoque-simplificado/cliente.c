// funções relacionadas ao cliente (Modulo 2)

#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "utilitarios.h"



// função para incluir um cliente
void incluirCliente(Cliente cliente[], int indiceCliente){
    int valido = 1;

    if (indiceCliente < MAX_CLIENTES){
        // loop enquanto o nome estiver vazio
        do {
            printf("Digite o nome do cliente: ");
            fgets(cliente[indiceCliente].nome, TAM_MAX_NOME, stdin);
            cliente[indiceCliente].nome[strcspn(cliente[indiceCliente].nome, "\n")] = 0;

            if (strlen(cliente[indiceCliente].nome) == 0) {
                printf("Nome invalido. Por favor, digite um nome valido.\n");
            }

        } while (strlen(cliente[indiceCliente].nome) == 0);

        // loop enquanto o CPF for inválido
        do
        {
            // Lê o CPF do cliente
            printf("Digite seu cpf (Apenas numeros): ");
            fgets(cliente[indiceCliente].cpf, 14, stdin);
            cliente[indiceCliente].cpf[strcspn(cliente[indiceCliente].cpf, "\n")] = '\0';

            valido = validarCPF(cliente, indiceCliente); // chama a função para validar CPF

            if (valido == 0) {
                printf("CPF invalido ou ja cadastrado. Tente novamente.\n");
            }

        } while (valido == 0);

    }
    
}

// função para listar os clientes
void listarClientes(Cliente cliente[], int indiceCliente) {
    printf("Clientes cadastrados:\n");

    for (int i = 0; i < indiceCliente; i++)
    {
        printf("CPF: %s | Nome: %s | Total de Compras: %d\n", cliente[i].cpf, cliente[i].nome, cliente[i].totalCompras);
    }
}


