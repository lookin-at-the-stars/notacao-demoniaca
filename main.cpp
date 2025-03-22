#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.hpp"

bool estaNoConjuntoChar(char conjunto[], int tamanho, char elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (conjunto[i] == elemento) {
            return true; // Elemento encontrado
        }
    }
    return false; // Elemento não encontrado
}

// Função para obter a prioridade do operador
int prioridade(char operador) {
    switch (operador) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0; // Parênteses ou caracteres inválidos
    }
}

int main() {
    char *texto = (char *)malloc(100 * sizeof(char));
    if (!texto) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite a Expressão Infixa que deseja operar: ");
    scanf("%s", texto);
    printf("Expressão digitada: %s\n", texto);

    char *saida = (char *)malloc(100 * sizeof(char));
    if (!saida) {
        printf("Erro ao alocar memória!\n");
        free(texto);
        return 1;
    }

    StackChar *pilhaop = CriaStackChar(50);
    int j = 0; 

    for (int i = 0; texto[i] != '\0' && texto[i] != '\n'; i++) {
        char c = texto[i];

        // Se for uma variável (A-Z), vai direto para a saída
        if (c >= 'A' && c <= 'Z') {
            saida[j++] = c; 
        } 
        // Se for um operador, verificar prioridade
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!isEmptyChar(pilhaop) && prioridade(topoChar(pilhaop)) >= prioridade(c)) {
                saida[j++] = popChar(pilhaop);
            }
            pushChar(pilhaop, c);
        } 
        // Se for um parêntese esquerdo, empilha
        else if (c == '(') {
            pushChar(pilhaop, c);
        }
        // Se for um parêntese direito, desempilha até encontrar o '('
        else if (c == ')') {
            while (!isEmptyChar(pilhaop) && topoChar(pilhaop) != '(') {
                saida[j++] = popChar(pilhaop);
            }
            popChar(pilhaop); // Remove o '('
        }
        else if (c != ' ') { 
            printf("Operação ou nome de variável inválidos!\n");
            return 0;
        }
    }

    // Esvaziar a pilha no final
    while (!isEmptyChar(pilhaop)) {
        saida[j++] = popChar(pilhaop);
    }

    saida[j] = '\0'; 
    printf("Expressão Pós-Fixa: %s\n", saida);

    // Liberar memória
    free(texto);
    free(saida);
    DestroiStackChar(pilhaop);

    return 0;
}
