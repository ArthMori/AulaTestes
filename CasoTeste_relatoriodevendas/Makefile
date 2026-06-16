CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm

TARGET = test_relatorio_vendas
SRCS = test_relatorio_vendas.c relatorio_vendas.c

.PHONY: all test clean

all: $(TARGET)

$(TARGET): $(SRCS) relatorio_vendas.h minunit.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
