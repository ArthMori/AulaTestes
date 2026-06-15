#include "minunit.h"
#include "relatorio_vendas.h"

Venda vendas[2] = {{2, 25.50}, {5, 8.00}};

MU_TEST(test_total_de_uma_venda) {
    mu_assert_double_eq(51.00, calcular_total_venda(vendas[0]));
}

MU_TEST(test_faturamento_total) {
    mu_assert_double_eq(91.00, calcular_faturamento_total(vendas, 2));
}

MU_TEST(test_total_itens_vendidos) {
    mu_assert_int_eq(7, calcular_total_itens_vendidos(vendas, 2));
}

MU_TEST_SUITE(suite_relatorio_vendas) {
    MU_RUN_TEST(test_total_de_uma_venda);
    MU_RUN_TEST(test_faturamento_total);
    MU_RUN_TEST(test_total_itens_vendidos);
}

int main(void) {
    MU_RUN_SUITE(suite_relatorio_vendas);
    MU_REPORT();
    return MU_EXIT_CODE;
}
