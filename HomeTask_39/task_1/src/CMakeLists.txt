cmake_minimum_required(VERSION 3.22)

# собираем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp qml.qrc)

# добавляем включения т.е. наши заголовочные файлы, к цели сборки
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

# подключаем к нашему приложению модули
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Gui Qt5::Widgets Qt5::Network
                                      Qt5::WebEngineWidgets Qt5::WebEngineCore
                                      Qt5::Multimedia Qt5::MultimediaWidgets)
