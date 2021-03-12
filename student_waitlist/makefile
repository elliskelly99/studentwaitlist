waiting_list: readline.o request.o waiting_list.o
		gcc -o waiting_list readline.o request.o waiting_list.o
readline.o: readline.c readline.h
		gcc -c readline.c
request.o: request.c readline.h request.h
		gcc -c request.c
waiting_list.o: waiting_list.c request.h
		gcc -c	waiting_list.c

