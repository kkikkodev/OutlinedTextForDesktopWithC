#include <string.h>
#include "TextItem.h"

void TextItem_Create(TextItem* textItem, char* text){
	unsigned int i;
	strcpy(textItem->text, text);
	textItem->totalByte = 0;
	for (i = 0; i < strlen(text); i++){
		textItem->totalByte++;
		if (!(text[i] >= 0 && text[i] < TEXT_SIZE)){
			textItem->totalByte++;
			i++;
		}
	}
}