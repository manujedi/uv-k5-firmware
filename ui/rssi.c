/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
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

#include <string.h>
#include "bitmaps.h"
#include "driver/st7565.h"
#include "functions.h"
#include "misc.h"
#include "settings.h"
#include "ui/rssi.h"
#include "ui/ui.h"
#include "helper.h"


void UI_UpdateRSSI(uint16_t RSSI)
{
	uint8_t Level;

	if (RSSI >= gEEPROM_RSSI_CALIB[gRxVfo->Band][3]) {
		Level = 6;
	} else if (RSSI >= gEEPROM_RSSI_CALIB[gRxVfo->Band][2]) {
		Level = 4;
	} else if (RSSI >= gEEPROM_RSSI_CALIB[gRxVfo->Band][1]) {
		Level = 2;
	} else if (RSSI >= gEEPROM_RSSI_CALIB[gRxVfo->Band][0]) {
		Level = 1;
	} else {
		Level = 0;
	}

	if (gVFO_RSSI_Level[gEeprom.RX_CHANNEL] != Level) {
		gVFO_RSSI_Level[gEeprom.RX_CHANNEL] = Level;
	}

    if (gCurrentFunction == FUNCTION_TRANSMIT || gScreenToDisplay != DISPLAY_MAIN) {
        return;
    }

    //do the calculation
    int16_t realRSSI = (int16_t)((RSSI >> 1) & 0xFF);
    realRSSI = realRSSI - 160;
    realRSSI *= -1;

    //rssi to string
    char rssi_str[8];
    NUMBER_ToDigits(realRSSI, rssi_str);

    //which line
    uint8_t line = gEeprom.RX_CHANNEL == 0 ? 2 : 6;
    //print the rssi
    UI_DisplaySmallDigits(3,rssi_str+5, 2, line);
    //print the minus
    gFrameBuffer[line][0] = 0x10;
    gFrameBuffer[line][1] = 0x10;
    ST7565_BlitFullScreen();
}

