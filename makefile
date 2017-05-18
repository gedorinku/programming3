#
# 統合
#

1.out:main.o menu.o file_in.o
	gcc -o 1.out main.o menu.o file_in.o

main.o:main.c
	gcc -c main.c

menu.o:01/menu.c
	gcc -c 01/menu.c

file_in.o:02/file_in.c
	gcc -c 02/file_in.c

clear:
	rm -f *~

