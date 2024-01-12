linked_list_test: linked_list_test.o linked_list.o
	gcc -o linked_list_test linked_list_test.o linked_list.o
linked_list_test.o: linked_list_test.c linked_list.h
	gcc -c linked_list_test.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
clean: 
	rm linked_list_test linked_list_test.o linked_list.o

