
ifndef VERBOSE
.SILENT:
endif


main: main.c
	gcc -o vbak main.c

run: main.c
	make 1> /dev/null
	./vbak 15
	rm vbak
