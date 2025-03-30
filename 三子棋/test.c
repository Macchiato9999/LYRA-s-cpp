#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

/**
 * ��Ϸ��ѭ��
 */
void game() {
    printf("ע����������ʱ���������确1 1��\n");
    printf("    ����Ϸ�쳣�򵥣����˵����������\n");
    char result = 0;
    char board[ROW][COL] = { 0 };

    // ��ʼ������
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);

    // ����
    while (1) {
        PlayerMove(board, ROW, COL);
        // �ж���Ӯ
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

    // �ж���Ӯ
    if (result == '*') {
        printf("����˰��������˸�����\n");
    } else if (result == '#') {
        printf("�ⶼӮ���ˣ���Ȼ������~\n");
    } else {
        printf("���㲻�㣬����\n");
    }
    DisplayBoard(board, ROW, COL);
}

/**
 * ��ӡ�˵�
 */
void menu() {
    printf("***************************\n");
    printf("******  1.play  0.exit*****\n");
    printf("***************************\n");
}

int main() {
    srand((unsigned int)time(NULL)); // ������������������

    int input = 0;
    do {
        menu(); // ��ӡ�˵�
        printf("��ѡ��>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                printf("������\n");
                break;
            case 0:
                printf("�˳���Ϸ\n");
                break;
            default:
                printf("ѡ�����\n");
                break;
        }
    } while (input);

    return 0;
}