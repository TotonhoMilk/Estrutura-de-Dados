#include <stdio.h>

// I - DECLARAÇÃO -------------------------------------------------
// Definição da estrutura da Lista
#define TAMANHO 10
typedef struct {
  int qtd_elem;
  int dados[TAMANHO];
} Lista;

// II - OPERAÇÕES -------------------------------------------------
// a) Inicialização
void inicia_lista(Lista *lista) { lista->qtd_elem = 0; }

// b) Acessar elemento
int acessa_elemento(Lista *lista, int indice) {
  if ((indice < 0) || (indice > lista->qtd_elem - 1) ||
      (lista->qtd_elem > TAMANHO - 1)) {
    printf("Erro! Elemento fora dos limites\n");
  } else {
    return lista->dados[indice];
  }
  return -1;
}

// c) Alterar elemento
void alterar_elemento(Lista *lista, int indice, int dado) {
  if ((indice < 0) || (indice > lista->qtd_elem - 1)) {
    printf("Erro! Elemento fora dos limites\n");
  } else {
    lista->dados[indice] = dado;
  }
}

// d) Inserir no local
void inserir_elemento_indice(Lista *lista, int indice, int dado) {
  if ((indice < 0) || (indice > lista->qtd_elem - 1) ||
      (lista->qtd_elem > TAMANHO - 1)) {
    printf("Erro! Elemento fora dos limites\n");
  } else {
    for (int i = lista->qtd_elem; i > indice; i--) {
      lista->dados[i] = lista->dados[i - 1];
    }
    lista->dados[indice] = dado;
    lista->qtd_elem++;
  }
}

// e) Inserir no final
void inserir_elemento_final(Lista *lista, int dado) {
  if (lista->qtd_elem > TAMANHO - 1) {
    printf("Erro! A lista não tem mais espaço\n");
  } else {
    lista->dados[lista->qtd_elem] = dado;
    lista->qtd_elem++;
  }
}

// f) Remover no local
void remover_elemento_indice(Lista *lista, int indice) {
  if ((indice < 0) || (indice > lista->qtd_elem - 1)) {
    printf("Erro! Elemento fora dos limites\n");
  } else {
    for (int i = indice; i < lista->qtd_elem; i++) {
      lista->dados[i] = lista->dados[i + 1];
    }
    lista->qtd_elem--;
  }
}

// g) Remover do final
void remover_elemento_final(Lista *lista) {
  if (lista->qtd_elem < 1) {
    printf("Erro! Lista vazia\n");
  } else {
    lista->qtd_elem--;
  }
}

// h) Remove todos os elementos da lista
void remover_tudo(Lista *lista) { lista->qtd_elem = 0; }

// III - ESPECIAIS --------------------------------------------
// a) Extração de sub-lista (do elemento inicio ao fim)
Lista sublista1(Lista *lista, int inicio, int fim) {
  Lista lista_aux;
  inicia_lista(&lista_aux);
  for (int i = 0; i < fim; i++) {
    inserir_elemento_final(&lista_aux, lista->dados[inicio]);
    inicio++;
  }
  return lista_aux;
}

// b) Extração de sub-lista sem dependencia da função inserir_elemento_final
Lista sublista2(Lista *lista, int inicio, int fim) {
  Lista lista_aux;
  inicia_lista(&lista_aux);
  for (int i = 0; i < fim; i++) {
    // inserir_elemento_final(&lista_aux, lista->dados[inicio]);
    lista_aux.dados[i] = lista->dados[inicio];
    inicio++;
    lista_aux.qtd_elem++;
  }
  return lista_aux;
}

// c) Concatena listas
void concateca_listas(Lista *lista1, Lista *lista2) {
  int vagas = 0;
  if (lista1->qtd_elem + lista2->qtd_elem <= TAMANHO) {
    vagas = lista2->qtd_elem;
  } else {
    vagas = TAMANHO - lista1->qtd_elem;
  }
  for (int i = 0; i < vagas; i++) {
    lista1->dados[lista1->qtd_elem] = lista2->dados[i];
    lista1->qtd_elem++;
  }
}

// d) Imprime lista
void imprime_lista(Lista *lista) {
  if (lista->qtd_elem < 1) {
    printf("Erro! Lista vazia\n");
  } else {
    for (int i = 0; i < lista->qtd_elem; i++) {
      printf("[%d]", lista->dados[i]);
    }
    printf("\n");
  }
}

int main() {
  printf("Estrutura de Dados - Lista\n\n");

  printf("Criar uma lista com 10 elementos\n");
  Lista l;
  inicia_lista(&l);
  for (int i = 0; i < TAMANHO; i++) {
    inserir_elemento_final(&l, i);
  }
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Apagar os 3 últimos elementos da lista\n");
  for (int i = 0; i < 3; i++) {
    remover_elemento_final(&l);
  }
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Remover o quarto elemento da lista\n");
  remover_elemento_indice(&l, 3);
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Inserir o elemento 111 na posição 3\n");
  inserir_elemento_indice(&l, 3, 111);
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Remover o último elemento da lista\n");
  remover_elemento_final(&l);
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Alterar o elemento da posição 3 para 999\n");
  alterar_elemento(&l, 3, 999);
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Obtem sub-lista pela função 1\n");
  Lista l1;
  inicia_lista(&l1);
  l1 = sublista1(&l, 1, 3);
  imprime_lista(&l1);
  printf("Quantidade de elementos: %d\n\n", l1.qtd_elem);

  printf("Obtem sub-lista pela função 2\n");
  Lista l2;
  inicia_lista(&l2);
  l2 = sublista2(&l, 1, 3);
  imprime_lista(&l2);
  printf("Quantidade de elementos: %d\n\n", l2.qtd_elem);

  printf("Concatenar duas listas\n");
  printf("Lista 1 --> ");
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);
  Lista l3;
  inicia_lista(&l3);
  for (int i = 0; i < 4; i++) {
    inserir_elemento_final(&l3, i + 6);
  }
  printf("Lista 2 --> ");
  imprime_lista(&l3);
  printf("Quantidade de elementos: %d\n\n", l3.qtd_elem);
  concateca_listas(&l, &l3);
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  printf("Apaga todos os elementos da lista\n");
  remover_tudo(&l);
  imprime_lista(&l);
  printf("Quantidade de elementos: %d\n\n", l.qtd_elem);

  return 0;
}
