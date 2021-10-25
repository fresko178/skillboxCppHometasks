cmake_minimum_required(VERSION 3.13)

set(PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(SRC
  main.cpp
  ${PATH}/cpu/cpu.cpp
  ${PATH}/disk/disk.cpp
  ${PATH}/gpu/gpu.cpp
  ${PATH}/kbd/kbd.cpp
  ${PATH}/ram/ram.cpp
)

set(HDR
  ${PATH}/cpu/cpu.h
  ${PATH}/disk/disk.h
  ${PATH}/gpu/gpu.h
  ${PATH}/kbd/kbd.h
  ${PATH}/ram/ram.h
)

# собираем исполняемый файл
add_executable(${PROJECT_NAME} ${SRC} ${HDR})

target_include_directories(${PROJECT_NAME} PUBLIC ../cpu/)
target_include_directories(${PROJECT_NAME} PUBLIC ../disk/)
target_include_directories(${PROJECT_NAME} PUBLIC ../gpu/)
target_include_directories(${PROJECT_NAME} PUBLIC ../kbd/)
target_include_directories(${PROJECT_NAME} PUBLIC ../ram/)

