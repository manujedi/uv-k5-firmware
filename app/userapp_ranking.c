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


void USERAPP_ranking_readChannelFreq(uint8_t rssi_val[200]) {

    for (uint8_t channel = 0; channel < 200; channel++) {
        printf("c %i\r\n", channel);

        gEeprom.MrChannel[gEeprom.TX_CHANNEL] = channel;
        gEeprom.ScreenChannel[gEeprom.TX_CHANNEL] = channel;

        RADIO_ConfigureChannel(0, VFO_CONFIGURE_RELOAD);
        RADIO_SetupRegisters(true);

        //reset rssi (thanks to fagci)
        uint32_t Reg = BK4819_ReadRegister(BK4819_REG_30);
        Reg &= ~1;
        BK4819_WriteRegister(BK4819_REG_30, Reg);
        Reg |= 1;
        BK4819_WriteRegister(BK4819_REG_30, Reg);

        SYSTEM_DelayMs(10);

        int32_t rssi = (((BK4819_GetRSSI() >> 1) & 0xFF) - 160) * -1;

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
    memset(rssi_val, 0, sizeof(rssi_val));

    uint8_t selection = 0;

    while (key != KEY_EXIT) {

        key = USERAPPS_GetInput();

        switch (key) {
            case KEY_0 ... KEY_9:
                break;
            case KEY_UP:
                selection = selection == 0 ? 0 : selection - 1;
                break;
            case KEY_DOWN:
                selection = selection == 199 ? 199 : selection + 1;
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
                break;
        }

        USERAPPS_ranking_draw(selection, rssi_val);
        SYSTEM_DelayMs(10);

    }


}