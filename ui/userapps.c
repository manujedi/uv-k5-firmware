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

#include "ui/userapps.h"
#include "app/userapps.h"
#include "helper.h"
#include "driver/st7565.h"


void USERAPPS_draw(uint8_t offset){
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
    for (uint8_t i = 0; i < 6; ++i) {
        UI_PrintStringSmall(menu_items[offset],0, 128, i, 8,false);
        offset++;
        if(offset >= sizeof(menu_items)/sizeof(menu_items[0]))
            break;
    }
    for (uint8_t i = 0; i < 128; ++i) {
        gFrameBuffer[0][i] ^= 0xFF;
    }
    ST7565_BlitFullScreen();
}
