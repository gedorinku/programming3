#include <stdio.h>
#include <stdlib.h>
#include "01/menu.h"
#include "02/file_in.h"
#include "03/node.h"
#include "03/linked_list.h"
#include "04/linked_list2.h"
#include "05/tree.h"
#include "06/file_out.h"

struct node* create_list(char eng[][256], char jpn[][256], int count) {
    struct node *init = create_node("", "");
    int i;

    for (i = 0; i < count; ++i) {
        struct node *p = create_node(eng[i], jpn[i]);
        concat_list(p, init);
    }

    return init;
}

struct node2* create_tree(char eng[][256], char jpn[][256], int count) {
    struct node2 *init;
    int i;
    if (count < 0) {
        puts("保存に失敗");
        return NULL;
    }

    init = create_node2("", "");
    for (i = 0; i < count; ++i) {
        struct node2 *p = create_node2(eng[i], jpn[i]);
        insert_tree(p, init);
    }

    return init;
}
    

int main() {
    char eng[20][256], jpn[20][256];
    int count = -1;
    struct node *list = NULL;
    struct node2 *root = NULL;

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

            case 5:
                root = create_tree(eng, jpn, count);
                break;

            case 6:
                if (root == NULL) {
                    puts("標準出力する二分木は存在しない");
                    break;
                }
                print_tree(root);
                break;

            case 7:
                store_dicdata("out1.txt", eng, jpn, count);
                puts("配列をファイルに保存しました。");
                store_list("out2.txt", list->next);
                puts("連結リストをファイルに保存しました。");
                store_tree("out3.txt", root);
                puts("二分木をファイルに保存しました。");
                break;

            case 8:
                print_tree_sorted(root);
                break;

            case 9:
                exit(0);
        }

        puts("");
    }
}
