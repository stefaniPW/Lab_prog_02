#include <stdio.h>
#include "vendas.h"
#include "../clientes/clientes.h"
#include "../produtos/produtos.h"

#define MAX_VENDAS 100
Venda vendas[MAX_VENDAS];
int ultima_venda_cadastrada = 0;

void gerar_venda() {
    listar_clientes();
    int id_cliente;
    printf("Informe o ID do cliente: ");
    scanf("%d", &id_cliente);

    listar_produtos();
    int id_produto, quantidade;
    printf("Informe o ID do produto: ");
    scanf("%d", &id_produto);
    printf("Informe a quantidade: ");
    scanf("%d", &quantidade);

    if (id_cliente < 1 || id_cliente > index_cliente ||
        id_produto < 1 || id_produto > index_produto) {
        printf("ID de cliente ou produto invalido!\n");
        return;
    }

    ProdutoVenda prod_venda;
    prod_venda.id_produto = id_produto;
    prod_venda.quantidade = quantidade;

    double preco_unit = produtos[id_produto - 1].preco;
    double valor_total = preco_unit * quantidade;

    Venda nova_venda;
    nova_venda.id_nota_fiscal = ++ultima_venda_cadastrada;
    nova_venda.id_cliente = id_cliente;
    nova_venda.produtos[0] = prod_venda;
    nova_venda.valor_total = valor_total;
    nova_venda.cancelada = 0;

    printf("Informe a data da venda (ex: 20250627): ");
    scanf("%d", &nova_venda.data_simulada);

    vendas[ultima_venda_cadastrada - 1] = nova_venda;

    printf("Venda registrada com sucesso! ID: %d\n", nova_venda.id_nota_fiscal);
}

void listar_vendas() {
    printf("Vendas registradas:\n");
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].cancelada) continue;
        printf("ID: %d | Cliente ID: %d | Total: R$ %.2f | Data: %d\n",
               vendas[i].id_nota_fiscal,
               vendas[i].id_cliente,
               vendas[i].valor_total,
               vendas[i].data_simulada);
    }
}

void cancelar_venda() {
    int id;
    printf("Digite o ID da venda para cancelar: ");
    scanf("%d", &id);

    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (vendas[i].id_nota_fiscal == id && !vendas[i].cancelada) {
            vendas[i].cancelada = 1;
            printf("Venda %d cancelada com sucesso!\n", id);
            return;
        }
    }
    printf("Venda nao encontrada ou ja cancelada.\n");
}

void relatorio_por_periodo() {
    int data_inicio, data_fim;
    printf("Digite a data inicial (ex: 20250601): ");
    scanf("%d", &data_inicio);
    printf("Digite a data final (ex: 20250630): ");
    scanf("%d", &data_fim);

    float total_faturado = 0;
    int total_vendas = 0;

    printf("Relatorio de vendas entre %d e %d:\n", data_inicio, data_fim);
    for (int i = 0; i < ultima_venda_cadastrada; i++) {
        if (!vendas[i].cancelada &&
            vendas[i].data_simulada >= data_inicio &&
            vendas[i].data_simulada <= data_fim) {
            printf("ID: %d | Cliente ID: %d | Total: R$ %.2f | Data: %d\n",
                   vendas[i].id_nota_fiscal,
                   vendas[i].id_cliente,
                   vendas[i].valor_total,
                   vendas[i].data_simulada);
            total_vendas++;
            total_faturado += vendas[i].valor_total;
        }
    }

    printf("\nResumo: %d vendas | Faturamento total: R$ %.2f\n", total_vendas, total_faturado);
}