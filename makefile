
ifndef VERBOSE
.SILENT:
endif

ARG=10

main: main.c
	gcc -o vbak main.c

run: main.c
	make 1> /dev/null
	sudo chown root:root ./vbak
	sudo chmod +s ./vbak
	./vbak $(ARG)
	rm vbak -f
