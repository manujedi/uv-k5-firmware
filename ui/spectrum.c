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
#if defined(ENABLE_MINIMAL_SPECTRUM)
#include <string.h>
#include "spectrum.h"
#include "driver/st7565.h"
#include "external/printf/printf.h"
#include "helper.h"

void spectrum_drawUI(uint32_t Frequency, uint32_t FrequencyStep) {

    memset(gStatusLine, 0, sizeof(gStatusLine));

    char String[16];

    uint32_t mhz =  Frequency / 100000;
    uint32_t khz = (Frequency % 100000) / 100;
    sprintf(String, "%d.%03d",mhz,khz);
    UI_PrintStringSmall(String, 70, 127, 0, 7, false);

    mhz = (Frequency + 55 * FrequencyStep) / 100000;
    khz = ((Frequency + 55 * FrequencyStep) % 100000) / 100;
    sprintf(String, "%d.%03d", mhz, khz);
    UI_PrintStringSmall(String, 70, 127, 6, 7, false);

    mhz =  FrequencyStep / 100000;
    khz = (FrequencyStep % 100000) / 100;
    sprintf(String, "s=%d.%03d", mhz, khz);
    UI_PrintStringSmall(String, 60, 127, -1, 7, false);

    for (uint8_t i = 50; i < 60; ++i) {
        gFrameBuffer[0][i] |= 1 << 0;
        gFrameBuffer[6][i] |= 1 << 7;
    }
    ST7565_BlitFullScreen();
    ST7565_BlitStatusLine();
}

void spectrum_drawSpectrum(uint8_t rssi_val[56], uint32_t Frequency, uint32_t FrequencyStep, uint8_t min, uint8_t max) {
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));

    uint8_t line;
    uint8_t bit;
    uint8_t tmp;
    uint8_t max_index = 0;
    uint8_t max_measurement = 0xFF;
    uint8_t diff = max - min;

    for (uint8_t i = 0; i < 56; ++i) {
        line = i / 8;
        bit = i % 8;

        tmp = max - rssi_val[i];
        tmp = (50 * tmp) / diff;
        for (uint8_t j = 0; j < tmp; ++j) {
            gFrameBuffer[line][j] |= (1 << bit);
        }
        if(max_measurement < rssi_val[i]){
            max_measurement = rssi_val[i];
            max_index = i;
        }

    }

    char String[16];
    sprintf(String, "%d.%03d", (Frequency + max_index * FrequencyStep) / 100000,
            ((Frequency + max_index * FrequencyStep) % 100000) / 100);
    UI_PrintStringSmall(String, 70, 127, 3, 7, false);


    line = max_index / 8;
    bit = max_index % 8;

    for (uint8_t j = 54; j < 60; ++j) {
        gFrameBuffer[line][j] |= (1 << bit);
    }

    spectrum_drawUI(Frequency, FrequencyStep);
}

void spectrum_drawMinMaxDB(uint8_t* rssi_min, uint8_t* rssi_max) {
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
}

#endif