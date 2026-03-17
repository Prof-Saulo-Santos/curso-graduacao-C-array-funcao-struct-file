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