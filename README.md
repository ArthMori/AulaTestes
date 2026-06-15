# Projeto Mercadinho - Engenharia de Software

Este repositório contém a Parte 2 do projeto de um sistema de mercadinho, focado em **Arquitetura, Testes e Qualidade de Software**.

## 🛠️ Estratégia de Versionamento (Git)

Para manter a organização e o fluxo de trabalho em equipe, adotamos as seguintes práticas:

* **Estratégia de Branches:** * `main`: Branch principal, contendo apenas código testado, documentado e funcional (Definition of Done cumprido).
  * `feature/*` ou `test/*`: Branches temporárias criadas para o desenvolvimento de novas lógicas ou adição de testes (ex: `feature/cadastro-produto`, `test/valida-senha`).
* **Padrão de Commits:**
  * Utilizamos a convenção de *Conventional Commits* para manter o histórico claro:
    * `feat:` Para novas funcionalidades.
    * `test:` Para criação ou alteração de testes unitários (MinUnit).
    * `docs:` Para inserção de documentação (Doxygen).
    * `fix:` Para correção de bugs.
* **Integração e Merges:**
  * O código só é integrado à `main` após a funcionalidade possuir seu caso de teste correspondente e documentação técnica, garantindo a qualidade.

## 🧪 Estratégia de Testes e Qualidade
* Foram elaborados 15 casos de testes estruturados cobrindo cenários válidos, alternativos e de exceção.
* Utilizamos a biblioteca **MinUnit** para rodar os testes unitários.
* A simulação de banco de dados e impostos foi feita através da implementação de **Stubs**.

## 📚 Documentação
Toda a documentação técnica dos protótipos, parâmetros e retornos foi feita diretamente no código fonte utilizando o padrão **Doxygen**.

---

### ⚙️ Como gerar a documentação (Doxygen)
O projeto já está pré-configurado. Para gerar ou atualizar a documentação visual (HTML) após fazer alguma alteração no código, siga os passos abaixo:

1. Abra o aplicativo **Doxywizard** na sua máquina.
2. No menu superior, clique em `File` > `Open...`.
3. Selecione o arquivo `Doxyfile` que está na raiz deste repositório. *(Isso vai carregar todas as configurações do nosso projeto automaticamente)*.
4. Vá direto para a aba **Run**.
5. Clique no botão **Run doxygen**.
6. **Pronto!** Vá até a pasta `Docs/html` e abra o arquivo `index.html` no seu navegador para ver o site da documentação atualizado.

---
## Para o grupo:
Guia rápido de comandos básicos para subirmos as alterações:

```bash
git clone "link do repositório"

cd "nome da pasta"

cd .. (voltar)

git add . (todos os arquivos da pasta)

git commit -m "mensagem"

git push origin main *(recomendo dar o git pull antes, para ver se está tudo atualizado)*