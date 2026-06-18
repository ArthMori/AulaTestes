#ifndef MATEMATICA_H
#define MATEMATICA_H

// --- Mercadinho ---
int soma(int v1, int v2);
float calcular_subtotal(float preco, int quantidade);
float calcular_troco(float valor_pago, float valor_total);
float aplicar_desconto(float valor_total, float porcentagem);
int validar_estoque(int estoque_disponivel, int quantidade_solicitada);

// --- Usuario ---
int validarSenha(char senha[]);

// --- Produto ---
float Preco_Final_Cons(float preco_f);
float stub_buscar_imposto_bd(int id_estado);
float Preco_Com_Imposto(float preco_base, int id_estado);

// --- Caderneta ---
int teste_cadastro_usuario(char *nome, int idade);

#endif
