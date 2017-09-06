#
# 統合
#

1.out:main.o menu.o file_in.o linked_list.o linked_list2.o tree.o file_out.o mora.o morabigram.o word.o dictionaryReader.o dictionary.o debug.o
	gcc -O2 -std=gnu99 -o 1.out main.o menu.o file_in.o linked_list.o linked_list2.o tree.o file_out.o mora.o morabigram.o word.o dictionaryReader.o dictionary.o debug.o

main.o:main.c
	gcc -O2 -std=gnu99 -c main.c

menu.o:01/menu.c
	gcc -O2 -std=gnu99 -c 01/menu.c

file_in.o:02/file_in.c
	gcc -O2 -std=gnu99 -c 02/file_in.c

linked_list.o:03/linked_list.c
	gcc -O2 -std=gnu99 -c 03/linked_list.c

linked_list2.o:04/linked_list2.c
	gcc -O2 -std=gnu99 -c 04/linked_list2.c

tree.o:05/tree.c
	gcc -O2 -std=gnu99 -c 05/tree.c

file_out.o:06/file_out.c
	gcc -O2 -std=gnu99 -c 06/file_out.c

mora.o:hayakuchi/mora.c
	gcc -O2 -std=gnu99 -c hayakuchi/mora.c

morabigram.o:hayakuchi/morabigram.c
	gcc -O2 -std=gnu99 -c hayakuchi/morabigram.c

word.o:hayakuchi/word.c
	gcc -O2 -std=gnu99 -c hayakuchi/word.c

dictionaryReader.o:hayakuchi/dictionaryReader.c
	gcc -O2 -std=gnu99 -c hayakuchi/dictionaryReader.c

dictionary.o:hayakuchi/dictionary.c
	gcc -O2 -std=gnu99 -c hayakuchi/dictionary.c

debug.o:hayakuchi/debug.c
	gcc -O2 -std=gnu99 -c hayakuchi/debug.c

clear:
	rm -f *~
