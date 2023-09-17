# Copyright 2023 Manuel Jedinger
# https://github.com/manujedi
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.25)

# Enable features
set(ENABLE_AIRCOPY 1)
set(ENABLE_ALARM 1)
set(ENABLE_FMRADIO 1)
set(ENABLE_NOAA 1)
set(ENABLE_OVERLAY 0)
set(ENABLE_SWD 1)
set(ENABLE_TX1750 1)
set(ENABLE_UART 1)

if (ENABLE_AIRCOPY)
    add_compile_definitions(ENABLE_AIRCOPY)
endif ()

if (ENABLE_ALARM)
    add_compile_definitions(ENABLE_ALARM)
endif ()

if (ENABLE_FMRADIO)
    add_compile_definitions(ENABLE_FMRADIO)
endif ()

if (ENABLE_NOAA)
    add_compile_definitions(ENABLE_NOAA)
endif ()

if (ENABLE_OVERLAY)
    add_compile_definitions(ENABLE_OVERLAY)
endif ()

if (ENABLE_SWD)
    add_compile_definitions(ENABLE_SWD)
endif ()

if (ENABLE_TX1750)
    add_compile_definitions(ENABLE_TX1750)
endif ()

if (ENABLE_UART)
    add_compile_definitions(ENABLE_UART)
endif ()


# specify cross compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# project settings
project(firmware ASM C)
set(CMAKE_C_STANDARD 11)

set(MCPU cortex-m0)

execute_process(
        COMMAND git rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)


add_compile_options(-mcpu=${MCPU} -Wall -Werror -fno-builtin -MMD)
add_compile_options(-DPRINTF_INCLUDE_CONFIG_H)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/firmware.ld)
add_link_options(-mcpu=${MCPU} -nostartfiles -Wl,-T ${LINKER_SCRIPT})

add_compile_options(-DGIT_HASH=\"${GIT_HASH}\")


if (CMAKE_C_COMPILER_VERSION VERSION_LESS "12.0.0")
    message(WARNING "Newer GCC version recommended")
    add_compile_options(-fno-delete-null-pointer-checks)
else ()
    add_compile_options(--param=min-pagesize=0)
endif ()


if ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    add_compile_options(-O2 -g)
    MESSAGE("Min Size build")
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    add_compile_options(-Os -DNDEBUG)
    MESSAGE("Min Size build")
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeDeb")
    add_compile_options(-Os -g)
    MESSAGE("Min Size build")
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_compile_options(-Og -g)
    add_link_options(-g)
    MESSAGE("Debug build")
else ()
    add_compile_options(-O2)
    MESSAGE("Other build")
endif ()

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

include_directories(
        ${CMAKE_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/external/CMSIS_5/CMSIS/Core/Include
        ${CMAKE_SOURCE_DIR}/external/CMSIS_5/Device/ARM/ARMCM0/Include
)

# External
target_sources(firmware.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/external/printf/printf.c
)

# Startup
if (ENABLE_OVERLAY)
    target_sources(firmware.elf PRIVATE
            ${CMAKE_SOURCE_DIR}/sram-overlay.c
    )
endif ()
target_sources(firmware.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/start.S
        ${CMAKE_SOURCE_DIR}/init.c
)

add_subdirectory(driver)
add_subdirectory(app)
add_subdirectory(helper)
add_subdirectory(ui)

#Main
target_sources(firmware.elf PRIVATE
        ${CMAKE_SOURCE_DIR}/audio.c
        ${CMAKE_SOURCE_DIR}/bitmaps.c
        ${CMAKE_SOURCE_DIR}/board.c
        ${CMAKE_SOURCE_DIR}/dcs.c
        ${CMAKE_SOURCE_DIR}/font.c
        ${CMAKE_SOURCE_DIR}/frequencies.c
        ${CMAKE_SOURCE_DIR}/functions.c
        ${CMAKE_SOURCE_DIR}/misc.c
        ${CMAKE_SOURCE_DIR}/radio.c
        ${CMAKE_SOURCE_DIR}/scheduler.c
        ${CMAKE_SOURCE_DIR}/settings.c
        ${CMAKE_SOURCE_DIR}/version.c
        ${CMAKE_SOURCE_DIR}/main.c
)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${SIZE} $<TARGET_FILE:${PROJECT_NAME}.elf>
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMAND python3 ${CMAKE_SOURCE_DIR}/fw-pack.py ${BIN_FILE} ${GIT_HASH} ${PROJECT_NAME}.packed.bin
)