cmake_minimum_required(VERSION 3.22)

project("myproj" VERSION 1.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)
set (CMAKE_AUTOUIC ON)

# разрешаем все предупреждающие сообщения
add_definitions(-Wall)

set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu")

# указываем модули
find_package(Qt5 COMPONENTS Core Gui Widgets Network WebEngineWidgets Multimedia MultimediaWidgets REQUIRED)

# указываем куда будет помещаться бинарник
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# создаём переменную котороя будет хранить путь к заголовочным файлам
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# теперь cmake папки src будет учавствовать в сборке
add_subdirectory(src)

