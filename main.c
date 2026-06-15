#include <stdio.h>
#include "minunit.h"
int teste_cadastro_usuario(char *nome, int idade);

MU_TEST(teste_cadastro){
    mu_assert( teste_cadastro_usuario("Gabriel", 18), "ERRO! USUÁRIO NÃO CADASTRADO!");
}
MU_TEST_SUITE(teste_suite){
    MU_RUN_TEST(teste_cadastro);
}
int main() {
    //teste_cadastro_usuario("Gabriel", 18);
    //registro_de_compras_fiadas("Joao", 100);
    MU_RUN_SUITE(teste_suite);
    MU_REPORT();
    
    return MU_EXIT_CODE;
}