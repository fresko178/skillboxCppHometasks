cmake_minimum_required(VERSION 3.5)

project("search_engine" VERSION 0.4 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)
# Обязательность установки указанного стандарта (если OFF (по умолчанию), то воспринимается как совет)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# разрешаем все предупреждающие сообщения
add_definitions(-Wall)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# указываем куда будет помещаться бинарник
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# собираем исполняемый файл
add_executable(${PROJECT_NAME}
  src/main.cpp
  src/converterjson.cpp
  src/invertedindex.cpp
  src/searchserver.cpp
)

add_executable(tests
  tests/main.cpp
  tests/test-cases.cpp
  src/converterjson.cpp
  src/invertedindex.cpp
  src/searchserver.cpp
)

# добавляем включения т.е. наши заголовочные файлы, к цели сборки
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
# добавляем включения т.е. наши заголовочные файлы, к цели сборки
target_include_directories(tests PUBLIC ${INCLUDE_DIR})

include(FetchContent)
FetchContent_Declare(
googletest
URL
https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# выставляем динамическое подключение библиотеки к проекту
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# делаем все настройки доступными для проекта
FetchContent_MakeAvailable(googletest)
# указываем, что в проекте будут применятся тесты с помощью строки
enable_testing()
#target_link_libraries(tests PRIVATE gtest)
include(GoogleTest)

# отключаем тесты
set(JSON_BuildTests OFF CACHE INTERNAL "")

gtest_discover_tests(tests)

find_package(Threads REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Threads::Threads)
target_link_libraries(tests PRIVATE gtest Threads::Threads)

