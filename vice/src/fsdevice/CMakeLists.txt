add_library(libfsdevice)

target_compile_definitions(
    libfsdevice
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _REENTRANT _REENTRANT >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libfsdevice
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/vdrive
        ${CMAKE_SOURCE_DIR}/src/lib/p64
        /usr/include/SDL2
        /usr/include/libpng16
        /usr/include/aarch64-linux-gnu
        /usr/include/webp
    )

target_compile_options(
    libfsdevice
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Werror=implicit-function-declaration -Wfatal-errors -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -fopenmp>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -Wfatal-errors -fopenmp -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libfsdevice
    PRIVATE
        fsdevice-close.c
        fsdevice-cmdline-options.c
        fsdevice-flush.c
        fsdevice-filename.c
        fsdevice-open.c
        fsdevice-read.c
        fsdevice-resources.c
        fsdevice-write.c
        fsdevice.c
        fsdevice-close.h
        fsdevice-cmdline-options.h
        fsdevice-flush.h
        fsdevice-filename.h
        fsdevice-open.h
        fsdevice-read.h
        fsdevice-resources.h
        fsdevice-write.h
        fsdevicetypes.h
    )

