cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_CXX_SOURCE_FILE_EXTENSIONS cc;cpp)
set(CMAKE_CXX_STANDARD 11)

if(NOT FIRST_RUN_COMPLETE)
    set(FIRST_RUN true)
endif()

project(VICE C CXX)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

find_package(SDL2 CONFIG REQUIRED)
# target_link_libraries(${targeet}
#     PRIVATE
#     $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
#     $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
# )

add_subdirectory(src)

set(FIRST_RUN_COMPLETE true CACHE INTERNAL "Used to detect first run")
