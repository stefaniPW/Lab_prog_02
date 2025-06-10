#ifndef CLIENTES_H
#define CLIENTES_H

void insere_clientes();
void listar_clientes ();
void excluir_clientes();
void altera_clientes();

typedef struct {
    char nome [100];
    char email [100];
    int ID;
}Cliente;


#endif //CLIENTES_H



