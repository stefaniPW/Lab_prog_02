#include <stdio.h>
#include <string.h>
#include "clientes.h"

#define QTD_CLIENTE 100
int index_cliente = 0;
Cliente clientes [QTD_CLIENTE];

void insere_clientes(){
    int opcao;
    if (index_cliente >= QTD_CLIENTE){
        printf("Limite de clientes atingido!\n\n");
    }else{
        int i = 0;
        while (strcmp(clientes[i].nome, "") != 0 ){
            i++;
        }
        printf("insira o nome do cliente: \t");
        scanf("%s", clientes[i].nome);
        printf("insira o e-mail do cliente: \t");
        scanf("%s", clientes[i].email);

        index_cliente++;
        clientes[i].ID = index_cliente;

        printf("Deseja inserir mais clientes?\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &opcao);
        if (opcao == 1){
            insere_clientes();
        }
    }
}


void listar_clientes (){ //listas = imprimi-r
    int i = 0;
    while (strcmp(clientes[i].nome, "")) {
        printf("Cliente %d - nome: %s\n\n", (i+1), clientes[i].nome);
        printf("Cliente %d - email: %s\n\n",(i+1), clientes[i].email);
        i++;
    }
}


void excluir_clientes(){
    char nome[100];
    listar_clientes();
    printf("Digite o nome do cliente a ser removido:");
    scanf("%s", nome);
    int i = 0;
    while (strcmp(clientes[i].nome, nome) != 0 ){
        i++;
    }
    strcpy(clientes[i].nome, "");
    strcpy(clientes[i].email, "");
    index_cliente--;
    printf("Quantidade de clientes cadastrados: %d\n", index_cliente);
}


void altera_clientes(){
    char nome [100];
    listar_clientes ();
    printf("Digite o nome do cliente a ser editado: ");
    scanf("%s", nome);
    int i = 0;
    while (strcmp(clientes[i].nome, nome) != 0 ){
        i++;
    }
    printf("Insira o nome editado: ");
    scanf ("%s", clientes[i].nome, nome);
}

