# Projeto Mercadinho - Engenharia de Software

Este repositório contém a entrega final do projeto de um sistema de mercadinho, focado e concluído com base nos pilares de **Arquitetura, Testes e Qualidade de Software**. O desenvolvimento desta etapa está finalizado, refletindo a versão consolidada e 100% funcional do código.

## 🧪 Estratégia de Testes e Qualidade
* Foram elaborados 15 casos de testes estruturados cobrindo cenários válidos, alternativos e de exceção.
* Utilizamos a biblioteca **MinUnit** para rodar os testes unitários.
* A simulação de banco de dados e impostos foi feita através da implementação de **Stubs**.

## 📚 Documentação
Toda a documentação técnica dos protótipos, parâmetros e retornos foi construída diretamente no código fonte utilizando o padrão **Doxygen**.

---

### ⚙️ Como gerar a documentação (Doxygen)
O projeto já está pré-configurado. Para gerar ou atualizar a documentação visual (HTML) caso seja feito algum ajuste final no código, siga os passos abaixo:

1. Abra o aplicativo **Doxywizard** na sua máquina.
2. No menu superior, clique em `File` > `Open...`.
3. Selecione o arquivo `Doxyfile` que está na raiz deste repositório. *(Isso vai carregar todas as configurações do nosso projeto automaticamente)*.
4. Vá direto para a aba **Run**.
5. Clique no botão **Run doxygen**.
6. **Pronto!** Vá até a pasta `Docs/html` e abra o arquivo `index.html` no seu navegador para ver o site da documentação atualizado.

---

## Para o grupo:
Guia rápido de comandos básicos, caso precisemos subir alguma alteração de última hora:

```bash
git clone "link do repositório"

cd "nome da pasta"

cd .. (voltar)

git add . (todos os arquivos da pasta)

git commit -m "mensagem"

git push origin main *(recomendo dar o git pull antes, para ver se está tudo atualizado)*
