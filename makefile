.PHONY: run compile clean
run: fork
	@./fork
compile fork: main.o
	@gcc -o fork main.o
main.o: main.c
	@gcc -c main.c
clean:
	rm -f *.o fork
