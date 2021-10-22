cmake_minimum_required(VERSION 3.13)

project("myproj" VERSION 1.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

# создаём переменную котороя будет хранить путь к директории с заголовочными файлами
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# теперь cmake папки src будет учавствовать в сборке
add_subdirectory(src)
