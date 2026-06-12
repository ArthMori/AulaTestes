#include "minunit.h"
#include <string.h>
#include <ctype.h>

int validarSenha(char senha[]) {

    int i;
    int senha_letra = 0;
    int senha_num = 0;

    for(i = 0; i < strlen(senha); i++) {

        if(isalpha(senha[i]))
            senha_letra = 1;

        if(isdigit(senha[i]))
            senha_num = 1;
    }

    if(strlen(senha) > 6)
        return 0;

    if(!senha_letra || !senha_num)
        return 0;

    return 1;
}

MU_TEST(teste_senha_valida) {
    mu_assert_int_eq(1, validarSenha("abc123"));
}

MU_TEST(teste_sem_numero) {
    mu_assert_int_eq(0, validarSenha("abcdef"));
}

MU_TEST(teste_sem_letra) {
    mu_assert_int_eq(0, validarSenha("123456"));
}

MU_TEST(teste_maior_que_6) {
    mu_assert_int_eq(0, validarSenha("abc1234"));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(teste_senha_valida);
    MU_RUN_TEST(teste_sem_numero);
    MU_RUN_TEST(teste_sem_letra);
    MU_RUN_TEST(teste_maior_que_6);
}

void executarTestes() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
}
