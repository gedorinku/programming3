#include <stdio.h>
#include <stdlib.h>

const char MENU[][256] = {"1.ファイルの読み込み",
                       "2.配列の内容を標準出力",
                       "3.連結リストに保存",
                       "4.連結リストの内容を標準出力",
                       "5.二分木に保存",
                       "6.二分木の内容を標準出力",
                       "7.ファイルの書き出し",
                       "8.オリジナル機能",
                       "9.終了"};

int main() {
    int menu_num, i;

    for (i = 1; i <= 9; ++i) {
        puts(MENU[i - 1]);
    }

    printf("> ? ");
    scanf(" %d", &menu_num);
    puts(MENU[menu_num - 1]);

    if (menu_num == 0) {
        exit(0);
    }

    return 0;
}
