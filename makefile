#
# 統合
#

1.out:main.o menu.o file_in.o linked_list.o linked_list2.o tree.o
	gcc -o 1.out main.o menu.o file_in.o linked_list.o linked_list2.o tree.o

main.o:main.c
	gcc -c main.c

menu.o:01/menu.c
	gcc -c 01/menu.c

file_in.o:02/file_in.c
	gcc -c 02/file_in.c

linked_list.o:03/linked_list.c
	gcc -c 03/linked_list.c

linked_list2.o:04/linked_list2.c
	gcc -c 04/linked_list2.c

tree.o:05/tree.c
	gcc -c 05/tree.c

clear:
	rm -f *~

