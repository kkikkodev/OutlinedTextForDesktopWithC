#ifndef _OUTLINED_TEXT_H
#define _OUTLINED_TEXT_H

#include "TextItem.h"
#include "Point.h"

#define ITEMS_COUNT 20

typedef struct _outlinedText{
	TextItem textItems[ITEMS_COUNT];
	int width;
	int height;
	Point startPositionToPrint;
}OutlinedText;

void OutlinedText_Create(OutlinedText* outlinedText, char(*items)[TEXT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint);
void OutlinedText_Print(OutlinedText* outlinedText);

#endif