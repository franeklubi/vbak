
ifndef VERBOSE
.SILENT:
endif

ARG=10

main: main.c
	gcc -o vbak main.c

permissions: main.c
	make
	sudo chown root:root ./vbak
	sudo chmod +s ./vbak

install: main.c
	make permissions
	sudo mv vbak /bin/

run: main.c
	make 1> /dev/null
	make permissions
	./vbak $(ARG)
	rm vbak -f
