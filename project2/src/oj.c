#include <stdio.h>
#include "run.h"

int main()
{
    const char *name_program = "./program";
    const char *name_in = "./in.txt";
    const char *name_out = "./out.txt";
    const char *name_right = "./right.txt";
    run(name_program, name_in, name_out);
    FILE *fpright = fopen(name_right, "r");
    FILE *fpout = fopen(name_out, "r");

    // Input your code here.
    char c1, c2;
    while (c1 = fgetc(fpright), c2 = getc(fpout), c1 != EOF && c2 != EOF && c1 == c2) ;
    if (c1 != EOF && c2 != EOF) {                                           //c1,c2都没读到文件尾，说明出现了不一样的字符
        printf("Wrong Answer\n");
    } else if (c1 == c2) {                                                  //此时是c1 == EOF && c2 == EOF,都读到了文件尾，说明两个文件内容一样
        printf("Accept\n");
    } else {                                                                //c1与c2有一个读到了文件尾
        if (c1 != '\n' && c2 != '\n') {                                     //一个文件读完后，另一个文件出现了换行之外的其他字符
            printf("Wrong Answer\n");
        } else {
            c1 == EOF ? (c2 = fgetc(fpout)) : (c1 = getc(fpright));         //吃掉多出来的一个换行
            printf("%s\n", c1 == c2 ? "Accept" : "Wrong Answer");           //c1与c2是否都读到了文件尾
        }
    }
    fclose(fpout);
    fclose(fpright);
    return 0;
}
