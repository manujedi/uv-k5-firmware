#Helper
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_sources(firmware.elf PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/battery.c
        ${CMAKE_CURRENT_SOURCE_DIR}/boot.c
        ${CMAKE_CURRENT_SOURCE_DIR}/radio_helper.c
)