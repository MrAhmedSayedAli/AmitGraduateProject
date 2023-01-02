cmake_minimum_required(VERSION 3.15)
#============================================================================================>
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../output")
#============================================================================================>
option(USE_ATMEL "USE ATML" OFF)

if (USE_ATMEL)
    set(CMAKE_FIND_ROOT_PATH "C:/Program Files/Microchip/xc8/v2.36")
else(USE_ATMEL)
    #	set(CMAKE_FIND_ROOT_PATH "F:/AVR/WinAVR")
    set(CMAKE_FIND_ROOT_PATH "F:/AVR/avr-gcc-12.1.0-x64-windows")
endif ()

set(AVR_MCU atmega32)
set(MCU_SPEED "16000000UL")
#============================================================================================>
if (USE_ATMEL)
    set(AVR_CC          ${CMAKE_FIND_ROOT_PATH}/bin/xc8-cc.exe)
    set(AVR_CXX     	${CMAKE_FIND_ROOT_PATH}/bin/xc8-cc.exe)
    set(OPTIMIZATION 1)
else(USE_ATMEL)
    set(AVR_CC          ${CMAKE_FIND_ROOT_PATH}/bin/avr-gcc.exe)
    set(AVR_CXX     	${CMAKE_FIND_ROOT_PATH}/bin/avr-g++.exe)
    set(OPTIMIZATION 3)
endif ()

set(AVR_OBJCOPY     ${CMAKE_FIND_ROOT_PATH}/bin/avr-objcopy.exe)
set(AVR_OBJDUMP     ${CMAKE_FIND_ROOT_PATH}/bin/avr-objdump.exe)
#============================================================================================>
set(CMAKE_SYSTEM_NAME Generic)
#set(CMAKE_CXX_COMPILER ${AVR_CXX} CACHE STRING "c++ compiler" FORCE)
set(CMAKE_C_COMPILER ${AVR_CC} CACHE STRING "c compiler" FORCE)
set(CMAKE_OBJCOPY ${AVR_OBJCOPY} CACHE STRING "AVR OBJCOPY" FORCE)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mmcu=${AVR_MCU} -O${OPTIMIZATION} -DF_CPU=${MCU_SPEED}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)
#============================================================================================>
PROJECT(AMIT_Graduate_Project_HAND)
#============================================================================================>
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/avr/avr/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/avr/avr/lib")
#============================================================================================>
add_subdirectory(src)
#============================================================================================>
set(APP_SOURCES ${APP_SOURCES})
#============================================================================================>
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/mcal)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/hal)
#============================================================================================>
set(elf_file ${PROJECT_NAME}.elf)
set(hex_file ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)
set(eeprom_image ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}-eeprom.hex)
#============================================================================================>
add_executable(${elf_file} ${APP_SOURCES})
#============================================================================================>
add_custom_target(
        OUTPUT ALL
        DEPENDS ${elf_file}
        COMMAND ${AVR_OBJCOPY} -j .text -j .data -O ihex ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${elf_file} ${hex_file}
)

#add_custom_target(
#        OUTPUT ${eeprom_image}
#        DEPENDS ${elf_file}
#        COMMAND ${AVR_OBJCOPY} -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${elf_file} ${eeprom_image}
#
#)

#============================================================================================>


