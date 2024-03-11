#include "ccsprt.h"
#include <fileioc.h>

#define ccsprt_HEADER_SIZE 0

unsigned char *ccsprt_appvar[3] =
{
    (unsigned char*)0,
    (unsigned char*)26,
    (unsigned char*)79,
};

unsigned char ccsprt_init(void)
{
    unsigned int data, i;
    uint8_t appvar;

    appvar = ti_Open("ccsprt", "r");
    if (appvar == 0)
    {
        return 0;
    }

    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)ccsprt_appvar[0] + ccsprt_HEADER_SIZE;
    for (i = 0; i < 3; i++)
    {
        ccsprt_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

