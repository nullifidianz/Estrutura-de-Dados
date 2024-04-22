#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int valor;
  struct celula *anterior;
  struct celula *proximo;
} celula;

typedef struct ldde {
  int qtde;
  celula *primeiro;
} ldde;

ldde *criar_lista() {
  ldde *l = malloc(sizeof(ldde));
  l->primeiro = NULL;
  l->qtde = 0;
  return l;
}

celula *criar_celula(int valor) {
  celula *c = malloc(sizeof(celula));
  c->valor = valor;
  c->anterior = NULL;
  c->proximo = NULL;
  return c;
}

void inserir(ldde *l, int valor) {
  celula *novo = malloc(sizeof(celula));
  novo->valor = valor;
  novo->proximo = NULL;
  novo->anterior = NULL;

  if (l->primeiro == NULL) {
    l->primeiro = novo;
  } else {
    celula *atual = l->primeiro;
    celula *anterior = NULL;
    while (atual != NULL && atual->valor <= valor) {
      anterior = atual;
      atual = atual->proximo;
    }
    if (anterior == NULL) {
      novo->proximo = l->primeiro;
      l->primeiro = novo;
    } else {
      if (atual == NULL) {
        anterior->proximo = novo;
        novo->anterior = anterior;
      } else {
        novo->proximo = atual;
        anterior->proximo = novo;
        novo->anterior = anterior;
        atual->anterior = novo;
      }
    }
  }
  l->qtde++;
}

void mostrar(ldde *l) {
  celula *atual = l->primeiro;
  printf("início -> ");
  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("<- final \n");
}

void mostrar_invertido(ldde *l) {
  if (l->primeiro == NULL) {
    printf("final -> <- início \n");
    return;
  }

  celula *atual = l->primeiro;

  while (atual->proximo != NULL) {
    atual = atual->proximo;
  }

  printf("final -> ");
  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->anterior;
  }
  printf("<- início \n");
}

void remover(ldde *l, int valor) {
  if (l->primeiro == NULL) {
    return;
  }
  celula *atual = l->primeiro;

  while (atual != NULL && atual->valor != valor) {
    atual = atual->proximo;
  }

  if (atual == NULL) {
    return;
  }

  if (atual->anterior != NULL) {
    atual->anterior->proximo = atual->proximo;
  } else {
    l->primeiro = atual->proximo;
  }

  if (atual->proximo != NULL) {
    atual->proximo->anterior = atual->anterior;
  }

  free(atual);
  l->qtde--;
}

int main(void) {
  // não alterar essa função
  ldde *l = criar_lista();
  inserir(l, 10);
  inserir(l, 20);
  inserir(l, 15);
  mostrar(l);
  mostrar_invertido(l);
  for (int i = 0; i < 10; i++) {
    inserir(l, i + 1);
  }
  mostrar(l);
  mostrar_invertido(l);
  remover(l, 20);
  remover(l, 15);
  remover(l, 10);
  mostrar(l);
  mostrar_invertido(l);
  remover(l, 20);
  remover(l, 15);
  remover(l, 10);
  for (int i = 0; i < 10; i++) {
    remover(l, i + 1);
  }
  mostrar(l);
  mostrar_invertido(l);
  return 0;
}