cmake_minimum_required(VERSION 3.13)

project("myproj" VERSION 1.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)

# разрешаем все предупреждающие сообщения
add_definitions(-Wall)

# создаём переменную котороя будет хранить путь к заголовочным файлам
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# теперь cmake папки src будет учавствовать в сборке
add_subdirectory(src)

# для работы с пакетами
find_package(Threads REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME} Threads::Threads)
