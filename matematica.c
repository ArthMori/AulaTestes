#include <string.h>
#include <ctype.h>
#include "matematica.h"

// ==========================================
// MÓDULO 1: MERCADINHO (Caixa e Estoque)
// ==========================================
int soma(int v1, int v2) { return v1 + v2; }
float calcular_subtotal(float preco, int quantidade) { return preco * quantidade; }

float calcular_troco(float valor_pago, float valor_total) { 
    if (valor_pago < valor_total) return -1.0; 
    return valor_pago - valor_total; 
}

float aplicar_desconto(float valor_total, float porcentagem) { 
    if (porcentagem < 0.0 || porcentagem > 100.0) return valor_total; 
    return valor_total - (valor_total * (porcentagem / 100.0)); 
}

int validar_estoque(int estoque_disponivel, int quantidade_solicitada) { 
    if (quantidade_solicitada <= 0) return 0; 
    return estoque_disponivel >= quantidade_solicitada ? 1 : 0; 
}

// ==========================================
// MÓDULO 2: USUÁRIO (Senha)
// ==========================================
int validarSenha(char senha[]) {
    int i, senha_letra = 0, senha_num = 0;
    
    if(strlen(senha) > 6 || strlen(senha) == 0) return 0;
    for(i = 0; i < strlen(senha); i++) {
        if(isalpha(senha[i])) senha_letra = 1;
        if(isdigit(senha[i])) senha_num = 1;
    }
    if(senha_letra && senha_num)
        return 1;
    else {
    	return 0;
	}

}

// ==========================================
// MÓDULO 3: PRODUTO (Impostos e Margem)
// ==========================================
float Preco_Final_Cons(float preco_f){ 
    return (preco_f * 0.6) + preco_f; 
}

float stub_buscar_imposto_bd(int id_estado) { 
    if (id_estado == 1) return 0.10; 
    return 0.05; 
}

float Preco_Com_Imposto(float preco_base, int id_estado) { 
    float imposto = stub_buscar_imposto_bd(id_estado); 
    return preco_base + (preco_base * imposto); 
}

// ==========================================
// MÓDULO 4: CADERNETA (Fiado)
// ==========================================
int teste_cadastro_usuario(char *nome, int idade){
    if(strlen(nome) == 0 || idade <= 0) return 0;
    return 1;
}
