/*************************************************************************
> File Name: ls_al.c
> Author: gpx
> Mail: 1457495424@qq.com
> Created Time: 2018年09月22日 星期六 19时25分58秒
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define BROWN                "\e[0;33m"
#define NONE                 "\e[0m"
#define BLUE                 "\e[0;34m"

/*****************以下是一些系统自定义结构体****************

struct dirent {
long d_ino;                                  // 索引节点号 
off_t d_off;                                 // 在目录文件中的偏移 
unsigned short d_reclen;                     // 文件名长 
unsigned char d_type;                        // 文件类型 
char d_name [NAME_MAX+1];                    // 文件名，最长255字符 
};

struct stat {
mode_t st_mode;                              // 文件对应的模式，文件、目录等
ino_t st_ino;                                // inode节点号
dev_t st_dev;                                // 设备号码
dev_t st_rdev;                               // 特殊设备号码
nlink_t st_nlink;                            // 文件的连接数
uid_t st_uid;                                // 文件所有者
gid_t st_gid;                                // 文件所有者对应的组
off_t st_size;                               // 普通文件，对应的文件字节数
time_t st_atime;                             // 文件最后被访问的时间
time_t st_mtime;                             // 文件内容最后被修改的时间
time_t st_ctime;                             // 文件状态改变时间
blksize t st_blksize;                        // 文件内容对应的块大小
blkcnt_t st_blocks;                          // 文件内容对应的块数量
};

***********************************************************/


void do_ls(char [], int);
void print(char *ch);
void dostat(char *, char *, int);
void show_stat_info(char *fname, struct stat *, int);
void mode_to_letters(int , char *);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);

int comp(const void *a, const void *b){
    return strcmp((char *)a, (char *)b);
}


void do_ls(char *dirname, int gon) {
    DIR *dir_ptr;
    struct dirent *direntp;
    struct stat dir;
    char name[1000][255];
    int tn = 0;

    if ((dir_ptr = opendir(dirname)) == NULL) {
        printf("ls:connot open %s\n", dirname);
    } else {
        while ((direntp = readdir(dir_ptr)) != NULL) {
            if (gon & 1) {     
                strcpy(name[tn], direntp->d_name);
                tn++;
            } else {
                if (direntp->d_name[0] == '.') continue;
                strcpy(name[tn], direntp->d_name);
                tn++;
            }
        }
    }
    qsort(name, tn, sizeof(name[0]), comp);
    for (int i = 0; i < tn; i++) {
        dostat(name[i], dirname, gon);
    }
    printf("\n");
}

void dostat(char *filename, char *dirname, int gon) {
    struct stat info;
    char pwdname[1000];

    strcpy(pwdname, dirname);
    if (strcmp(dirname, ".") == 0) {
        strcpy(pwdname, filename);
    } else if (strcmp(dirname, "/") == 0) {
        strcat(pwdname, filename);
    } else {
        strcat(strcat(pwdname, "/"), filename);
    }
    if (stat(pwdname, &info) == -1) {
        perror(filename);
    } else {
        show_stat_info(filename, &info,gon);
    }
}

void show_stat_info(char *filename, struct stat *info_p, int gon) {
    char modestr[11];

    mode_to_letters(info_p->st_mode, modestr);
    if (gon & 2) {
        printf("%s", modestr);
        printf("%4d ", (int)info_p->st_nlink);
        printf("%-8s ", uid_to_name(info_p->st_uid));
        printf("%-8s ", gid_to_name(info_p->st_gid));
        printf("%8ld ", (long)info_p->st_size);
        printf("%.12s ", 4 + ctime(&info_p->st_mtime));
        if (modestr[0] == 'd') printf(BROWN "%s\n" NONE, filename);
        else if (modestr[0] == '-') printf(BLUE "%s\n" NONE, filename);
    } else {
        if (modestr[0] == 'd') printf(BROWN "%s " NONE, filename);
        else if (modestr[0] == '-') printf(BLUE "%s " NONE, filename);
    }
}

void mode_to_letters(int mode, char *str){
    strcpy(str,"----------");
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';
    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';
    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';
}

char* uid_to_name(uid_t uid) {
    struct passwd *pw_ptr;
    static char numstr[10];

    if ((pw_ptr = getpwuid(uid)) == NULL) {
        sprintf(numstr,"%d", uid);
        return numstr;
    } else {
        return pw_ptr->pw_name;
    }
}

char* gid_to_name(gid_t gid) {
    struct group *grp_ptr;
    static char numstr[10];

    if ((grp_ptr = getgrgid(gid)) == NULL) {
        sprintf(numstr,"%d", gid);
        return numstr;
    } else {
        return grp_ptr->gr_name;
    }
}

int main(int argc, char **argv) {
    int temp = 0, para;                    //temp = 1, 代表-a; temp = 2, 代表-l; temp = 3, 代表-al;
    *(++argv);
    for(para = 2; para <= argc && (*argv)[0] == '-'; ++argv, para++) {
        strlen(*argv) == 2 && (*argv)[1] == 'a' && (temp |= 1, 1) || (*argv)[1] == 'l' && (temp |= 2, 1);
        strlen(*argv) == 3 && ((*argv)[1] == 'a' && (*argv)[2] == 'l' || (*argv)[1] == 'l' && (*argv)[2] == 'a') && (temp |= 3, 1);
    }
    if (para > argc) {
        do_ls(".", temp);
    } else if (para == argc) {
        do_ls(*argv, temp);
    } else {
        while (para <= argc) {
            printf("%s:\n", *argv);
            do_ls(*argv, temp);
            ++argv;
            para += 1;
        }
    }
    return 0;
}
