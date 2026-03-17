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
