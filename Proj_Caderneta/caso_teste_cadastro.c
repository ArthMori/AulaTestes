#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Valida os dados para abertura de conta na caderneta (fiado).
 * @param nome Nome do cliente (string).
 * @param idade Idade do cliente (int).
 * @return 1 se os dados forem validos, 0 caso o nome seja vazio ou idade invalida.
 */
int teste_cadastro_usuario(char *nome, int idade){
    if(strlen(nome) == 0 || idade <= 0){
        return 0;
    }
    else{
        return 1;
    }
}