#include <iostream>
#include <cassert>
#include <cmath>

// Vinculação com o código em C da calculadora
extern "C" {
    /**
     * @brief Declaração da função que está no Calculadora.c
     */
    int soma(int v1, int v2); // <-- Apenas a assinatura com ponto e vírgula!
    
    // Quando você criar subtração, coloque aqui só a assinatura também:
    // int subtracao(int v1, int v2);
}

/**
 * @brief Executa os testes unitários da função soma.
 */
void test_soma() {
    // Teste com números positivos
    assert(soma(2, 3) == 5);
    
    // Teste com números negativos
    assert(soma(-1, -1) == -2);
    
    // Teste com zero
    assert(soma(5, 0) == 5);
    
    std::cout << "[PASS] Teste da funcao soma passou com sucesso!" << std::endl;
}

/**
 * @brief Ponto de entrada principal para a execução dos testes.
 */
int main() {
    std::cout << "Iniciando os testes da calculadora..." << std::endl;
    
    // Executa a suíte de testes
    test_soma();
    
    std::cout << "Todos os testes foram executados com sucesso!" << std::endl;
    return 0;
}