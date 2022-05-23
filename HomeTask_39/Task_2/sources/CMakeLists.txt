cmake_minimum_required(VERSION 3.13)

# собираем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp form.cpp form.ui)

# добавляем включения т.е. наши заголовочные файлы, к цели сборки
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network)
