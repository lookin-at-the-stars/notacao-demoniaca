#include <stdbool.h>

typedef struct TStack {
    int *pilha;
    int curr_size;
    int max_size;

} Stack;

typedef struct {
    char *pilha;
    int curr_size;
    int max_size;
} StackChar;

Stack* CriaStack(int tamanho);

void DestroiStack(Stack *s);

bool isEmpty(Stack *s);

bool isFull(Stack *s);

int topo(Stack *s);

int sizeElements(Stack *s);

bool push(Stack *s, int elemento);

int pop(Stack *s);

StackChar* CriaStackChar(int tamanho);

void DestroiStackChar(StackChar *s);

bool isEmptyChar(StackChar *s);

bool isFullChar(StackChar *s);

char topoChar(StackChar *s);

int sizeElementsChar(StackChar *s);

bool pushChar(StackChar *s, char elemento);

char popChar(StackChar *s);
