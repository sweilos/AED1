#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char data[100];  // Tamanho máximo da string
    struct No* next;
} No;

typedef struct {
    No* front;
} No_Fila;

No_Fila* criarNo_Fila() {
    No_Fila* fila = (No_Fila*)malloc(sizeof(No_Fila));
    if (fila == NULL) {
        fprintf(stderr, "Erro ao alocar memria.\n");
        exit(1);
    }
    fila->front = NULL;
    return fila;
}

int estaVazia(No_Fila* fila) {
    return fila->front == NULL;
}

void enfileirar(No_Fila* fila, const char* valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memoria\n");
        exit(1);
    }

    strcpy(novoNo->data, valor);
    novoNo->next = NULL;

    if (estaVazia(fila)) {
        fila->front = novoNo;
    } else {
        No* atual = fila->front;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo;
    }
}


void mostrar(No_Fila* fila) {
    No* atual = fila->front;
    while (atual != NULL) {
        printf("%s\n", atual->data);
        atual = atual->next;
    }
}


