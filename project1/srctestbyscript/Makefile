CC = gcc                                             #设置c语言的编译器
CFLAGS = -g -Wall                                    #-g 增加调试信息，-Wall 打开大部分警告信息                   
RM = rm -f

MAINOBJS = ncat.o roman.o                            #整理一下main依赖于哪些文件

.PHONY: clean                                        #.PHONY用于声明一些伪目标 

ncat: $(MAINOBJS)
	$(CC) $(CFLAGS) -o ncat $(MAINOBJS)

roman.o: roman.c roman.h
	$(CC) $(CFLAGS) -c -o roman.o roman.c

ncat.o: ncat.c roman.h
	$(CC) $(CFLAGS) -c -o ncat.o ncat.c

clean:
	$(RM) ncat.o roman.o ncat

