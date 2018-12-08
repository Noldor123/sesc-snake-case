run:main
	./main
main:main.c
	gcc -std=c99 main.c -ls -o main
build:main
