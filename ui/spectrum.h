//
// Created by manu on 9/21/23.
//

#ifndef FIRMWARE_UI_SPECTRUM_H
#define FIRMWARE_UI_SPECTRUM_H

#include <string.h>
#include "stdint.h"
#include "driver/keyboard.h"
#include "app/userapps.h"
#include "driver/bk4819.h"
#include "external/printf/printf.h"
#include "radio.h"
#include "driver/eeprom.h"
#include "driver/system.h"

#if defined(ENABLE_MINIMAL_SPECTRUM)
void spectrum_drawUI(uint32_t Frequency, uint32_t FrequencyStep);
void spectrum_drawSpectrum(uint8_t rssi_val[56], uint32_t Frequency, uint32_t FrequencyStep, uint8_t min, uint8_t max);
void spectrum_drawMinMaxDB(uint8_t* rssi_min, uint8_t* rssi_max);
#endif

#endif //FIRMWARE_UI_SPECTRUM_H
