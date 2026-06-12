#include "minunit.h"

float Preco_Final_Cons(float preco_f){
    return (preco_f * 0.6) + preco_f;
}

MU_TEST(teste_preco_100) {
    mu_assert_double_eq(160.0, Preco_Final_Cons(100.0));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(teste_preco_100);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
