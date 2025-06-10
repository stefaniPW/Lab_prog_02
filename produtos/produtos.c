#include <stdio.h>
#include <string.h>
#include "produtos.h"


#define QTD_PRODUTOS 100

Produto produtos [QTD_PRODUTOS];
int index_produto = 0;
void insere_produtos(){
    int opcao;
    if (index_produto >= QTD_PRODUTOS){
        printf ("Limite de produtos atingido!\n\n");
    }else{
        printf ("insira o nome do produto: \t");
        scanf("%s", produtos[index_produto].nome);
        printf ("insira o preço do produto: \t");
        scanf("%lf", produtos[index_produto].preco);
        index_produto++;
        printf("Deseja inserir mais produtos?\n");
        printf("1 - SIM\n");
        printf("2 - NÃO\n");
        scanf("%d", &opcao);
        if (opcao == 1){
            insere_produtos();
        }
    }
}


void listar_produtos(){
    int j;
    for (j = 0; j < index_produto; j++){
        printf("Produtos %d - nome: %s\n\n", (j+1), produtos[j].nome);
        printf("Produtos %d - preço: %lf\n\n", (j+1), produtos[j].preco);
    }
}


void excluir_produtos(){
    char nome[100];
    listar_produtos();
    printf("Digite o nome do produto a ser removido:");
    scanf("%s", nome);
    int j = 0;
    while (strcmp(produtos[j].nome, nome) != 0 ){
        j++;
    }
    strcpy(produtos[j].nome, "");
    strcpy(produtos[j].nome, "");
    index_produto--;
    printf("Quantidade de produtos cadastrados: %d\n", index_produto);
}



void altera_produtos(){
    char nome [100];
    listar_produtos();
    printf("Digite o produto a ser editado: ");
    scanf("%s", nome);
    int j = 0;
    while (strcmp(produtos[j].nome, nome) != 0 ){
        j++;
    }
    printf("Insira o nome editado: ");
    scanf ("%s", produtos[j].nome, nome);
}

