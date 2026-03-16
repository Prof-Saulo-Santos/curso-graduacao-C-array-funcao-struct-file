#include <stdio.h>
int main(){
    char nome[10];
    int idade;

    //Entrada   
    printf("Digite seu primeiro nome(digite um nome composto com mais de 10 caracteres): ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;   
}
