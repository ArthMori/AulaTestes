#include <stdio.h>
#include <math.h>

/**
 * @brief Realiza a soma de dois valores inteiros.
 * @param v1 Primeiro valor inteiro.
 * @param v2 Segundo valor inteiro.
 * @return Resultado da soma de v1 e v2.
 */
int soma (int v1, int v2){
	return v1 + v2;
}

/**
 * @brief Calcula o subtotal de um item baseado no preco e quantidade.
 * @param preco Valor unitario do produto (float).
 * @param quantidade Quantidade de itens comprados (int).
 * @return O valor do subtotal (preco * quantidade).
 */
float calcular_subtotal(float preco, int quantidade) {
    return preco * quantidade;
}

/**
 * @brief Calcula o troco a ser devolvido ao cliente.
 * @param valor_pago O valor entregue pelo cliente (float).
 * @param valor_total O valor total da compra (float).
 * @return O valor do troco. Retorna -1.0 se o valor pago for insuficiente.
 */
float calcular_troco(float valor_pago, float valor_total) {
    if (valor_pago < valor_total) {
        return -1.0;
    }
    return valor_pago - valor_total;
}

/**
 * @brief Aplica um percentual de desconto no valor total.
 * @param valor_total Valor bruto da compra (float).
 * @param porcentagem Percentual de desconto a ser aplicado (0.0 a 100.0).
 * @return O valor com desconto. Retorna o valor original se a porcentagem for invalida.
 */
float aplicar_desconto(float valor_total, float porcentagem) {
    if (porcentagem < 0.0 || porcentagem > 100.0) {
        return valor_total;
    }
    return valor_total - (valor_total * (porcentagem / 100.0));
}

/**
 * @brief Valida se ha estoque suficiente para realizar a venda.
 * @param estoque_disponivel Quantidade atual no estoque (int).
 * @param quantidade_solicitada Quantidade que o cliente deseja (int).
 * @return 1 se houver estoque suficiente e o pedido for valido (>0), 0 caso contrario.
 */
int validar_estoque(int estoque_disponivel, int quantidade_solicitada) {
    if (quantidade_solicitada <= 0) return 0;
    return estoque_disponivel >= quantidade_solicitada ? 1 : 0;
}