//
// Created by manu on 9/17/23.
//

#include "ui/userapps.h"
#include "app/userapps.h"
#include "helper.h"
#include "driver/st7565.h"


void USERAPPS_draw(uint8_t offset){
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
    for (uint8_t i = 0; i < 3; ++i) {
        UI_PrintString(menu_items[offset],0, 128, i*2, 8,false);
        offset++;
        if(offset >= sizeof(menu_items)/sizeof(menu_items[0]))
            break;
    }
    for (uint8_t i = 0; i < 128; ++i) {
        gFrameBuffer[0][i] ^= 0xFF;
        gFrameBuffer[1][i] ^= 0xFF;
    }
    ST7565_BlitFullScreen();
}
