#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

/**
 * 初始化棋盘
 * @param board 棋盘数组
 * @param row 行数
 * @param col 列数
 */
void InitBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}

/**
 * 打印棋盘
 * @param board 棋盘数组
 * @param row 行数
 * @param col 列数
 */
void DisplayBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        // 打印数据
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        // 打印分割线
        if (i < row - 1) {
            for (int j = 0; j < col; j++) {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

/**
 * 玩家下棋
 * @param board 棋盘数组
 * @param row 行数
 * @param col 列数
 */
void PlayerMove(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("玩家下棋\n");
    while (1) {
        printf("请输入坐标：>");
        scanf("%d %d", &x, &y);
        // 范围合法的判断
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (board[x - 1][y - 1] == ' ') {
                board[x - 1][y - 1] = '*';
                break;
            } else {
                printf("坐标被占用，不能下棋，请选择其他位置\n");
            }
        } else {
            printf("坐标非法，请重新输入\n");
        }
    }
}

/**
 * 电脑下棋
 * @param board 棋盘数组
 * @param row 行数
 * @param col 列数
 */
void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("电脑下棋：>\n");
    int x = 0;
    int y = 0;
    while (1) {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ') {
            board[x][y] = '#';
            break;
        }
    }
}

/**
 * 检查棋盘是否已满
 * @param board 棋盘数组
 * @param row 行数
 * @param col 列数
 * @return 满了返回1，不满返回0
 */
int IsFull(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * 判断游戏结果
 * @param board 棋盘数组
 * @param row 行数
 * @param col 列数
 * @return 玩家赢返回 '*', 电脑赢返回 '#', 平局返回 'Q', 继续返回 'C'
 */
char IsWin(char board[ROW][COL], int row, int col) {
    // 行
    for (int i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
            return board[i][1];
        }
    }

    // 列
    for (int j = 0; j < col; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
            return board[1][j];
        }
    }

    // 对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
        return board[1][1];
    }

    // 没有人赢，平局
    if (IsFull(board, row, col)) {
        return 'Q';
    }

    // 游戏继续
    return 'C';
}
