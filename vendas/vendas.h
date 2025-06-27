#ifndef VENDA_H
#define VENDA_H

typedef struct produto_venda {
    int id_produto;
    int quantidade;
} ProdutoVenda;

typedef struct venda {
    int id_nota_fiscal;
    int id_cliente;
    ProdutoVenda produtos[10];
    float valor_total;
    int data_simulada;  // ex: 20250627
    int cancelada; // 0 = ativa, 1 = cancelada
} Venda;

void gerar_venda();
void listar_vendas();
void cancelar_venda();
void relatorio_por_periodo();

#endif



