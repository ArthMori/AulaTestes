#ifndef RELATORIO_VENDAS_H
#define RELATORIO_VENDAS_H

typedef struct {
    int quantidade;
    float preco_unitario;
} Venda;

float calcular_total_venda(Venda venda);
float calcular_faturamento_total(Venda vendas[], int n);
int calcular_total_itens_vendidos(Venda vendas[], int n);

#endif
