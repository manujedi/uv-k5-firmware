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

#ifndef FIRMWARE_RADIO_HELPER_H
#define FIRMWARE_RADIO_HELPER_H
#include "radio_helper.h"
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
void setF(uint32_t f);
void ResetRSSI();

#endif //FIRMWARE_RADIO_HELPER_H
