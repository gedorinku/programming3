#include <stdio.h>
#include <stdlib.h>
#include "01/menu.h"
#include "02/file_in.h"
#include "03/node.h"
#include "03/linked_list.h"
#include "04/linked_list2.h"


struct node* create_list(char eng[][256], char jpn[][256], int count) {
    struct node *init = create_node("", "");
    int i;

    for (i = 0; i < count; ++i) {
        struct node *p = create_node(eng[i], jpn[i]);
        concat_list(p, init);
    }

    return init;
}

int main() {
    char eng[20][256], jpn[20][256];
    int count = -1;
    struct node *list = NULL;

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

            case 3:
                if (count < 0) {
                    puts("保存に失敗");
                    break;
                }
                destory_list(list);
                list = create_list(eng, jpn, count);
                break;

            case 4:
                if (list == NULL) {
                    puts("標準出力する連結リストは存在しない");
                    break;
                }
                print_list(list->next);
                break;

            case 9:
                exit(0);
        }

        puts("");
    }
}
