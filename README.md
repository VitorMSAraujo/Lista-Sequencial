# Lista Sequencial

Este projeto implementa uma estrutura de **Lista Sequencial** com operações básicas de inserção, remoção, modificação e busca.

## 📎 Estrutura do Projeto

- `controller.cpp` → Arquivo principal que executa os testes.
- `sequencial_list.cpp/.h` → Implementação da estrutura de lista sequencial.
- `entrada.txt` e `entrada_2.txt` → Arquivos de entrada com comandos de teste.
- `saida_esperada.txt` e `saida_esperada_2.txt` → Saídas esperadas para comparação.
- `Makefile` → Facilita a compilação e execução do projeto.

## ⚡ Como Compilar e Executar

1. Compile o programa:

   ```bash
   make
   ```

2. Execute os testes:

   ```bash
   make run
   ```

3. Verifique as saídas:

   ```bash
   cat saida_teste.txt
   cat saida_teste_2.txt
   ```

4. Compare com as saídas esperadas:

   ```bash
   diff -w saida_teste.txt saida_esperada.txt
   diff -w saida_teste_2.txt saida_esperada_2.txt
   ```

   Se ambas as comparações não apresentarem diferenças, os testes passaram com sucesso!

## 🛠 Limpar Arquivos Gerados

Para remover arquivos de saída e o executável, use:

```bash
make clean
```

