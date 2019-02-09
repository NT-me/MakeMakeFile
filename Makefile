compil:
	gcc -o MMF MakeMakefile.c -Wall
run: MMF
	./MMF
