# pragma once
# include<stdio.h>
#define ROW 3
#define COL 3
#include<stdlib.h>
#include<time.h>
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//���Ӯ-��*��
//����Ӯ-"#"
//ƽ��-��Q"
//����-"C"

char IsWin(char board[ROW][COL], int row, int col);

