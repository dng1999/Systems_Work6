compile:
	gcc main.c

run: a.out
	./a.out

clean:
	rm *~
	rm sigmsg.txt