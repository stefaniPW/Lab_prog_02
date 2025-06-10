#include <stdio.h>
#include "vendas.h"
#include "./clientes.h"
#include "./produtos.h"

int ultima_venda_cadastrada = 0;
void insere_vendas() {
    listar_clientes();

    int id_cliente;
    printf("Informe o ID do cliente: \n");
    scanf("%d", &id_cliente);

    listar_produtos();
    ProdutoVenda produto_venda;

    printf("Informe o ID do produto: \n");
    scanf("%d", &produto_venda.id_produto);
    printf("Informe a quantidade do produto: \n");
    scanf("%d", &produto_venda.quantidade);


    ultima_venda_cadastrada++;
    Venda venda;
    venda.id_nota_fiscal = ultima_venda_cadastrada;
    venda.id_cliente = id_cliente;
    venda.produtos[0] = produto_venda;
    venda.valor_total =

    printf("");
}

