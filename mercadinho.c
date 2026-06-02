#include <stdio.h>
#include <math.h>

int soma (int v1, int v2){
	return v1 + v2;
}

float calcular_subtotal(float preco, int quantidade) {
    return preco * quantidade;
}

float calcular_troco(float valor_pago, float valor_total) {
    if (valor_pago < valor_total) {
        return -1.0;
    }
    return valor_pago - valor_total;
}

float aplicar_desconto(float valor_total, float porcentagem) {
    if (porcentagem < 0.0 || porcentagem > 100.0) {
        return valor_total;
    }
    return valor_total - (valor_total * (porcentagem / 100.0));
}

int validar_estoque(int estoque_disponivel, int quantidade_solicitada) {
    if (quantidade_solicitada <= 0) return 0;
    return estoque_disponivel >= quantidade_solicitada ? 1 : 0;
}