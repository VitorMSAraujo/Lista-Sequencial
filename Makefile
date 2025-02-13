all:
	g++ -o lista controller.cpp sequencial_list.cpp

run:
	./lista
	diff saida_teste.txt saida_esperada.txt && echo "Teste passou!" || echo "Teste falhou!"

clean:
	rm -f lista saida_teste.txt
