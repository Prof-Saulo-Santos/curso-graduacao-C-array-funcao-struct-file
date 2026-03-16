![imagem](image/prof-saulo-santos-parametros.png)
# Passagem de Parâmetros por Referência em Linguagem C

# Video aula: https://www.youtube.com/watch?v=WJb_uzKB_nk

## 1. Conceito Geral

Em C, os parâmetros são passados por **valor**.\
Para simular passagem por **referência**, utilizamos **ponteiros**.

Isso significa que passamos o **endereço da variável** para a função,
permitindo que ela altere o valor original.

------------------------------------------------------------------------

# 2. Parâmetro do tipo `int`

## 2.1 Exemplo sem referência (não altera o valor original)

``` c
#include <stdio.h>

void altera(int x) {
    x = 10;
}

int main() {
    int a = 5;
    altera(a);
    printf("%d", a);  // Continua 5
}
```

## 2.2 Exemplo com referência (usando ponteiro)

``` c
#include <stdio.h>

void altera(int *x) {
    *x = 10;
}

int main() {
    int a = 5;
    altera(&a);
    printf("%d", a);  // Agora é 10
}
```

------------------------------------------------------------------------

# 3. Array de `int`

Arrays já são passados como ponteiros para o primeiro elemento.

``` c
#include <stdio.h>

void dobra(int v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        v[i] *= 2;
    }
}

int main() {
    int numeros[3] = {1, 2, 3};
    dobra(numeros, 3);

    for(int i = 0; i < 3; i++)
        printf("%d ", numeros[i]);
}
```

------------------------------------------------------------------------

# 4. Array de `double`

``` c
#include <stdio.h>

void aumenta(double v[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        v[i] += 1.5;
    }
}

int main() {
    double valores[3] = {1.0, 2.0, 3.0};
    aumenta(valores, 3);

    for(int i = 0; i < 3; i++)
        printf("%.2lf ", valores[i]);
}
```

------------------------------------------------------------------------

# 5. Parâmetro do tipo `char`

``` c
#include <stdio.h>

void muda(char *c) {
    *c = 'Z';
}

int main() {
    char letra = 'A';
    muda(&letra);
    printf("%c", letra);
}
```

------------------------------------------------------------------------

# 6. Array de `char` (Strings)

Strings em C são arrays de char terminados em '\\0'.

``` c
#include <stdio.h>
#include <string.h>

void alteraString(char str[]) {
    str[0] = 'P';
}

int main() {
    char nome[20] = "Saulo";
    alteraString(nome);
    printf("%s", nome);
}
```

------------------------------------------------------------------------

# 7. Resumo Conceitual

-   C não possui passagem por referência nativa.
-   Utiliza-se ponteiros para modificar valores originais.
-   Arrays já são tratados como ponteiros.
-   Sempre usar operador `&` ao chamar a função.
-   Sempre usar operador `*` para acessar/modificar o valor.

------------------------------------------------------------------------

# 8. Exercícios

## Exercício 1 -- Troca de valores (int)

Crie uma função que receba dois inteiros por referência e troque seus
valores.

## ✅ Solução

``` c
#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    troca(&x, &y);
    printf("x=%d y=%d", x, y);
}
```

------------------------------------------------------------------------

## Exercício 2 -- Maior elemento do vetor

Crie uma função que receba um vetor de inteiros e retorne o maior valor
através de um parâmetro por referência.

## ✅ Solução

``` c
#include <stdio.h>

void maiorElemento(int v[], int tamanho, int *maior) {
    *maior = v[0];
    for(int i = 1; i < tamanho; i++) {
        if(v[i] > *maior) {
            *maior = v[i];
        }
    }
}

int main() {
    int v[4] = {3, 9, 1, 7};
    int resultado;
    maiorElemento(v, 4, &resultado);
    printf("Maior = %d", resultado);
}
```

------------------------------------------------------------------------

## Exercício 3 -- Média de double

Crie uma função que receba um vetor de double e calcule a média,
retornando o resultado por referência.

## ✅ Solução

``` c
#include <stdio.h>

void calculaMedia(double v[], int tamanho, double *media) {
    double soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += v[i];
    }
    *media = soma / tamanho;
}

int main() {
    double v[3] = {5.0, 7.0, 9.0};
    double resultado;
    calculaMedia(v, 3, &resultado);
    printf("Media = %.2lf", resultado);
}
```

------------------------------------------------------------------------

## Exercício 4 -- Converter para maiúscula

