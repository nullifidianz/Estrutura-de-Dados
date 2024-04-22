#include <stdio.h>

#define LEN 10

typedef struct {
  int values[LEN];
  int n;
} list;

int is_full(list *l) { return l->n == LEN; }

int is_empty(list *l) { return l->n == 0; }

void show(list *l) {
  for (int i = 0; i < l->n; i++) {
    printf("%d ", l->values[i]);
  }
  printf("\n");
}

int get_idx(list *l, int value) {
  int idx = 0;
  while (idx < l->n && l->values[idx] < value)
    idx++;
  return idx;
}

void move(list *l, int idx) {
  for (int i = l->n; i > idx; i--) {
    l->values[i] = l->values[i - 1];
  }
}

int insert(list *l, int value) {
  if (is_full(l))
    return 0;

  int idx = 0;
  if (!is_empty(l)) {
    idx = get_idx(l, value);
    move(l, idx);
  }

  l->values[idx] = value;
  l->n++;
  show(l);  
  return 1; 
}

void move_remove(list *l, int idx) {
  for (int i = idx; i < l->n - 1; i++) {
    l->values[i] = l->values[i + 1];
  }
}

int _remove(list *l, int value) {
  if (is_empty(l))
    return 0;

  int idx = get_idx(l, value);
  move_remove(l, idx);
  l->n--;
  show(l);  
  return 1; 
}

int main(void) {
  list l;
  l.n = 0;
  list *pl = &l;
  int values[] = {21, 14, 13, 10, 87, 35, 27, 56, 85, 29};
  for (int i = 0; i < LEN; i++) {
    insert(pl, values[i]);
  }

  for (int i = 0; i < LEN; i++) {
    printf("O valor %d está na posição %d\n", values[i], get_idx(pl, values[i]));
  }

  for (int i = 0; i < LEN; i++) {
    _remove(pl, values[i]);
  }

  return 0;
}
