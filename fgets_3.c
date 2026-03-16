#include <string.h> // Necessário para a função strcspn
#include <stdio.h>
int main(){
    char nome[10];
    int idade;
    int lixo;

    //Entrada
    printf("Digite seu nome: ");
    fgets(nome, 10, stdin); // Lê uma linha inteira contendo espaços no máximo até 49 caracteres.
    nome[strcspn(nome, "\n")] = '\0'; // Encontra a posição do '\n' e substitui pelo caractere nulo '\0'
    while ((lixo = getchar()) != '\n' && lixo != '\r' && lixo != EOF); //limpa o buffer de entrada
    printf("Digite sua idade: ");
    scanf("%d", &idade); // scanf recolhe o lixo de entrada e impede digitação da idade.

    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;
}