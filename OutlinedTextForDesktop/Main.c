#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OutlinedText.h"

int main(int argc, char* argv[]){
	OutlinedText outlinedText = { 0, };
	char items[ITEMS_COUNT][TEXT_SIZE] = { '\0', };
	int i;
	int count;
	int startPositionXToPrint;
	int startPositionYToPrint;
	printf("���ڿ� ���� �� �Է� : ");
	scanf("%d", &count);
	printf("�ܰ��� ���ڿ� ��� ���� ��ġ �Է� (x, y)\n�ܼ� â ũ�� ����� �ʵ��� ���� : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("���ڿ� ����� �Է�\n");
	for (i = 0; i < count; i++){
		printf("%d ��° : ex) ���ڿ� : ", i + 1);
		fgets(items[i], TEXT_SIZE, stdin);
		items[i][strlen(items[i]) - 1] = '\0';
	}
	system("cls");
	OutlinedText_Create(&outlinedText, items, count, startPositionXToPrint, startPositionYToPrint);
	OutlinedText_Print(&outlinedText);
	return 0;
}