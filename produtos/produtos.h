
#ifndef PRODUTOS_H
#define PRODUTOS_H

void insere_produtos();
void listar_produtos();

typedef struct {
    char nome [100];
    double preco;
    int ID;
}Produto;


#endif //PRODUTOS_H


