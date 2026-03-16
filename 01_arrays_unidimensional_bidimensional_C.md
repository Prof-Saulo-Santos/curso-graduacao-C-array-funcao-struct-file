![imagem](image/prof-saulo-santos-array.png)
# 📘 Arrays Unidimensionais e Bidimensionais em C

*(usando tipos `int` e `double`)*

------------------------------------------------------------------------

## 1️⃣ O que é um Array em C?

Um **array** (vetor ou matriz) é uma estrutura de dados que armazena
múltiplos valores **do mesmo tipo** em posições contíguas de memória.

Em C:

-   Todos os elementos têm **mesmo tipo**
-   O tamanho deve ser definido na declaração
-   O índice começa em **0**

------------------------------------------------------------------------

# 🔹 PARTE 1 --- ARRAY UNIDIMENSIONAL (VETOR)

Um array unidimensional é uma sequência linear de elementos.

------------------------------------------------------------------------

## 📌 Declaração

``` c
tipo nome[tamanho];
```

### Exemplos:

``` c
int numeros[5];
double notas[3];
```

------------------------------------------------------------------------

## 📌 Inicialização

``` c
int numeros[5] = {1, 2, 3, 4, 5};
double notas[3] = {7.5, 8.0, 9.3};
```

Também é possível:

``` c
int numeros[] = {10, 20, 30};  // tamanho automático
```

------------------------------------------------------------------------

## 📌 Acessando elementos

``` c
printf("%d", numeros[0]);   // primeiro elemento
printf("%.2lf", notas[1]);  // segundo elemento
```

------------------------------------------------------------------------

## 📌 Exemplo completo com int

``` c
#include <stdio.h>

int main() {
    int vetor[5];
    int i;

    for(i = 0; i < 5; i++) {
        printf("Digite um numero: ");
        scanf("%d", &vetor[i]);
    }

    printf("\nValores digitados:\n");
    for(i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
```

------------------------------------------------------------------------

## 📌 Exemplo completo com double

``` c
#include <stdio.h>

int main() {
    double notas[4];
    int i;
    double soma = 0;

    for(i = 0; i < 4; i++) {
        printf("Digite a nota: ");
        scanf("%lf", &notas[i]);
        soma += notas[i];
    }

    printf("Media: %.2lf\n", soma/4);

    return 0;
}
```

------------------------------------------------------------------------

# 🔹 PARTE 2 --- ARRAY BIDIMENSIONAL (MATRIZ)

Um array bidimensional é organizado em **linhas e colunas**.

Representa uma **tabela**.

------------------------------------------------------------------------

## 📌 Declaração

``` c
tipo nome[linhas][colunas];
```

### Exemplos:

``` c
int matriz[3][3];
double tabela[2][4];
```

------------------------------------------------------------------------

## 📌 Representação visual

### Matriz 3x3:

    [0][0]  [0][1]  [0][2]
    [1][0]  [1][1]  [1][2]
    [2][0]  [2][1]  [2][2]

------------------------------------------------------------------------

## 📌 Inicialização

``` c
int matriz[2][2] = {
    {1, 2},
    {3, 4}
};
```

------------------------------------------------------------------------

# 🔹 Exemplo com int (matriz 3x3)

``` c
#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Digite valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz digitada:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

------------------------------------------------------------------------

# 🔹 Exemplo com double (matriz 2x3)

``` c
#include <stdio.h>

int main() {
    double matriz[2][3];
    int i, j;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("Digite valor [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

------------------------------------------------------------------------

# 🔹 Diferença entre int e double

  Tipo     Armazena   Exemplo     Formato printf   Formato scanf
  -------- ---------- ----------- ---------------- ---------------
  int      Inteiros   10, -3      %d               %d
  double   Reais      7.5, 3.14   %lf ou %.2lf     %lf

------------------------------------------------------------------------

# 🔹 Como a memória funciona

Em C, arrays são armazenados de forma **contígua na memória**.

Para matriz, o armazenamento é feito em **ordem por linha (row-major
order)**:

    matriz[0][0]
    matriz[0][1]
    matriz[0][2]
    matriz[1][0]
    ...

------------------------------------------------------------------------

# 🔹 Erros Comuns

❌ Acessar índice fora do limite\
❌ Esquecer `&` no scanf\
❌ Usar `%d` para double\
❌ Não inicializar o array

------------------------------------------------------------------------

# 🔹 Resumo Final

  ----------------------------------------------------------------------------
  Tipo             Estrutura           Acesso          Uso típico
  ---------------- ------------------- --------------- -----------------------
  Unidimensional   vetor\[i\]          1 índice        listas, notas, idades

  Bidimensional    matriz\[i\]\[j\]    2 índices       tabelas, matrizes
                                                       matemáticas
  ----------------------------------------------------------------------------

------------------------------------------------------------------------

# 🔹 Exercícios Propostos

1.  Criar um vetor de 10 inteiros e mostrar o maior valor.
2.  Criar um vetor de double e calcular o desvio médio.
3.  Criar uma matriz 3x3 e calcular:
    -   Soma da diagonal principal
    -   Soma total dos elementos
4.  Criar uma matriz 5x2 representando alunos e duas notas.
