#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Funcao interativa para o usuario criar e validar uma senha no terminal.
 * @note Verifica se a senha possui no maximo 6 caracteres, contendo letras e numeros.
 */
void testeSenha() {
    char senha[20];
    int i, senha_letra = 0, senha_num = 0;

    // criar senha
    printf("\n Crie a senha \n");
    printf("Digite uma senha:"); 
    scanf("%19s", senha);

    // percorrendo o vetor senha
    for(i=0; i < strlen(senha); i++){
        if(isalpha(senha[i])){
            senha_letra=1;
        }
        if(isdigit(senha[i])){
            senha_num=1;
        }
    }
    
    // condicoes para aprovacao ou reprovacao do cadastro
    if(strlen(senha)>6 ){
        printf("ERRO!! A SENHA DEVE TER NO MÁXIMO 6 CARACTERES.\n");
    } 
    else if(!senha_letra || !senha_num){
        printf("ERRO! A senha deve conter letras e numeros!\n");
    }
    else {
        printf("Cadastro realizado com sucesso!!\n");
    }
}