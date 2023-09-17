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

char menu_items[7][15] = {
        "Ranking",
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

void USERAPPS_startapp(uint8_t selection){
    switch (selection) {
        case 0:
            USERAPP_ranking_init();
            break;
        default:
            break;
    }

}

void USERAPPS_init(void){
    USERAPPS_loop();
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