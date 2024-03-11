//libraries n stuff
#include <ti/getcsc.h>
#include <compression.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>
#include "gfx/ccsprt.h"
#include "getInput.h"

//frame limit
#define TARGET_FRAMERATE 30
#define TARGET_FRAME_TIME (CLOCKS_PER_SEC / TARGET_FRAMERATE)

//main stuffz
int main(void) {
	
	//setup / initialization
	if (ccsprt_init() == 0) {return 1;}
    gfx_Begin();
	gfx_SetDrawBuffer();
	//sets palette and transparent color
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetTransparentColor(0);
	
	//decompressing spritezzz
	gfx_sprite_t *mouse1;
	mouse1 = gfx_MallocSprite(mouse1_width, mouse1_height);
	zx0_Decompress(mouse1, mouse1_compressed);
	
	gfx_sprite_t *perfectCookie;
	perfectCookie = gfx_MallocSprite(perfectCookie_width, perfectCookie_height);
	zx0_Decompress(perfectCookie, perfectCookie_compressed);
	
	//the endless loop of pain and suffering (for the developer, anyways)
	do {
		//starts frame timer
		clock_t frame_start = clock();
		
		//calls getInput function to, well, get input, and do stuff with said input
		getInput();
		
		//graphics rendering :3
		gfx_FillScreen(2);
		gfx_TransparentSprite(perfectCookie, 9, 74);
		gfx_TransparentSprite(mouse1, mouseX, mouseY);
		gfx_SwapDraw();
		
		//waits until ~1/60th of a second - frame render time to render the next frame
		clock_t frame_time = clock() - frame_start;
		do {frame_time = clock() - frame_start;} while (frame_time < TARGET_FRAME_TIME);
		
	} while(inGame == true);
	
	//ends gfx process and frees memory of pesky lil sprites
    gfx_End();
	free(mouse1);
	free(perfectCookie);
    return 0;
}