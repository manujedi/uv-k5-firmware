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
#if defined(ENABLE_CHANNEL_SCAN)

#include "ui/userapps.h"
#include "ui/userapp_ranking.h"
#include "app/userapps.h"
#include "external/printf/printf.h"
#include "settings.h"
#include "helper.h"
#include "driver/st7565.h"
#include "driver/eeprom.h"


void USERAPPS_ranking_draw(uint8_t offset, uint8_t rssi_val[200], uint8_t min_rssi_filter){
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
    char String[24];
    uint8_t printed = 0;
    for (uint8_t i = 0; i < 200 && printed < 6; ++i) {
        if((i+offset) >= 200)
            break;

        if(rssi_val[i+offset] > min_rssi_filter)
            continue;

        EEPROM_ReadBuffer(0x0F50 + ((i+offset) * 0x10), String + 0, 8);
        EEPROM_ReadBuffer(0x0F58 + ((i+offset) * 0x10), String + 8, 2);

        if(String[0] == 0 || String[0] == 0xFF) {
            sprintf(String, "CH-%03d", (i+offset) + 1);
            UI_PrintStringSmall(String, 0, 128, printed, 8, false);
        } else {
            UI_PrintStringSmall(String, 0, 128, printed, 8, false);
        }
        sprintf(String, "-%03idb", rssi_val[i+offset]);
        UI_PrintStringSmall(String, 82, 128, printed, 7, false);
        printed++;
    }
    sprintf(String, "min -%03idb", min_rssi_filter);
    UI_PrintStringSmall(String, 5, 128, 6, 7, false);

    ST7565_BlitFullScreen();
}

void USERAPPS_ranking_progress(uint8_t percent){
    memset(gFrameBuffer[6], 0, sizeof(gFrameBuffer[0]));
    for (uint8_t i = 0; i < 128; ++i) {
        if(((uint32_t) i)*100 > percent*128)
            break;
        gFrameBuffer[6][i] = 0xF0;
    }

    ST7565_BlitFullScreen();
}

#endif