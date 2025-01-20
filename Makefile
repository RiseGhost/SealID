make:
	echo "Building project"
	gcc -c id.c -o id.o
	gcc id.o teste.c -o teste.out -lcrypto -lm