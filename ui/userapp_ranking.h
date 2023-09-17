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

#ifndef FIRMWARE_UI_USERAPP_RANKING_H
#define FIRMWARE_UI_USERAPP_RANKING_H

#include "stdint.h"
#include "app/userapps.h"

void USERAPPS_ranking_draw(uint8_t offset, uint8_t rssi_val[200], uint8_t min_rssi_filter);
void USERAPPS_ranking_progress(uint8_t percent);

#endif //FIRMWARE_UI_USERAPP_RANKING_H
