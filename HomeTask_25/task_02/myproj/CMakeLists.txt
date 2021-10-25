cmake_minimum_required(VERSION 3.13)

project("myproj" VERSION 1.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

# разрешаем все предупреждающие сообщения
add_definitions(-Wall)

# теперь cmake папки src будет учавствовать в сборке
add_subdirectory(src)

