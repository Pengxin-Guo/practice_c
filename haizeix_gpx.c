/*************************************************************************
	> File Name: haizeix_gpx.c
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2018年10月04日 星期四 15时55分57秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *error_msg = NULL;

int app_name_valid(char *argv[]) {
    int i = strlen(argv[0]);
    while (i > 0 && argv[0][i - 1] != '/') --i;
    int ret = (strcmp(argv[0] + i, "haizeix_gpx") == 0);
    error_msg = (char *)(ret ? NULL : "wrong app-name");
    return ret;
}

int user_name_valid(char **env) {
    int ret = 0;
    for (char **p = env; p[0] != NULL; p++) {
        ret = ret || strcmp(p[0], "USER=gpx") == 0;
    }
    error_msg = (char *)(ret ? NULL : "wrong user-name");
    return ret;
}

int main(int argc, char *argv[], char *env[]) {
    if (app_name_valid(argv) == 0) {
        fprintf(stderr, "%s\n", error_msg);
        return 0;
    }
    if (user_name_valid(env) == 0) {
        fprintf(stderr, "%s\n", error_msg);
        return 0;
    }
    printf("Hello Haizei\n");
    return 0;
}