Crie uma função que receba um caractere por referência e o converta para
maiúsculo.

## ✅ Solução

``` c
#include <stdio.h>
#include <ctype.h>

void paraMaiusculo(char *c) {
    *c = toupper(*c);
}

int main() {
    char letra = 'a';
    paraMaiusculo(&letra);
    printf("%c", letra);
}
```

------------------------------------------------------------------------

## Exercício 5 -- Contar vogais

Crie uma função que receba uma string e retorne, por referência, a
quantidade de vogais.

## ✅ Solução

``` c
#include <stdio.h>
#include <ctype.h>

void contarVogais(char str[], int *quantidade) {
    *quantidade = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            (*quantidade)++;
        }
    }
}

int main() {
    char texto[] = "Programacao";
    int total;
    contarVogais(texto, &total);
    printf("Vogais = %d", total);
}
```

------------------------------------------------------------------------

# Lista de Exercícios

## Passagem de Parâmetros por Referência em Linguagem C

### (Versão para Alunos -- Sem Soluções)

------------------------------------------------------------------------

## Parte 1 -- Conceitos Fundamentais

1.  Explique a diferença entre passagem por valor e passagem por
    referência em C.
2.  Por que a linguagem C não possui passagem por referência nativa?
3.  Qual a função dos operadores `&` e `*` nesse contexto?

------------------------------------------------------------------------

## Parte 2 -- Tipo int

4.  Crie uma função que receba um inteiro por referência e o triplique.
5.  Implemente uma função que receba dois inteiros por referência e
    retorne, também por referência, o maior deles.
6.  Escreva uma função que receba um inteiro por referência e informe se
    ele é par ou ímpar (retornando o resultado por outro parâmetro por
    referência).

------------------------------------------------------------------------

## Parte 3 -- Vetor de int

7.  Crie uma função que receba um vetor de inteiros e seu tamanho e
    calcule a soma dos elementos.
8.  Desenvolva uma função que conte quantos números negativos existem em
    um vetor.
9.  Faça uma função que substitua todos os valores negativos por zero em
    um vetor.
10. Implemente uma função que troque o primeiro elemento com o último
    elemento de um vetor.

------------------------------------------------------------------------

## Parte 4 -- Vetor de double

11. Crie uma função que calcule o desvio simples (valor - média) de cada
    elemento de um vetor.
12. Desenvolva uma função que normalize um vetor (dividindo todos os
    elementos pelo maior valor).
13. Implemente uma função que encontre o segundo maior valor de um
    vetor.

------------------------------------------------------------------------

## Parte 5 -- Tipo char

14. Crie uma função que receba um caractere por referência e o converta
    para minúsculo.
15. Implemente uma função que verifique se um caractere é letra ou
    número.
16. Escreva uma função que receba um caractere e o substitua por '\*'
    caso seja vogal.

------------------------------------------------------------------------

## Parte 6 -- Strings (array de char)

17. Crie uma função que conte quantos caracteres existem em uma string
    (sem usar strlen).
18. Desenvolva uma função que substitua todas as ocorrências de uma
    letra específica em uma string.
19. Implemente uma função que remova espaços em branco de uma string.
20. Faça uma função que converta toda a string para maiúscula.
21. Crie uma função que verifique se uma string é palíndromo.

------------------------------------------------------------------------

## Parte 7 -- Nível Avançado

22. Crie uma função que receba dois vetores e retorne, por referência, o
    vetor soma.
23. Implemente uma função que faça a multiplicação escalar entre dois
    vetores.
24. Desenvolva uma função que troque duas linhas de uma matriz NxN.
25. Crie uma função que aloque dinamicamente um vetor e o retorne via
    ponteiro duplo.
26. Implemente uma função que compacte uma string removendo caracteres
    repetidos consecutivos.
27. Desenvolva uma função que ordene uma matriz 3x3 em ordem crescente.
28. Faça uma função que receba um vetor e retorne, por referência, a
    quantidade de números primos.

------------------------------------------------------------------------

## Desafio Extra

29. Implemente um mini-sistema que receba um vetor de notas e retorne:

-   Média
-   Maior nota
-   Menor nota
-   Quantidade de aprovados (nota \>= 6) Todos os resultados devem ser
    retornados por referência.

------------------------------------------------------------------------

### Observação

Todos os exercícios devem obrigatoriamente utilizar passagem de
parâmetros por referência quando necessário.

------------------------------------------------------------------------


