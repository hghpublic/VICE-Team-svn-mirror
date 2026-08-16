cmake_minimum_required(VERSION 3.31)

project(dev-gtk4 C)



find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4 gtk4-macos gtk4-atspi gtk4-unix-print)
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})

# target_link_libraries(${target} PRIVATE ${GTK3_LIBRARIES})

add_subdirectory(src)
