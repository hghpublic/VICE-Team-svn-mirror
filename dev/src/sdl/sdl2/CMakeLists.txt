cmake_minimum_required(VERSION 3.31)

project(dev-sdl2 C)

find_package(SDL2 CONFIG REQUIRED)
# target_link_libraries(${target}}
#     PRIVATE
#     $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
#     $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
# )

add_subdirectory(src)
