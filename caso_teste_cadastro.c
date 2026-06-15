#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int teste_cadastro_usuario(char *nome, int idade){
    if(strlen(nome)==0 || idade <= 0 ||){
        return 0;
    }
    else{
        return 1;
    }
}