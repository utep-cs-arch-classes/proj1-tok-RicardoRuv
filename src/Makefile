main: input.o tokenizer.o
	gcc -o test input.o tokenizer.o

input.o: input.c tokenizer.h
	gcc -c input.c

clean:
	rm -f test *.o *~ *#
