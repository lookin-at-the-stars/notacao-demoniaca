#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

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
    char *texto = NULL;
    char *saida = NULL;
    int valores[26] = {0};
    bool valores_preenchidos[26] = {false};
    StackChar *pilhaop = NULL;

    int opcao;
    do {
        printf("\nMenu de Opções:\n");
        printf("1. Entrada da expressão aritmética na notação infixa\n");
        printf("2. Entrada dos valores numéricos associados às variáveis\n");
        printf("3. Conversão da expressão para notação pós-fixa\n");
        printf("4. Avaliação da expressão (a ser implementada)\n");
        printf("5. Encerramento do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: // Entrada da expressão aritmética na notação infixa
                if (texto) free(texto);
                texto = (char *)malloc(100 * sizeof(char));
                if (!texto) {
                    printf("Erro ao alocar memória!\n");
                    return 1;
                }
                printf("Digite a Expressão Infixa que deseja operar: ");
                scanf("%s", texto);
                printf("Expressão digitada: %s\n", texto);
                break;

            case 2: // Entrada dos valores numéricos associados às variáveis
                if (!texto) {
                    printf("Por favor, insira uma expressão infixa primeiro (opção 1).\n");
                    break;
                }
                for (int i = 0; texto[i] != '\0'; i++) {
                    char c = texto[i];
                    if (c >= 'A' && c <= 'Z') {
                        if (!valores_preenchidos[c - 'A']) {
                            printf("Digite um valor para a variável %c: ", c);
                            scanf("%d", &valores[c - 'A']);
                            valores_preenchidos[c - 'A'] = true;
                        }
                    }
                }
                printf("Valores associados às variáveis foram armazenados.\n");
                break;

            case 3: // Conversão da expressão para notação pós-fixa
                if (!texto) {
                    printf("Por favor, insira uma expressão infixa primeiro (opção 1).\n");
                    break;
                }
                if (saida) free(saida);
                saida = (char *)malloc(100 * sizeof(char));
                if (!saida) {
                    printf("Erro ao alocar memória!\n");
                    return 1;
                }
                if (pilhaop) DestroiStackChar(pilhaop);
                pilhaop = CriaStackChar(50);

                int j = 0;
                for (int i = 0; texto[i] != '\0' && texto[i] != '\n'; i++) {
                    char c = texto[i];

                    if (c >= 'A' && c <= 'Z') {
                        saida[j++] = c;
                    } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                        while (!isEmptyChar(pilhaop) && prioridade(topoChar(pilhaop)) >= prioridade(c)) {
                            saida[j++] = popChar(pilhaop);
                        }
                        pushChar(pilhaop, c);
                    } else if (c == '(') {
                        pushChar(pilhaop, c);
                    } else if (c == ')') {
                        while (!isEmptyChar(pilhaop) && topoChar(pilhaop) != '(') {
                            saida[j++] = popChar(pilhaop);
                        }
                        popChar(pilhaop);
                    } else if (c != ' ') {
                        printf("Operação ou nome de variável inválidos!\n");
                        free(saida);
                        saida = NULL;
                        break;
                    }
                }

                while (!isEmptyChar(pilhaop)) {
                    saida[j++] = popChar(pilhaop);
                }

                saida[j] = '\0';
                printf("Expressão Pós-Fixa: %s\n", saida);
                break;

            case 4: // Avaliação da expressão (a ser implementada)
                printf("Avaliação da expressão ainda não implementada.\n");
                break;

            case 5: // Encerramento do programa
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    // Liberar memória
    if (texto) free(texto);
    if (saida) free(saida);
    if (pilhaop) DestroiStackChar(pilhaop);

    return 0;
}
