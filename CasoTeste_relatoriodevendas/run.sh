#!/bin/bash
set -e
clang -Wall -Wextra -std=c99 -g -o test_relatorio_vendas test_relatorio_vendas.c relatorio_vendas.c -lm
./test_relatorio_vendas
