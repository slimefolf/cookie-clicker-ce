#include <keypadc.h>
#include "getInput.h"

int mouseX = 160;
int mouseY = 120;
int inGame = true;

void getInput(void) {
	//scans the keypad, then checks inputs
	kb_Scan();
	if (kb_Data[6] & kb_Clear) {inGame = false;}
	if (kb_Data[7] & kb_Down) {mouseY += 2;}
	if (kb_Data[7] & kb_Up) {mouseY -= 2;}
	if (kb_Data[7] & kb_Left) {mouseX -= 2;}
	if (kb_Data[7] & kb_Right) {mouseX += 2;}
}