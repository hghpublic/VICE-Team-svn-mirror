cmake_minimum_required(VERSION 3.31)

project(dev-gtk3 C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0 gtk+-quartz-3.0 gdk-3.0 gdk-quartz-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

# target_link_libraries(${target} PRIVATE ${GTK3_LIBRARIES})

add_subdirectory(src)
