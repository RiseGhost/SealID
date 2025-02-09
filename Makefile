make:
	echo "Building project"
	gcc -c id.c -o id.o
	gcc id.o main.c -o run  -lcrypto -lm