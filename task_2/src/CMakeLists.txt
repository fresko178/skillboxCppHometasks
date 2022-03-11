cmake_minimum_required(VERSION 3.22)

# собираем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp)

# добавляем включения т.е. наши заголовочные файлы, к цели сборки
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)
