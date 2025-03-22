# Notação Demoníaca

## Descrição

O projeto "notacao-demoniaca" é um programa em C++ que converte expressões matemáticas da notação infixa para a notação pós-fixa (notação polonesa reversa). A notação pós-fixa é uma forma de escrever expressões matemáticas onde os operadores seguem seus operandos, eliminando a necessidade de parênteses para definir a ordem das operações.

## Funcionalidades

- Leitura de uma expressão infixa do usuário.
- Conversão da expressão infixa para a notação pós-fixa.
- Suporte para operadores aritméticos básicos (`+`, `-`, `*`, `/`, `^`).
- Suporte para parênteses para definir a precedência das operações.
- Validação de entrada para detectar operadores ou variáveis inválidas.
- Uso de pilhas para gerenciar operadores e operandos durante a conversão.

## Estrutura do Código

- `main.cpp`: Contém a função principal que realiza a leitura da expressão, a conversão e a exibição da expressão pós-fixa.
- `pilha.hpp`: Declaração das estruturas de dados de pilha (`Stack` e `StackChar`) e das funções associadas.
- `pilha.cpp`: Implementação das funções de manipulação de pilha.

## Como Compilar e Executar

1. Certifique-se de ter um compilador C++ instalado (por exemplo, g++).
2. Compile o código usando o seguinte comando:
    ```sh
    g++ -o main main.cpp pilha.cpp
    ```
3. Execute o programa compilado:
    ```sh
    ./main
    ```

## Exemplo de Uso

1. O usuário é solicitado a digitar uma expressão infixa.
2. O programa converte a expressão para a notação pós-fixa.
3. A expressão pós-fixa é exibida ao usuário.

## Exemplo

Entrada:A*(B+C)
Saída:ABC+*

## Autores

Arthur Silva Torres
Gabriel Barbosa de Souza
Lucas Osório Baldoíno
Lucca Romano Brasil