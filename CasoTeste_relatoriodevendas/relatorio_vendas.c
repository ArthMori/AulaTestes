#include "relatorio_vendas.h"

float calcular_total_venda(Venda venda) {
    return venda.quantidade * venda.preco_unitario;
}

float calcular_faturamento_total(Venda vendas[], int n) {
    float total = 0;
    int i;

    for (i = 0; i < n; i++) {
        total = total + calcular_total_venda(vendas[i]);
    }

    return total;
}

int calcular_total_itens_vendidos(Venda vendas[], int n) {
    int total = 0;
    int i;

    for (i = 0; i < n; i++) {
        total = total + vendas[i].quantidade;
    }

    return total;
}
