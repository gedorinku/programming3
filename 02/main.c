#include <stdio.h>
#include <stdlib.h>

int load_dicdata(char* filename, char eng[][256], char jpn[][256]);

void print_array(char array[][256], int count);

int main() {
    char eng[20][256];
    char jpn[20][256];
    int count1;

    count1 = load_dicdata("dicdata.txt", eng, jpn);
    
    if (count1 == -1) {
        puts("読み込み失敗");
        return -1;
    }

    puts("読み込み成功");
    printf("%d個の単語を読み込みました\n", count1);

    print_array(eng, count1);
    print_array(jpn, count1);

    return 0;
}
