#include <stdio.h>
#include <string.h>
#include <ctype.h>

void testeSenha()

// criar senha
printf("\n Crie a senha \n");
printf("Digite uma senha:"); scanf("%19s", senha);

// percorrendo o vetor senha
for(i=0; i < strlen(senha); i++){
	if(isalpha(senha[i])){
		senha_letra=1;
	}
	if(isdigit(senha[i])){
		senha_num=1;
	}
}
// condições para aprovação ou reprovação do cadastro
if(strlen(senha)>6 ){
	printf("ERRO!! A SENHA DEVE TER NO MÁXIMO 6 CARACTERES.");
} 
	else if(!senha_letra || !senha_num){
    	printf("ERRO! A senha deve conter letras e numeros!");
	}
		else {
			printf("Cadastro realizado com sucesso!!");
		}


return 0;	
}

