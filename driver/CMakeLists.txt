#Drivers
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

if (ENABLE_OVERLAY)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_SOURCE_DIR}/driver/flash.c
    )
endif ()
if (ENABLE_UART)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_SOURCE_DIR}/driver/aes.c
            ${CMAKE_SOURCE_DIR}/driver/uart.c
    )
endif ()
if (ENABLE_FMRADIO)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_SOURCE_DIR}/driver/bk1080.c
    )
endif ()
if (ENABLE_UART OR ENABLE_AIRCOPY)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_SOURCE_DIR}/driver/crc.c
    )
endif ()
target_sources(firmware.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/driver/adc.c
        ${CMAKE_SOURCE_DIR}/driver/backlight.c
        ${CMAKE_SOURCE_DIR}/driver/bk4819.c
        ${CMAKE_SOURCE_DIR}/driver/eeprom.c
        ${CMAKE_SOURCE_DIR}/driver/gpio.c
        ${CMAKE_SOURCE_DIR}/driver/i2c.c
        ${CMAKE_SOURCE_DIR}/driver/keyboard.c
        ${CMAKE_SOURCE_DIR}/driver/spi.c
        ${CMAKE_SOURCE_DIR}/driver/st7565.c
        ${CMAKE_SOURCE_DIR}/driver/system.c
        ${CMAKE_SOURCE_DIR}/driver/systick.c
)