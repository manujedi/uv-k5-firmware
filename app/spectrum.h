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

#ifndef FIRMWARE_APP_SPECTRUM_H
#define FIRMWARE_APP_SPECTRUM_H

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
void spectrum_init(void);
void spectrum_loop(void);
#endif


#endif //FIRMWARE_APP_SPECTRUM_H
