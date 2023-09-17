#App
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
            ${CMAKE_CURRENT_SOURCE_DIR}/fm.c
    )
endif ()
if (ENABLE_UART)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/uart.c
    )
endif ()
target_sources(firmware.elf PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/action.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app.c
        ${CMAKE_CURRENT_SOURCE_DIR}/dtmf.c
        ${CMAKE_CURRENT_SOURCE_DIR}/generic.c
        ${CMAKE_CURRENT_SOURCE_DIR}/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/menu.c
        ${CMAKE_CURRENT_SOURCE_DIR}/scanner.c
        ${CMAKE_CURRENT_SOURCE_DIR}/userapps.c
)