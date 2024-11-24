cmake_minimum_required(VERSION 3.22.1)

project("silkcasket")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -flto")


set(INCLUDE_DIRS
        include/silkcasket
)

add_library(
        silkcasket
        STATIC
        src/compress/lzw.cpp
        src/compress/compress.cpp
        src/parser/entry.cpp
        src/utils/file.cpp
        src/structure/entry.cpp
        src/structure/verification.cpp
        src/structure/header.cpp
        src/build/build.cpp
        src/build/entry.cpp
)

target_include_directories(
        silkcasket
        PUBLIC
        ${INCLUDE_DIRS}
)

target_link_libraries(
        silkcasket
        PUBLIC
        log
)

add_library(exexample
        SHARED
        native-lib.cpp
)

target_link_libraries(exexample
        silkcasket
        android
        log)