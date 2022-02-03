cmake_minimum_required(VERSION 3.13)

project("myproj" VERSION 1.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)

# разрешаем все предупреждающие сообщения
add_definitions(-Wall)

# создаём переменную котороя будет хранить путь к заголовочным файлам
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
# какая-то дич с отключением тестов
set(JSON_BuildTests OFF CACHE INTERNAL "")

# теперь cmake папки src будет учавствовать в сборке
add_subdirectory(src)
# теперь cmake папки nlohmann_json будет учавствовать в сборке
add_subdirectory(nlohmann_json)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
