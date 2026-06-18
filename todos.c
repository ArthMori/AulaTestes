#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "minunit.h"

// ============================================================================
// 1. LÓGICAS DE NEGÓCIO
// ============================================================================

// --- Mercadinho (Caixa e Estoque) ---
int soma(int v1, int v2) { return v1 + v2; }
float calcular_subtotal(float preco, int quantidade) { return preco * quantidade; }
float calcular_troco(float valor_pago, float valor_total) { if (valor_pago < valor_total) return -1.0; return valor_pago - valor_total; }
float aplicar_desconto(float valor_total, float porcentagem) { if (porcentagem < 0.0 || porcentagem > 100.0) return valor_total; return valor_total - (valor_total * (porcentagem / 100.0)); }
int validar_estoque(int estoque_disponivel, int quantidade_solicitada) { if (quantidade_solicitada <= 0) return 0; return estoque_disponivel >= quantidade_solicitada ? 1 : 0; }

// --- Cadastro de Usuário (Senha) ---
int validarSenha(char senha[]) {
    int i, senha_letra = 0, senha_num = 0;
    if(strlen(senha) > 6 || strlen(senha) == 0) return 0;
    for(i = 0; i < strlen(senha); i++) {
        if(isalpha(senha[i])) senha_letra = 1;
        if(isdigit(senha[i])) senha_num = 1;
    }
    if(!senha_letra || !senha_num) return 0;
    return 1;
}

// --- Cadastro de Produto (Margem e Imposto via Stub) ---
float Preco_Final_Cons(float preco_f){ return (preco_f * 0.6) + preco_f; }
float stub_buscar_imposto_bd(int id_estado) { if (id_estado == 1) return 0.10; return 0.05; }
float Preco_Com_Imposto(float preco_base, int id_estado) { float imposto = stub_buscar_imposto_bd(id_estado); return preco_base + (preco_base * imposto); }

// --- Caderneta (Fiado) ---
int teste_cadastro_usuario(char *nome, int idade){
    if(strlen(nome) == 0 || idade <= 0) return 0;
    return 1;
}

// ============================================================================
// 2. TESTES UNITÁRIOS (MINUNIT)
// ============================================================================

// Testes do Mercadinho
MU_TEST(test_soma) { mu_assert_int_eq(15, soma(10, 5)); }
MU_TEST(test_calcular_subtotal) { mu_assert_double_eq(50.0, calcular_subtotal(10.0, 5)); }
MU_TEST(test_calcular_troco) { 
    mu_assert_double_eq(10.0, calcular_troco(50.0, 40.0)); 
    mu_assert_double_eq(-1.0, calcular_troco(10.0, 40.0)); // Bloqueia troco negativo
}
MU_TEST(test_aplicar_desconto) { mu_assert_double_eq(90.0, aplicar_desconto(100.0, 10.0)); }
MU_TEST(test_validar_estoque) { 
    mu_assert_int_eq(1, validar_estoque(10, 5)); 
    mu_assert_int_eq(0, validar_estoque(10, 15)); // Bloqueia falta de estoque
}

// Testes do Usuário
MU_TEST(teste_senha_valida) { mu_assert_int_eq(1, validarSenha("abc123")); }
MU_TEST(teste_sem_numero) { mu_assert_int_eq(0, validarSenha("abcdef")); }
MU_TEST(teste_sem_letra) { mu_assert_int_eq(0, validarSenha("123456")); }
MU_TEST(teste_maior_que_6) { mu_assert_int_eq(0, validarSenha("abc1234")); }
MU_TEST(teste_senha_vazia) { mu_assert_int_eq(0, validarSenha("")); }

// Testes do Produto
MU_TEST(teste_preco_100) { mu_assert_double_eq(160.0, Preco_Final_Cons(100.0)); }
MU_TEST(teste_preco_zero) { mu_assert_double_eq(0.0, Preco_Final_Cons(0.0)); }
MU_TEST(teste_preco_quebrado) { mu_assert_double_eq(80.8, Preco_Final_Cons(50.5)); }
MU_TEST(teste_preco_com_imposto_estado_1) { mu_assert_double_eq(110.0, Preco_Com_Imposto(100.0, 1)); }
MU_TEST(teste_preco_com_imposto_outros_estados) { mu_assert_double_eq(105.0, Preco_Com_Imposto(100.0, 2)); }

// Testes da Caderneta
MU_TEST(teste_cadastro_valido) { mu_assert_int_eq(1, teste_cadastro_usuario("Gabriel", 18)); }
MU_TEST(teste_cadastro_invalido_idade) { mu_assert_int_eq(0, teste_cadastro_usuario("Gabriel", -5)); } // Bloqueia idade negativa

// ============================================================================
// 3. AGRUPAMENTO DAS SUÍTES
// ============================================================================

MU_TEST_SUITE(suite_mercadinho) {
    MU_RUN_TEST(test_soma);
    MU_RUN_TEST(test_calcular_subtotal);
    MU_RUN_TEST(test_calcular_troco);
    MU_RUN_TEST(test_aplicar_desconto);
    MU_RUN_TEST(test_validar_estoque);
}

MU_TEST_SUITE(suite_usuario) {
    MU_RUN_TEST(teste_senha_valida);
    MU_RUN_TEST(teste_sem_numero);
    MU_RUN_TEST(teste_sem_letra);
    MU_RUN_TEST(teste_maior_que_6);
    MU_RUN_TEST(teste_senha_vazia);
}

MU_TEST_SUITE(suite_produto) {
    MU_RUN_TEST(teste_preco_100);
    MU_RUN_TEST(teste_preco_zero);
    MU_RUN_TEST(teste_preco_quebrado);
    MU_RUN_TEST(teste_preco_com_imposto_estado_1);
    MU_RUN_TEST(teste_preco_com_imposto_outros_estados);
}

MU_TEST_SUITE(suite_caderneta) {
    MU_RUN_TEST(teste_cadastro_valido);
    MU_RUN_TEST(teste_cadastro_invalido_idade);
}

// ============================================================================
// 4. EXECUÇÃO PRINCIPAL
// ============================================================================

int main() {
    printf("\n======================================================\n");
    printf("   INICIANDO BATERIA DE TESTES - PROJETO MERCADINHO   \n");
    printf("======================================================\n");
    
    MU_RUN_SUITE(suite_mercadinho);
    MU_RUN_SUITE(suite_usuario);
    MU_RUN_SUITE(suite_produto);
    MU_RUN_SUITE(suite_caderneta);
    
    MU_REPORT();
    
    printf("\nTodos os módulos testados com sucesso.\n");
    return MU_EXIT_CODE;
}
