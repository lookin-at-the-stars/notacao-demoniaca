#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

Stack* CriaStack(int tamanho) {
    Stack *aux; /* começo com um ponteiro, que será o retorno */
    aux = (Stack*) malloc(sizeof(Stack)); /* aloco a estrutura */
    aux->pilha = (int*) malloc((size_t)tamanho * sizeof(int)); /* aloco o vetor pilha */
    aux->curr_size = -1; /* tamanho default da pilha vazia: -1 */
    aux->max_size = tamanho; /* tamanho máximo: o recebido como parâmetro */
    return aux;
}

void DestroiStack(Stack *s) {
    free(s->pilha);
    free(s);
}

bool isEmpty(Stack *s) {
    if (s->curr_size == -1)
        return true;
    return false;
}

bool isFull(Stack *s) {
    if (s->curr_size+1 == s->max_size)
        return true;
    return false;
}


int topo(Stack *s) {
    if (isEmpty(s)) {
        printf("Pilha vazia!");
        return -1;
    }
    return s->pilha[s->curr_size];
}

int sizeElements(Stack *s) {
    return s->curr_size + 1;
}

/* coloquei um retorno so pra indicar o sucesso
   da operação:
       -false indica que não foi possível adicionar
       -true indica que foi adicionado com sucesso */
bool push(Stack *s, int elemento) {
    if (isFull(s)) {
        printf("Elemento %d não adicionado. Motivo: pilha cheia!\n", elemento);
        return false;
    }
    s->curr_size++;
    s->pilha[s->curr_size] = elemento;
    return true;
}

int pop(Stack *s) {
    /* pede para topo mostrar o elemento que será removido */
    int elementoRemovido = topo(s);
    /* se de fato a pilha não está vazia (elemento não é -1)
        então vamos decrementar seu tamanho */
    if (elementoRemovido != -1)
        s->curr_size--;
    return elementoRemovido;
}

StackChar* CriaStackChar(int tamanho) {
    StackChar *aux = (StackChar*) malloc(sizeof(StackChar));
    aux->pilha = (char*) malloc((size_t)tamanho * sizeof(char));
    aux->curr_size = -1;
    aux->max_size = tamanho;
    return aux;
}

void DestroiStackChar(StackChar *s) {
    free(s->pilha);
    free(s);
}

bool isEmptyChar(StackChar *s) {
    return s->curr_size == -1;
}

bool isFullChar(StackChar *s) {
    return s->curr_size + 1 == s->max_size;
}

char topoChar(StackChar *s) {
    if (isEmptyChar(s)) {
        printf("Pilha vazia!\n");
        return '\0';  // Retorna '\0' para indicar erro
    }
    return s->pilha[s->curr_size];
}

int sizeElementsChar(StackChar *s) {
    return s->curr_size + 1;
}

bool pushChar(StackChar *s, char elemento) {
    if (isFullChar(s)) {
        printf("Elemento '%c' não adicionado. Motivo: pilha cheia!\n", elemento);
        return false;
    }
    s->curr_size++;
    s->pilha[s->curr_size] = elemento;
    return true;
}

char popChar(StackChar *s) {
    char elementoRemovido = topoChar(s);
    if (elementoRemovido != '\0') // Se a pilha não está vazia
        s->curr_size--;
    return elementoRemovido;
}