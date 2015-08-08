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
	printf("문자열 라인 수 입력 : ");
	scanf("%d", &count);
	printf("외곽선 문자열 출력 시작 위치 입력 (x, y)\n콘솔 창 크기 벗어나지 않도록 주의 : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("문자열 내용들 입력\n");
	for (i = 0; i < count; i++){
		printf("%d 번째 : ex) 문자열 : ", i + 1);
		fgets(items[i], TEXT_SIZE, stdin);
		items[i][strlen(items[i]) - 1] = '\0';
	}
	system("cls");
	OutlinedText_Create(&outlinedText, items, count, startPositionXToPrint, startPositionYToPrint);
	OutlinedText_Print(&outlinedText);
	return 0;
}