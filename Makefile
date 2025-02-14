all:
	g++ -o lista controller.cpp sequencial_list.cpp

run:
	rm -f saida_teste.txt saida_teste_2.txt  # Remove saídas antigas
	./lista | tee log_execucao.txt
	cat saida_teste.txt
	cat saida_teste_2.txt
	diff -w saida_teste.txt saida_esperada.txt && echo "Teste 1 passou!" || echo "Teste 1 falhou!"
	diff -w saida_teste_2.txt saida_esperada_2.txt && echo "Teste 2 passou!" || echo "Teste 2 falhou!"

clean:
	rm -f lista saida_teste.txt
