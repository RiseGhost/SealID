make:
	echo "Building project"
	gcc -c id.c -o id.o
	gcc -c token.c -o token.o
	gcc id.o token.o teste.c -o teste.out  -lcrypto -lm