#Helper
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_sources(firmware.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/helper/battery.c
        ${CMAKE_SOURCE_DIR}/helper/boot.c
)