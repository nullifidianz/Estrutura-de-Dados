#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int valores;
    struct celula *prox;
    struct celula *anterior;
} celula;

typedef struct pilha
{
    celula *topo;
    int qtd;
} pilha;

celula *inicia_celula(int valor)
{
    celula *c = malloc(sizeof(celula));
    c->anterior = NULL;
    c->valores = valor;
    c->prox = NULL;
    return c;
}

pilha *inicia_pilha()
{
    pilha *p = malloc(sizeof(pilha));
    p->topo = NULL;
    p->qtd = 0;
    return p;
}

int pilha_vazia(pilha *p) { return p->qtd == 0; }

void push(pilha *p, int valor)
{
    celula *c = inicia_celula(valor);
    if (!pilha_vazia(p))
    {
        c->prox = p->topo;
        p->topo->anterior = c;
        p->topo = c;
    }
    p->topo = c;
    p->qtd++;
}

int pop(pilha *p)
{
    int valor = p->topo->valores;
    celula *c = p->topo;
    if (!pilha_vazia(p))
    {
        p->topo->prox->anterior = NULL;
        p->topo = p->topo->prox;
        p->qtd--;
        free(c);
        return valor;
    }
    else
    {
        return -1;
    }
}

void mostra_pilha(pilha *p)
{
    celula *c = p->topo;
    printf("\nTOPO\n");
    for (int i = 0; i < p->qtd; i++)
    {
        printf("%d\n", c->valores);
        c = c->prox;
    }
    printf("Base\n");
    printf("\n");
}

int main(void)
{
    pilha *p = inicia_pilha();
    for (int i = 0; i < 10; i++)
    {
        push(p, i);
        mostra_pilha(p);
    }
    for (int i = p->qtd; i > 0; i--)
    {
        printf("Valor removido: %d\n", pop(p));
        mostra_pilha(p);
    }
    return 0;
}