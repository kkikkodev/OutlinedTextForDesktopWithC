#include <stdio.h>
#include <string.h>
#include "OutlinedText.h"
#include "Util.h"

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

void OutlinedText_Create(OutlinedText* outlinedText, char* title, char(*items)[TEXT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint){
	int i;

	// if title length is odd, append blank
	if (strlen(title) % 2){
		strcat(title, " ");
	}

	TextItem_Create(&outlinedText->title, title);
	outlinedText->width = TextItem_GetTotalByte(outlinedText->title);
	for (i = 0; i < count; i++){
		TextItem_Create(outlinedText->textItems + i, items[i]);
		outlinedText->width = MAX(outlinedText->width, TextItem_GetTotalByte(outlinedText->textItems[i]));
	}
	outlinedText->height = count;
	outlinedText->startPositionToPrint.x = startPositionXToPrint;
	outlinedText->startPositionToPrint.y = startPositionYToPrint;
}

void OutlinedText_Print(OutlinedText* outlinedText){
	int topOutlineCount;
	int i;
	int j;
	Point startPositionToPrint = outlinedText->startPositionToPrint;
	outlinedText->width = outlinedText->width % 2 == 1 ? outlinedText->width + 1 : outlinedText->width;
	topOutlineCount = outlinedText->width == TextItem_GetTotalByte(outlinedText->title) ? 0 : outlinedText->width / 2 - TextItem_GetTotalByte(outlinedText->title) / 2;
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	printf("旨");
	if (TextItem_GetTotalByte(outlinedText->title) == 0){
		for (i = 0; i < outlinedText->width / 2; i++){
			printf("收");
		}
	}
	else{
		for (i = 0; i < topOutlineCount / 2; i++){
			printf("收");
		}

		// if top ouline count does not balance, print blank before title
		if (topOutlineCount % 2){
			printf(" ");
		}

		printf("%s", TextItem_GetText(&outlinedText->title));

		// if top ouline count does not balance, print blank after title
		if (topOutlineCount % 2){
			printf(" ");
		}
		for (i = 0; i < topOutlineCount / 2; i++){
			printf("收");
		}
	}
	printf("旬");
	for (i = 0; i < outlinedText->height; i++){
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
		printf("早");
		printf("%s", TextItem_GetText(&outlinedText->textItems[i]));
		for (j = 0; j < outlinedText->width - TextItem_GetTotalByte(outlinedText->textItems[i]); j++){
			printf(" ");
		}
		printf("早");
	}
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	printf("曲");
	for (i = 0; i < outlinedText->width / 2; i++){
		printf("收");
	}
	printf("旭");
}