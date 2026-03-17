![imagem](image/prof-saulo-santos-string-caract.png)
# 📘 Strings e Arrays de Caracteres em C

Em C, não existe um tipo de dados primitivo específico para textos (como `String` em Java ou Python). Em vez disso, textos são representados através de um **array de caracteres** (vetor do tipo `char`).

---

## 1️⃣ Conceitos de Array de Caracteres

Uma **string** em C é um array (ou vetor) uni-dimensional do tipo `char` que obrigatoriamente termina com um caractere especial nulo `'\0'` (null terminator). Esse caractere serve para indicar onde o texto termina na memória.

- **Tamanho do Array:** O tamanho do array deve ser sempre **pelo menos um caractere maior** que o texto que você deseja armazenar. Esse espaço extra é exclusivo para acomodar o terminador `'\0'`.
- Por exemplo, a palavra `"Olá"` tem 3 letras, mas precisa de um array de tamanho 4 para ser armazenada fisicamente na memória de forma correta (`'O'`, `'l'`, `'á'`, `'\0'`).

---

## 2️⃣ Inicialização

Existem várias formas de declarar e inicializar uma string:

### Inicialização com aspas duplas (Mais comum e prática)
Neste formato, o compilador adiciona o `'\0'` automaticamente no final da string.
```c
char nome[10] = "Saulo"; 
// O array tem espaço para 10 caracteres, mas a string ocupa 6 posições (5 letras + '\0')
```

### Inicialização caractere por caractere
Neste formato, você **deve** incluir o `'\0'` manualmente como o último elemento, do contrário não será considerado uma string válida para funções da biblioteca padrão.
```c
char saudacao[] = {'O', 'l', 'a', '\0'};
```

### Inicialização sem tamanho definido (Automático)
Se você inicializar a variável no momento da declaração sem especificar o tamanho entre conchetes `[]`, o compilador aloca o tamanho exato para a frase mais o `'\0'`.
```c
char cidade[] = "Sao Paulo"; // Tamanho 10 será alocado automaticamente (9 letras/espaço + 1 nulo)
```

---

## 3️⃣ Leitura e Impressão

Para interagir com textos via console, geralmente usamos as funções da biblioteca `<stdio.h>` como `scanf`/`printf` ou `fgets`/`puts`.

### Impressão
Utilizamos o especificador `%s` no `printf`, ou a função especifica `puts`.

```c
char nome[] = "Maria";
printf("Nome: %s\n", nome); 
puts(nome); // Equivalente a um printf com \n automático no final
```

### Leitura (abra: fgets_1.c)
Ao usar `scanf` com formatador `%s`, **NÃO** colocamos o operador `&` antes da variável, pois arrays em C decaem naturalmente para ponteiros passando seu próprio endereço de memória.
⚠️ *Aviso: O `scanf` com `%s` lê apenas a primeira palavra (para no primeiro espaço em branco).*
```c
#include <stdio.h>
int main(){
    char nome[10];
    int idade;

    //Entrada   
    printf("Digite nome e sobrenome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;   
}
```

**Para ler textos com múltiplos espaços protegendo a quebra de buffer, a melhor abordagem é `fgets` (abra: fgets_2.c):**
```c
#include <string.h> // Necessário para a função strcspn
#include <stdio.h>
int main(){
    char nome[10];
    int idade;

    //Entrada
    printf("Digite nome e sobrenome: ");
    fgets(nome, 10, stdin); // Lê uma linha inteira contendo espaços no máximo até 49 caracteres.
    nome[strcspn(nome, "\n")] = '\0'; // Encontra a posição do '\n' e substitui pelo caractere nulo '\0'
    printf("Digite sua idade: ");
    scanf("%d", &idade); // scanf recolhe o lixo de entrada e impede digitação da idade.

    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;
}
```

**No entanto, ainda temos que esvaziar o buffer de entrada! (abra: fgets_3.c)**
```c
#include <string.h> 
#include <stdio.h>
int main(){
    char nome[10];
    int idade;
    int lixo;

    //Entrada
    printf("Digite nome e sobrenome: ");
    fgets(nome, 10, stdin);
    if (strchr(nome, '\n') == NULL)     
       while ((lixo = getchar()) != '\n' && lixo != '\r' && lixo != EOF);
    nome[strcspn(nome, "\n")] = '\0'; 

    printf("Digite sua idade: ");
    scanf("%d", &idade); 

    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;    
}
```

# Solução usando pss.h/pss.c (abra: fgets_4.c)
```c
#include "pss.h"
#include <stdio.h>
int main(){
    char nome[10];
    int idade;

    //Entrada
    input_s("Digite nome e sobrenome: ",nome,sizeof(nome)); 
    idade =  input_d("Digite a idade: "); 

    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;
}
```

---

## 4️⃣ Passagem de Parâmetros

Quando passamos um array (incluindo arrays de caracteres/strings) para uma função, não passamos o conteúdo do texto por cópia, e sim uma **referência** para o início (o endereço do primeiro caractere) através de um ponteiro.
Isso significa que modificações feitas na string dentro da função, afetam diretamente a string original declarada na função executora.

