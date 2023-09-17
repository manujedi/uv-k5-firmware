//
// Created by manu on 9/17/23.
//

#include "userapps.h"
#include "driver/keyboard.h"
#include "ui/userapps.h"
#include "driver/system.h"

char menu_items[7][15] = {
        "Contrast",
        "Bridge",
        "Scanner",
        "Todo",
        "Todo",
        "Todo",
        "Todo",
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
        scroll = 5; //scrollspeed
        return currentKey;
    }

    return KEY_INVALID;
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
                break;
        }

        USERAPPS_draw(selection);
        SYSTEM_DelayMs(10);

    }

}