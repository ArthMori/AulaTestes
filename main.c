#include <stdio.h>
#include <math.h>
#include "minunit.h"
#include "matematica.h"

// =========================================================
// TESTES DO MERCADINHO (CAIXA E ESTOQUE)
// =========================================================

MU_TEST(test_soma){
	mu_assert(
		soma(10, 5) == 15,
		"ERRO NA SOMA"
	);
}

MU_TEST(test_calcular_subtotal){
	mu_assert(
		calcular_subtotal(10.0, 5) == 50.0,
		"ERRO NO SUBTOTAL"
	);
}

MU_TEST(test_calcular_troco){
	mu_assert(
		calcular_troco(50.0, 40.0) == 10.0,
		"ERRO NO TROCO"
	);
}

MU_TEST(test_troco_negativo){
	mu_assert(
		calcular_troco(10.0, 40.0) == -1.0,
		"ERRO NO TROCO NEGATIVO"
	);
}

MU_TEST(test_aplicar_desconto){
	mu_assert(
		aplicar_desconto(100.0, 10.0) == 90.0,
		"ERRO NO DESCONTO"
	);
}

MU_TEST(test_validar_estoque){
	mu_assert(
		validar_estoque(10, 5) == 1,
		"ERRO NO ESTOQUE"
	);
}

// =========================================================
// TESTES DE USUÁRIO (VALIDAÇÃO DE SENHA)
// =========================================================

MU_TEST(teste_senha_valida){
	mu_assert(
		validarSenha("abc123") == 1,
		"ERRO: SENHA VALIDA BLOQUEADA"
	);
}

MU_TEST(teste_sem_numero){
	mu_assert(
		validarSenha("abcdef") == 0,
		"ERRO: SENHA SEM NUMERO ACEITA"
	);
}

MU_TEST(teste_sem_letra){
	mu_assert(
		validarSenha("123456") == 0,
		"ERRO: SENHA SEM LETRA ACEITA"
	);
}

MU_TEST(teste_maior_que_6){
	mu_assert(
		validarSenha("abc1234") == 0,
		"ERRO: SENHA MAIOR QUE 6 ACEITA"
	);
}

MU_TEST(teste_senha_vazia){
	mu_assert(
		validarSenha("") == 0,
		"ERRO: SENHA VAZIA ACEITA"
	);
}

// =========================================================
// TESTES DE PRODUTO (MARGEM E IMPOSTOS)
// =========================================================

MU_TEST(teste_preco_100){
	mu_assert(
		Preco_Final_Cons(100.0) == 160.0,
		"ERRO NA MARGEM DE LUCRO"
	);
}

MU_TEST(teste_preco_zero){
	mu_assert(
		Preco_Final_Cons(0.0) == 0.0,
		"ERRO NO PRECO ZERO"
	);
}

MU_TEST(teste_preco_quebrado){
	mu_assert(
		fabs(Preco_Final_Cons(50.5) - 80.8) < 0.1,
		"ERRO NO PRECO QUEBRADO"
	);
}

MU_TEST(teste_preco_com_imposto_estado_1){
	mu_assert(
		Preco_Com_Imposto(100.0, 1) == 110.0,
		"ERRO NO IMPOSTO DO ESTADO 1"
	);
}

MU_TEST(teste_preco_com_imposto_outros_estados){
	mu_assert(
		Preco_Com_Imposto(100.0, 2) == 105.0,
		"ERRO NO IMPOSTO DE OUTROS ESTADOS"
	);
}

// =========================================================
// TESTES DA CADERNETA (FIADO)
// =========================================================

MU_TEST(teste_cadastro_valido){
	mu_assert(
		teste_cadastro_usuario("Gabriel", 18) == 1,
		"ERRO NO CADASTRO VALIDO"
	);
}

MU_TEST(teste_cadastro_invalido_idade){
	mu_assert(
		teste_cadastro_usuario("Gabriel", -5) == 0,
		"ERRO NA IDADE INVALIDA"
	);
}

// =========================================================
// SUÍTE UNIFICADA DE TESTES
// =========================================================

MU_TEST_SUITE(test_suite){
	// Mercadinho
	MU_RUN_TEST(test_soma);
	MU_RUN_TEST(test_calcular_subtotal);
	MU_RUN_TEST(test_calcular_troco);
	MU_RUN_TEST(test_troco_negativo);
	MU_RUN_TEST(test_aplicar_desconto);
	MU_RUN_TEST(test_validar_estoque);
	
	// Usuário
	MU_RUN_TEST(teste_senha_valida);
	MU_RUN_TEST(teste_sem_numero);
	MU_RUN_TEST(teste_sem_letra);
	MU_RUN_TEST(teste_maior_que_6);
	MU_RUN_TEST(teste_senha_vazia);
	
	// Produto
	MU_RUN_TEST(teste_preco_100);
	MU_RUN_TEST(teste_preco_zero);
	MU_RUN_TEST(teste_preco_quebrado);
	MU_RUN_TEST(teste_preco_com_imposto_estado_1);
	MU_RUN_TEST(teste_preco_com_imposto_outros_estados);
	
	// Caderneta
	MU_RUN_TEST(teste_cadastro_valido);
	MU_RUN_TEST(teste_cadastro_invalido_idade);
}

// =========================================================
// EXECUÇÃO PRINCIPAL
// =========================================================

int main(){
	printf("\n--- Testes do Projeto Mercadinho ---\n");
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
