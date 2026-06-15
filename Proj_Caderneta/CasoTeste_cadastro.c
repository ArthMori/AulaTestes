#include <stdio.h>
#include "minunit.h"
#include "caso_teste_cadastro.c"

MU_TEST(teste_cadastro){
    mu_assert_int_eq(1, teste_cadastro_usuario("Gabriel", 18));
}

MU_TEST_SUITE(teste_suite){
    MU_RUN_TEST(teste_cadastro);
}

int main() {
    MU_RUN_SUITE(teste_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}