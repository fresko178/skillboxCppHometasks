cmake_minimum_required(VERSION 3.13)

# собираем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp
                               border.cpp
                               circle.cpp
                               rectangle.cpp
                               square.cpp
                               triangle.cpp)


# добавляем включения т.е. наши заголовочные файлы, к цели сборки
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

