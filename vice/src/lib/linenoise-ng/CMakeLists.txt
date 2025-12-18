add_library(liblinenoiseng)

target_compile_definitions(
    liblinenoiseng
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:>
        $<$<COMPILE_LANGUAGE:CXX>:HAVE_CONFIG_H NDEBUG _REENTRANT _REENTRANT >
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    liblinenoiseng
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        /usr/include/SDL2
        /usr/include/libpng16
        /usr/include/aarch64-linux-gnu
        /usr/include/webp
    )

target_compile_options(
    liblinenoiseng
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations -g -O3 -W -Wall -Wextra -Wformat -Wformat-signedness -Wformat-security -Wshadow -Wpointer-arith -Wmissing-prototypes -Wstrict-prototypes -Wuninitialized -Wmissing-field-initializers -Wunreachable-code -Werror=implicit-function-declaration -Wfatal-errors -Wdiscarded-qualifiers -Wno-unknown-pragmas -Wunused-but-set-variable -Wno-sign-compare -Wno-ignored-qualifiers -Wno-unused-parameter -fopenmp>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -O3 -Wall -Wformat -Wshadow -Wpointer-arith -Wuninitialized -Wunreachable-code -Wno-unused-parameter -Wfatal-errors -fopenmp -Wno-unused-variable -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    liblinenoiseng
    PRIVATE
        ConvertUTF.cpp
        linenoise.cpp
        wcwidth.cpp
        ConvertUTF.h
        linenoise.h
        wcwidth.h
    )

