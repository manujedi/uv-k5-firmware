#UI
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

if (ENABLE_AIRCOPY)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/aircopy.c
    )
endif ()
if (ENABLE_FMRADIO)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/fmradio.c
    )
endif ()

target_sources(firmware.elf PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/battery.c
        ${CMAKE_CURRENT_SOURCE_DIR}/helper.c
        ${CMAKE_CURRENT_SOURCE_DIR}/inputbox.c
        ${CMAKE_CURRENT_SOURCE_DIR}/lock.c
        ${CMAKE_CURRENT_SOURCE_DIR}/main.c
 #       ${CMAKE_CURRENT_SOURCE_DIR}/menu.c
        ${CMAKE_CURRENT_SOURCE_DIR}/menu_new.c
        ${CMAKE_CURRENT_SOURCE_DIR}/rssi.c
        ${CMAKE_CURRENT_SOURCE_DIR}/scanner.c
        ${CMAKE_CURRENT_SOURCE_DIR}/status.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ui.c
        ${CMAKE_CURRENT_SOURCE_DIR}/welcome.c
        ${CMAKE_CURRENT_SOURCE_DIR}/spectrum.c
        ${CMAKE_CURRENT_SOURCE_DIR}/userapps.c
        ${CMAKE_CURRENT_SOURCE_DIR}/userapp_ranking.c
)