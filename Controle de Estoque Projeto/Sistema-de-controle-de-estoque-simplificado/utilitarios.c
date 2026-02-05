// para funções auxiliares, validações etc
#include <stdio.h>
#include <string.h>
#include "utilitarios.h"

// para validar CPF
int validarCPF(Cliente cliente[], int indiceCliente) {
    int valido;
    int soma, resto;

    valido = 1; // Resetar a validade para cada nova entrada

    // Verificar se ja existe um cliente com o mesmo CPF
    for (int i = 0; i < indiceCliente; i++) {
        if (strcmp(cliente[i].cpf, cliente[indiceCliente].cpf) == 0) {
            valido = 0; // CPF já cadastrado
            break;
        }
    }


   // Verificar se tem exatamente 11 dígitos
    if (strlen(cliente[indiceCliente].cpf) != 11) {
        valido = 0;
    }

    // Verificar se todos são números
    for (int i = 0; i < 11 && valido; i++) {
        if (cliente[indiceCliente].cpf[i] < '0' || cliente[indiceCliente].cpf[i] > '9') {
            valido = 0;
        }
    }

    // Verificar se todos os dígitos são iguais (ex: 11111111111)
    for (int i = 1; i < 11 && valido; i++) {
        if (cliente[indiceCliente].cpf[i] != cliente[indiceCliente].cpf[0]) {
            break;
        }
        if (i == 10) valido = 0;
    }

    // verificar o primeiro dígito verificador
    if (valido == 1)
    {
        soma = 0;
        for (int i = 0 , j = 10; i < 9; i++, j--)
        {
            soma += (cliente[indiceCliente].cpf[i] - '0') * j;
        }

        resto = (soma * 10) % 11;

        if (resto == 10 || resto == 11) resto = 0;
        if (resto != (cliente[indiceCliente].cpf[9] - '0')) valido = 0;
    }

    if (valido == 1)
    {
        // verificar o segundo dígito verificador
        soma = 0;
        for (int i = 0, j = 11; i < 10; i++, j--)
        {
            soma += (cliente[indiceCliente].cpf[i] - '0') * j;
        }

        resto = (soma * 10) % 11;

        if (resto == 10 || resto == 11) resto = 0;
        if (resto != (cliente[indiceCliente].cpf[10] - '0')) valido = 0;
    }

    return valido;

}


//Função que limpa o caminho para a próxima leitura

void limparBufferEntrada(){

    while (getchar() != '\n');

}

//Função que espera alguma tecla ser apertada, permitindo que o usuário tenha tempo de ler o conteúdo
void aguardarTecla(){

    getchar();

}

// funcao para validar a data
int validarData(int dia, int mes, int ano) {
    int valido = 1;

    // Verifica o ano
    if (ano < 1900 || ano > 2100) {
        valido = 0;
    }

    // Verifica o mês
    if (mes < 1 || mes > 12) {
        valido = 0;
    }

    // Verifica o dia
    if (dia < 1 || dia > 31) {
        valido = 0;
    }

    // Verifica meses com menos de 31 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        valido = 0;
    }

    // Verifica fevereiro
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            if (dia > 29) valido = 0;
        } else {
            if (dia > 28) valido = 0;
        }
    }

    return valido;
}
