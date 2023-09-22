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

#include "app/spectrum.h"
#include "ui/spectrum.h"
#include "helper/radio_helper.h"

#if defined(ENABLE_MINIMAL_SPECTRUM)
void spectrumMessure(uint8_t *rssi_val, uint32_t freq) {

    BK4819_PickRXFilterPathBasedOnFrequency(freq);
    setF(freq);

    ResetRSSI();
    SYSTEM_DelayMs(10);

    int32_t rssi = (BK4819_GetRSSI() >> 1);
    rssi -= 160;
    rssi *= (-1);
    *rssi_val = rssi & 0xFF;

}

uint32_t pow10(uint8_t exponent) {
    uint32_t ret = 1;
    for (uint8_t i = 0; i < exponent; ++i)
        ret *= 10;
    return ret;
}

uint8_t log10(uint32_t val) {
    uint8_t ret = 0;
    val /= 10;
    while (val) {
        ret++;
        val /= 10;
    }
    return ret;
}


void spectrum_init() {
    spectrum_loop();
}

void spectrum_loop() {

    KEY_Code_t key = KEY_INVALID;

    uint8_t rssi_val[56];
    uint8_t i = 0;

    memset(rssi_val, 0xFF, sizeof(rssi_val));

    uint32_t Frequency = 45000000;
    uint32_t FrequencyStep = 100;

    bool updateUI = true;

    while (key != KEY_EXIT) {

        key = USERAPPS_GetInput();

        switch (key) {
            case KEY_0:
                break;
            case KEY_1:
                if (FrequencyStep < 1000000)
                    FrequencyStep += pow10(log10(FrequencyStep));
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
                if (FrequencyStep > 1)
                    FrequencyStep -= pow10(log10(FrequencyStep)-1);
                updateUI = true;
                break;
            case KEY_8:
                break;
            case KEY_9:
                break;
            case KEY_UP:
                Frequency -= FrequencyStep;
                updateUI = true;
                break;
            case KEY_DOWN:
                Frequency += FrequencyStep;
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
                break;
        }

        spectrumMessure(&rssi_val[i], Frequency + (FrequencyStep * i));

        i++;
        if (i >= 56) {
            i = 0;
            spectrum_drawSpectrum(rssi_val, Frequency, FrequencyStep);
        }

        if (updateUI) {
            spectrum_drawUI(Frequency, FrequencyStep);
            updateUI = false;
        }

    }
}
#endif