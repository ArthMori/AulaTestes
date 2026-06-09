#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (){
	
char nome [50], senha [20];
int idade;
int i ,senha_letra =0, senha_num=0;
long long int tel, CPF;

// inserir dados
printf("Digite nome:"); 
scanf(" %s", nome);
printf("Digite CPF:"); 
scanf("%lld", &CPF);
printf("Digite idade:"); 
scanf("%d", &idade);
printf("Digite telefone:"); 
scanf("%lld", &tel);

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

