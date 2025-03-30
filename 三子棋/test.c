#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

/**
 * 游戏主循环
 */
void game() {
    printf("注：输入坐标时请这样：如‘1 1’\n");
    printf("    此游戏异常简单，输了的是这个（）\n");
    char result = 0;
    char board[ROW][COL] = { 0 };

    // 初始化棋盘
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);

    // 下棋
    while (1) {
        PlayerMove(board, ROW, COL);
        // 判断输赢
        result = IsWin(board, ROW, COL);
        if (result != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);

        ComputerMove(board, ROW, COL);
        result = IsWin(board, ROW, COL);
        if (result != 'C') {
            break;
        }
        DisplayBoard(board, ROW, COL);
    }

    // 判断输赢
    if (result == '*') {
        printf("这个运啊，给你了给你了\n");
    } else if (result == '#') {
        printf("这都赢不了，果然是杂鱼~\n");
    } else {
        printf("不算不算，再来\n");
    }
    DisplayBoard(board, ROW, COL);
}

/**
 * 打印菜单
 */
void menu() {
    printf("***************************\n");
    printf("******  1.play  0.exit*****\n");
    printf("***************************\n");
}

int main() {
    srand((unsigned int)time(NULL)); // 设置随机数的生成起点

    int input = 0;
    do {
        menu(); // 打印菜单
        printf("请选择：>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                printf("三子棋\n");
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    } while (input);

    return 0;
}