#include <stdio.h>
#include <stdlib.h>

#define CAP 6
typedef struct
{
    int valores[6];
    int topo;
} pilha;

pilha *inicializa_pilha()
{
    pilha *p = malloc(sizeof(pilha));
    p->topo = 0;
    return p;
}

int pilha_cheia(pilha *p) { return p->topo == CAP; }

int push(pilha *p, int valor)
{
    if (!pilha_cheia(p))
    {
        p->valores[p->topo++] = valor;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_vazia(pilha *p) { return p->topo == 0; }

int pop(pilha *p)
{
    if (!pilha_vazia(p))
    {
        return p->valores[--p->topo];
    }
    else
    {
        return -1;
    }
}

void mostrarpilha(pilha *p)
{
    printf("TOPO\n");
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("%d\n", p->valores[i]);
    }
    printf("BASE\n");
}

int main(void)
{
    pilha *p = inicializa_pilha();
    push(p, 1);
    push(p, 3);
    push(p, 5);
    push(p, 7);
    push(p, 9);
    push(p, 11);
    mostrarpilha(p);
    printf("valor removido: %d\n", pop(p));
    printf("valor removido: %d\n", pop(p));
    mostrarpilha(p);
    return 0;
}