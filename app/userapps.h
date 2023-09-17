//
// Created by manu on 9/17/23.
//

#ifndef FIRMWARE_APP_USERAPPS_H
#define FIRMWARE_APP_USERAPPS_H

#include <string.h>
#include "stdint.h"
#include "driver/keyboard.h"

extern char menu_items[7][15];

void USERAPPS_init(void);
KEY_Code_t USERAPPS_GetInput(void);
void USERAPPS_loop(void);

#endif //FIRMWARE_APP_USERAPPS_H
