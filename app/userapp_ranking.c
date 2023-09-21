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

#include "app/userapps.h"
#include "app/userapp_ranking.h"
#include "ui/userapp_ranking.h"
#include "driver/keyboard.h"
#include "ui/userapps.h"
#include "driver/system.h"
#include "radio.h"
#include "driver/uart.h"
#include "external/printf/printf.h"
#include "settings.h"
#include "misc.h"
#include "driver/bk4819-regs.h"
#include "driver/bk4819.h"
#include "driver/systick.h"
#include "driver/eeprom.h"

//some code stolen from https://github.com/fagci/uv-k5-firmware-fagci-mod/blob/main/app/spectrum.c
static void ResetRSSI() {
    uint32_t Reg = BK4819_ReadRegister(BK4819_REG_30);
    Reg &= ~1;
    BK4819_WriteRegister(BK4819_REG_30, Reg);
    Reg |= 1;
    BK4819_WriteRegister(BK4819_REG_30, Reg);
}

void setF(uint32_t f) {
    BK4819_PickRXFilterPathBasedOnFrequency(f);
    BK4819_SetFrequency(f);
    //??? fagci does it
    uint16_t reg = BK4819_ReadRegister(BK4819_REG_30);
    BK4819_WriteRegister(BK4819_REG_30, 0);
    BK4819_WriteRegister(BK4819_REG_30, reg);

}

void USERAPP_ranking_readChannelFreq(uint8_t rssi_val[200]) {

    for (uint8_t channel = 0; channel < 200; channel++) {
        if (channel != 0 && RADIO_FindNextChannel(channel, RADIO_CHANNEL_UP, false, 0) == 0)
            continue;

        printf("c %i\r\n", channel);

        uint32_t Frequency;
        EEPROM_ReadBuffer(channel * 16, &Frequency, 4);
        setF(Frequency);

        //reset rssi (thanks to fagci)
        ResetRSSI();
        SYSTEM_DelayMs(10);

        int32_t rssi = (BK4819_GetRSSI() >> 1);
        rssi -= 160;
        rssi *= (-1);
        rssi_val[channel] = rssi & 0xFF;

        USERAPPS_ranking_progress(channel / 2);

    }
}


void USERAPP_ranking_init() {
    USERAPP_ranking_loop();
}

void USERAPP_ranking_loop() {

    KEY_Code_t key = KEY_INVALID;

    uint8_t rssi_val[200];
    memset(rssi_val, 0xFF, sizeof(rssi_val));

    uint8_t selection = 0;
    uint8_t min_rssi = 100;
    bool updateUI = true;

    while (key != KEY_EXIT) {

        key = USERAPPS_GetInput();

        switch (key) {
            case KEY_0:
                break;
            case KEY_1:
                min_rssi -= 5;
                updateUI = true;
                break;
            case KEY_2:
                break;
            case KEY_3:
                break;
            case KEY_4:
                break;
            case KEY_5:
                break;
            case KEY_6:
                break;
            case KEY_7:
                min_rssi += 5;
                updateUI = true;
                break;
            case KEY_8:
                break;
            case KEY_9:
                break;
            case KEY_UP:
                selection = selection == 0 ? 0 : selection - 1;
                updateUI = true;
                break;
            case KEY_DOWN:
                selection = selection == 199 ? 199 : selection + 1;
                updateUI = true;
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
                USERAPP_ranking_readChannelFreq(rssi_val);
                updateUI = true;
                break;
        }
        if (updateUI)
            USERAPPS_ranking_draw(selection, rssi_val, min_rssi);
        updateUI = false;
        SYSTEM_DelayMs(10);
    }


}