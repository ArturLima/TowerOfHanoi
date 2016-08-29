typedef struct pilha Pilha;

Pilha * criar();
void destruir(Pilha * p);
void empilhar(Pilha * p, int x);
int desempilhar(Pilha * p);
int tamanho(Pilha * p);
int topo(Pilha * p);
void imprimir(Pilha * p);
