#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "minunit.h"

int tests_run = 0;

extern "C" {
    int soma(int v1, int v2);
    float calcular_subtotal(float preco, int quantidade);
    float calcular_troco(float valor_pago, float valor_total);
    float aplicar_desconto(float valor_total, float porcentagem);
    int validar_estoque(int estoque_disponivel, int quantidade_solicitada);
}

const char* test_soma() {
    for(int i = 0; i < 50; i++) {
        int v1 = rand() % 1000 - 500;
        int v2 = rand() % 1000 - 500;
        mu_assert("Erro na funcao soma", soma(v1, v2) == v1 + v2);
    }
    return 0;
}

const char* test_calcular_subtotal() {
    for(int i = 0; i < 50; i++) {
        float preco = (rand() % 10000) / 100.0f;
        int qtde = rand() % 50;
        mu_assert("Erro em calcular_subtotal", std::abs(calcular_subtotal(preco, qtde) - (preco * qtde)) < 0.001);
    }
    return 0;
}

const char* test_calcular_troco() {
    for(int i = 0; i < 50; i++) {
        float total = (rand() % 5000) / 100.0f + 1.0f;
        float pago = total + ((rand() % 2000) / 100.0f);
        mu_assert("Erro no troco", std::abs(calcular_troco(pago, total) - (pago - total)) < 0.001);
    }
    mu_assert("Erro troco negativo", calcular_troco(10.0f, 20.0f) == -1.0f);
    return 0;
}

const char* test_aplicar_desconto() {
    for(int i = 0; i < 50; i++) {
        float total = (rand() % 10000) / 100.0f + 10.0f;
        float desc = rand() % 101; 
        float esperado = total - (total * (desc / 100.0f));
        mu_assert("Erro no desconto", std::abs(aplicar_desconto(total, desc) - esperado) < 0.001);
    }
    mu_assert("Erro desc negativo", aplicar_desconto(100.0f, -5.0f) == 100.0f);
    mu_assert("Erro desc maior 100", aplicar_desconto(100.0f, 150.0f) == 100.0f);
    return 0;
}

const char* test_validar_estoque() {
    for(int i = 0; i < 50; i++) {
        int est = rand() % 100 + 10;
        int ped = rand() % est + 1;
        mu_assert("Erro estoque valido", validar_estoque(est, ped) == 1);
        mu_assert("Erro estoque invalido", validar_estoque(est, est + 1) == 0);
    }
    mu_assert("Erro estoque ped zero", validar_estoque(10, 0) == 0);
    mu_assert("Erro estoque ped negativo", validar_estoque(10, -5) == 0);
    return 0;
}

const char* all_tests() {
    mu_run_test(test_soma);
    mu_run_test(test_calcular_subtotal);
    mu_run_test(test_calcular_troco);
    mu_run_test(test_aplicar_desconto);
    mu_run_test(test_validar_estoque);
    return 0;
}

int main() {
    srand(time(NULL));
    
    const char* result = all_tests();
    
    if (result != 0) {
        std::cout << "FALHA: " << result << std::endl;
    } else {
        std::cout << "TODOS OS TESTES PASSARAM" << std::endl;
    }
    
    std::cout << "Testes rodados: " << tests_run << std::endl;
    
    system("pause");
    
    return result != 0;
}