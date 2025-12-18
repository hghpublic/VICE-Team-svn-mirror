add_library(libtapeport)

target_compile_definitions(
    libtapeport
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG _REENTRANT _REENTRANT >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libtapeport
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src/arch/sdl
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/datasette
        ${CMAKE_SOURCE_DIR}/src/core/rtc
        ${CMAKE_SOURCE_DIR}/src/diag
        /usr/include/SDL2
        /usr/include/libpng16
        /usr/include/aarch64-linux-gnu
        /usr/include/webp
    )

target_compile_options(
    libtapeport
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Werror=implicit-function-declaration -Wfatal-errors -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -fopenmp>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -Wfatal-errors -fopenmp -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libtapeport
    PRIVATE
        cp-clockf83.c
        dtl-basic-dongle.c
        sense-dongle.c
        wordcraft-dongle.c
        tape_diag_586220_harness.c
        tapecart.c
        tapeport.c
        cp-clockf83.h
        dtl-basic-dongle.h
        sense-dongle.h
        wordcraft-dongle.h
        tape_diag_586220_harness.h
        tapecart.h
        tapecart-loader.h
        tapeport.h
    )

