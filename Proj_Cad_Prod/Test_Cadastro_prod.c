#include "minunit.h"

/**
 * @brief Calcula o preco final para o consumidor (margem de 60%).
 * @param preco_f Preco de custo do fornecedor (float).
 * @return O preco final ajustado (float).
 */
float Preco_Final_Cons(float preco_f){
    return (preco_f * 0.6) + preco_f;
}

/**
 * @brief Stub: Simula a busca do percentual de imposto no banco de dados.
 * @param id_estado ID do estado para consulta de imposto.
 * @return O percentual de imposto simulado.
 * @note Essa funcao eh um stub para simular dependencias externas nos testes.
 */
float stub_buscar_imposto_bd(int id_estado) {
    // Simulando comportamento de banco de dados para os testes
    if (id_estado == 1) return 0.10; // 10% para o estado 1
    return 0.05; // 5% para os demais
}

/**
 * @brief Calcula o preco final incluindo o imposto simulado (Depende do Stub).
 * @param preco_base Preco base do produto.
 * @param id_estado ID do estado para calcular o imposto.
 * @return Preco total com imposto.
 */
float Preco_Com_Imposto(float preco_base, int id_estado) {
    float imposto = stub_buscar_imposto_bd(id_estado);
    return preco_base + (preco_base * imposto);
}

/* --- TESTES UNITARIOS MINUNIT --- */

MU_TEST(teste_preco_100) {
    mu_assert_double_eq(160.0, Preco_Final_Cons(100.0));
}

// Novos testes estruturados (cenarios alternativos e de excecao)
MU_TEST(teste_preco_zero) {
    mu_assert_double_eq(0.0, Preco_Final_Cons(0.0));
}

MU_TEST(teste_preco_quebrado) {
    mu_assert_double_eq(80.8, Preco_Final_Cons(50.5));
}

// Testando a funcionalidade usando o STUB
MU_TEST(teste_preco_com_imposto_estado_1) {
    mu_assert_double_eq(110.0, Preco_Com_Imposto(100.0, 1));
}

MU_TEST(teste_preco_com_imposto_outros_estados) {
    mu_assert_double_eq(105.0, Preco_Com_Imposto(100.0, 2));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(teste_preco_100);
    MU_RUN_TEST(teste_preco_zero);
    MU_RUN_TEST(teste_preco_quebrado);
    MU_RUN_TEST(teste_preco_com_imposto_estado_1);
    MU_RUN_TEST(teste_preco_com_imposto_outros_estados);
}

int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}