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


# Set up Qt forms/resources
#qt5_wrap_ui(UI_OUT_FILES forms/Form.ui)
#qt5_add_resources(RESOURCE_FILE resources.qrc)

# Library cpp and header files
#set(CORE_CPP_FILES Bar.cpp)
#set(LIB_CPP_FILES ${LIB_CPP_FILES} ${CORE_CPP_FILES} ${UI_OUT_FILES} ${RESOURCE_FILE})
#set(LIB_HEADER_FILES ${PUBLIC_HEADERS_DIR}/Foo/Bar.h)

## Build library
#add_library(Foo SHARED ${LIB_CPP_FILES} ${LIB_HEADER_FILES})
#target_link_libraries(Foo ${Qt5Widgets_LIBRARIES})

