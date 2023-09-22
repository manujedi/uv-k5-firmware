/* Copyright 2023 Manuel Jedinger
 * https://github.com/manujedi
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include "userapps.h"
#include "driver/keyboard.h"
#include "ui/userapps.h"
#include "driver/system.h"
#include "userapp_ranking.h"
#include "app/spectrum.h"
#include "board.h"
#include "ui/helper.h"
#include "driver/st7565.h"
#include "misc.h"

char menu_items[][15] = {
#if defined(ENABLE_CHANNEL_SCAN)
        "Ranking",
#else
        "Not Enabled",
#endif
#if defined(ENABLE_MINIMAL_SPECTRUM)
        "Spectrum",
#else
        "Not Enabled",
#endif
        "Temp",
};

KEY_Code_t USERAPPS_GetInput(void){
    static KEY_Code_t currentKey;
    static KEY_Code_t lastKey = KEY_EXIT;   //eat the first exit key
    currentKey = KEYBOARD_Poll();

    static uint8_t scroll = 20;

    if(lastKey != currentKey) {
        lastKey = currentKey;
        scroll = 20;
        return currentKey;
    }
    if(currentKey == KEY_INVALID)
        scroll = 20;
    else
        scroll = scroll == 0 ? 0 : scroll-1;

    if(scroll == 0) {
        scroll = 2; //scrollspeed
        return currentKey;
    }

    return KEY_INVALID;
}

void printTemp(){
    KEY_Code_t key = KEY_INVALID;
    uint8_t refresh = 0;

    while (key != KEY_EXIT) {

        key = USERAPPS_GetInput();

        if (refresh == 0) {
            uint16_t raw = 0;
            int16_t temp = 0;
            BOARD_ADC_GetDieTemp(&temp, &raw);

            memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
            char String[16];

            sprintf(String, "%i.%iC", temp/10, temp%10);
            UI_PrintStringSmall(String, 0, 127, 1, 7, true);

            sprintf(String, "ADC: %i", raw);
            UI_PrintStringSmall(String, 0, 127, 2, 7, true);

            ST7565_BlitFullScreen();
        }

        SYSTEM_DelayMs(10);
        refresh = refresh == 0 ? 100 : refresh-1;

    }
}


void USERAPPS_startapp(uint8_t selection){
    switch (selection) {
        case 0:
#if defined(ENABLE_CHANNEL_SCAN)
            USERAPP_ranking_init();
#endif
            break;
        case 1:
#if defined(ENABLE_MINIMAL_SPECTRUM)
            spectrum_init();
#endif
            break;
        case 2:
            printTemp();
        default:
            break;
    }

}

void USERAPPS_init(void){
    USERAPPS_loop();
    gUpdateDisplay=true;
}

void USERAPPS_loop(void){
    uint8_t selection = 0;

    KEY_Code_t key = KEY_INVALID;

    while (key != KEY_EXIT) {

        key = USERAPPS_GetInput();

        switch (key) {
            case KEY_0 ... KEY_9:
                break;
            case KEY_UP:
                selection = selection == 0 ? 0 : selection - 1;
                break;
            case KEY_DOWN:
                if(selection < sizeof(menu_items)/sizeof(menu_items[0]) - 1)
                    selection++;
                break;
            case KEY_EXIT:
                break;
            case KEY_STAR:
                break;
            case KEY_F:
                break;
            case KEY_PTT:
                break;
            case KEY_SIDE2:
                break;
            case KEY_SIDE1:
                break;
            case KEY_INVALID:
                break;
            case KEY_MENU:
                USERAPPS_startapp(selection);
                break;
        }

        USERAPPS_draw(selection);
        SYSTEM_DelayMs(10);

    }

}