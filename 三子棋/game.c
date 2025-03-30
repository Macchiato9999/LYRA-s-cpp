#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

/**
 * ��ʼ������
 * @param board ��������
 * @param row ����
 * @param col ����
 */
void InitBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}

/**
 * ��ӡ����
 * @param board ��������
 * @param row ����
 * @param col ����
 */
void DisplayBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        // ��ӡ����
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        // ��ӡ�ָ���
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
 * �������
 * @param board ��������
 * @param row ����
 * @param col ����
 */
void PlayerMove(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("�������\n");
    while (1) {
        printf("���������꣺>");
        scanf("%d %d", &x, &y);
        // ��Χ�Ϸ����ж�
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (board[x - 1][y - 1] == ' ') {
                board[x - 1][y - 1] = '*';
                break;
            } else {
                printf("���걻ռ�ã��������壬��ѡ������λ��\n");
            }
        } else {
            printf("����Ƿ�������������\n");
        }
    }
}

/**
 * ��������
 * @param board ��������
 * @param row ����
 * @param col ����
 */
void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("�������壺>\n");
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
 * ��������Ƿ�����
 * @param board ��������
 * @param row ����
 * @param col ����
 * @return ���˷���1����������0
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
 * �ж���Ϸ���
 * @param board ��������
 * @param row ����
 * @param col ����
 * @return ���Ӯ���� '*', ����Ӯ���� '#', ƽ�ַ��� 'Q', �������� 'C'
 */
char IsWin(char board[ROW][COL], int row, int col) {
    // ��
    for (int i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
            return board[i][1];
        }
    }

    // ��
    for (int j = 0; j < col; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
            return board[1][j];
        }
    }

    // �Խ���
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
        return board[1][1];
    }

    // û����Ӯ��ƽ��
    if (IsFull(board, row, col)) {
        return 'Q';
    }

    // ��Ϸ����
    return 'C';
}
