all: sorted-list.o main.o libsl.a create

create:
	gcc -Wall -Werror -g -o sl sorted-list.c main.c
sorted-list.o: sorted-list.c sorted-list.h
	gcc -Wall -Werror -g -c sorted-list.c
main.o: main.c
	gcc -Wall -Werror -g -c main.c
libsl.a:
	ar r libsl.a sorted-list.o main.o
clean:
	rm -rf *.o