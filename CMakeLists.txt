cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(webserver CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_OUTPUT_PATH "../bin")

# set(LIB_DIRS src/lib)

# set(TEST_LIBS ${LIB_DIRS}/test.c)
# add_library(lib SHARED ${TEST_LIBS})

add_executable(main src/main.cpp src/tcp.cpp)
# target_include_directories(main PUBLIC ${INCLUDE_DIRS})
# target_link_libraries(main PUBLIC test)
