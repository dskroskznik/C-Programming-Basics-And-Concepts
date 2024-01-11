book_requests: book_requests.o book.o readline.o
	gcc -o book_requests book_requests.o book.o readline.o
book_requests.o: book_requests.c book.h readline.h
	gcc -c book_requests.c 
book.o: book.c book.h readline.h
	gcc -c book.c
readline.o: readline.c readline.h
	gcc -c readline.c
clean:
	rm  book_requests book_requests.o book.o readline.o
