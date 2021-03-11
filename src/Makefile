main: input.o tokenizer.o history.o
	gcc -o test input.o tokenizer.o history.o

input.o: input.c tokenizer.h history.h
	gcc -c input.c
tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c

history.o: history.c history.h
	gcc -c history.c

clean:
	rm -f test *.o *~ *#
