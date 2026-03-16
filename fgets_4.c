#include "pss.h"
#include <stdio.h>
int main(){
    char nome[10];
    int idade;

    //Entrada
    input_s("Digite o nome: ",nome,sizeof(nome)); 
    idade =  input_d("Digite a idade: "); 

    //Saída
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    return 0;
}
