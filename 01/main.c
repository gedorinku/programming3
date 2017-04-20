#include <stdio.h>
#include <stdlib.h>

int print_menu();

int load_dicdata(char *filename, char eng[][256], char jpn[][256]);

void print_array(char a[][256], int);

int main() {
    char eng[20][256], jpn[20][256];
    int count = -1;

    while (1) {
        int menu_num = print_menu();
        
        if (menu_num == 9) {
            exit(0);
        }
        switch (menu_num) {
            case 1:
                count = load_dicdata("dicdata.txt", eng, jpn);
                if (count == -1) {
                    puts("読み込み失敗");
                    exit(-1);
                }
                puts("読み込み成功");
                printf("単語数%d\n", count);
                break;

            case 2:
                if (count == -1) {
                    puts("単語が読み込まれていません");
                    break;
                }
                print_array(eng, count);
                print_array(jpn, count);
                break;
            case 9:
                exit(0);
        }

        puts("");
    }
}
