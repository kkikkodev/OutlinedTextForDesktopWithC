#include <stdio.h>
#include "OutlinedText.h"
#include "Util.h"

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

void OutlinedText_Create(OutlinedText* outlinedText, char(*items)[TEXT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint){
	int i;
	outlinedText->width = 0;
	for (i = 0; i < count; i++){
		TextItem_Create(outlinedText->textItems + i, items[i]);
		outlinedText->width = MAX(outlinedText->width, outlinedText->textItems[i].totalByte);
	}
	outlinedText->height = count;
	outlinedText->startPositionToPrint.x = startPositionXToPrint;
	outlinedText->startPositionToPrint.y = startPositionYToPrint;
}

void OutlinedText_Print(OutlinedText* outlinedText){
	int i;
	int j;
	int x = outlinedText->startPositionToPrint.x;
	int y = outlinedText->startPositionToPrint.y;
	outlinedText->width = outlinedText->width % 2 == 1 ? outlinedText->width + 1 : outlinedText->width;
	CursorUtil_GotoXY(x, y++);
	printf("旨");
	for (i = 0; i < outlinedText->width / 2; i++){
		printf("收");
	}
	printf("旬");
	for (i = 0; i < outlinedText->height; i++){
		CursorUtil_GotoXY(x, y++);
		printf("早");
		printf("%s", outlinedText->textItems[i].text);
		for (j = 0; j < outlinedText->width - outlinedText->textItems[i].totalByte; j++){
			printf(" ");
		}
		printf("早");
	}
	CursorUtil_GotoXY(x, y++);
	printf("曲");
	for (i = 0; i < outlinedText->width / 2; i++){
		printf("收");
	}
	printf("旭");
}