```c
#include <stdio.h>
#include <ctype.h> // Para a função toupper()

// Função que converte as letras do array original para maiúsculas
void paraMaiusculo(char str[]) {
    int i = 0;
    while(str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main() {
    char texto[30] = "linguagem c";
    paraMaiusculo(texto); // Chamando por referência
    printf("Texto modificado: %s\n", texto); // Saída: LINGUAGEM C
    return 0;
}
```

---

## 5️⃣ Retorno de Função

Em C, não é possível retornar por valor um array criado dentro da própria função (variável local) usando a diretiva `return`, já que em C a variável local perde o escopo e é destruída ao final da execução.

Se precisarmos "retornar" ou preencher uma string a partir de uma função, temos duas metodologias principais:

### Alternativa A: Passar um array de destino como parâmetro (Mais simples e recomendada)
Uma função apenas "escreve" o resultado final num array passado pelo escopo da sua chamadora.
```c
#include <stdio.h>
#include <string.h>

// A função preenche a string 'destino' com a lógica processada sobre a 'origem'
void gerarSaudacao(char destino[], char nome[]) {
    strcpy(destino, "Ola, ");   // Copia a primeira string no destino
    strcat(destino, nome);      // Concatena a segunda string
}

int main() {
    char nomeOriginal[] = "Ana";
    char saudacaoFinal[50]; // Buffer sendo alocado no caller para armazenamento com capacidade de 50 char.
    
    gerarSaudacao(saudacaoFinal, nomeOriginal);
    printf("%s\n", saudacaoFinal);
    return 0;
}
```

### Alternativa B: Retornar ponteiro alocado dinamicamente (Esse assunto será abordado na disciplina de Estrutura de Dados)
Aloca-se bloco extra via sistema durante tempo de execução, retornando um ponteiro `char*`.
```c
#include <stdio.h>
#include <stdlib.h> // Para malloc() e free()
#include <string.h>

char* criarSaudacao(char nome[]) {
    // Aloca memória dinamicamente no espaço Heap
    char *resultado = (char*) malloc(50 * sizeof(char)); 
    strcpy(resultado, "Ola, ");
    strcat(resultado, nome);
    return resultado; // Retorna o endereço da memória dinamicamente alocada
}

int main() {
    char nome[] = "Saulo";
    char *mensagem = criarSaudacao(nome);
    
    printf("%s\n", mensagem);
    
    free(mensagem); // Importante liberar a memória para evitar vazamento (memory leak)
    return 0;
}
```

- Usaremos nesse curso a alternativa A, pois é mais simples e não requer o uso de `malloc` e `free`. 

---

## 6️⃣ Comparação de Strings (`strcmp`)

Em C, você **não pode** usar o operador `==` para comparar se duas strings têm o mesmo conteúdo. O operador `==` compararia apenas os *endereços de memória* dos vetores, e não os textos.

Para comparar o conteúdo de duas strings, utilizamos a função **`strcmp()`** (String Compare) da biblioteca `<string.h>`.

A função `strcmp(string1, string2)` retorna:
- **`0`**: Se as strings forem **exatamente iguais**.
- **`< 0` (negativo)**: Se a `string1` vier *antes* da `string2` em ordem alfabética.
- **`> 0` (positivo)**: Se a `string1` vier *depois* da `string2` em ordem alfabética.

### Exemplo Prático:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char senhaCorreta[] = "12345";
    char senhaDigitada[20];

    printf("Digite a senha: ");
    scanf("%19s", senhaDigitada); // A IA criou esse codigo, mas voce sabe que ele é perigoso! Prefira fgets()

    printf("A quantidade de caracteres digitados foi: %d\n", strlen(senhaDigitada));

    // Compara as duas strings. Retorna 0 se forem iguais.
    if (strcmp(senhaCorreta, senhaDigitada) == 0) {
        printf("Acesso Permitido!\n");
    } else {
        printf("Senha Incorreta!\n");
    }

    return 0;
}
```

---

## 7️⃣ Exercícios Propostos

1. **Tamanho Manual da String:** Implemente uma função chamada `meuStrlen` que receba uma string por referência e retorne o seu tamanho inteiro (contando posições até o `'\0'`) sem usar a biblioteca nativa `<string.h>`.
2. **Contador de Vogais:** Escreva um programa que leia uma frase usando `fgets` e conte quantas vogais (a, e, i, o, u) ela possui e imprima a quantidade no log. Considere o tratamento para as letras minúsculas e maiúsculas.
3. **Inverter String inplace:** Crie uma função que receba uma string como parâmetro e troque/inverta a estrutura do texto _na própria string_ de modo referenciado (ex: `"Roma"` torna-se `"amoR"` internamente sem criar outro vetor).
4. **Substituição de Caracteres:** Desenvolva um programa que peça uma palavra e um caractere alvo. Crie uma função que busque o caractere alvo na palavra e os converta no caractere `'*'` retornando por fim quantos caracteres foram substituídos.
5. **Autenticação Palíndromo:** Escreva uma função inteira que valide se uma palavra lida é um "palíndromo" (se ao lida de trás para a frente a mesma equivale exatamente a original. Ex: "osso", "radar"). Retorne 1 para palíndromo verdadeiro e 0 para falso.
