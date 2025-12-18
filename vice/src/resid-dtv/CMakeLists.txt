add_library(libresiddtv)

target_compile_definitions(
    libresiddtv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:>
        $<$<COMPILE_LANGUAGE:CXX>:PACKAGE_NAME="" PACKAGE_TARNAME="" PACKAGE_VERSION="" PACKAGE_STRING="" PACKAGE_BUGREPORT="" PACKAGE_URL="" PACKAGE="resid" VERSION="0.16vice" HAVE_STDIO_H=1 HAVE_STDLIB_H=1 HAVE_STRING_H=1 HAVE_INTTYPES_H=1 HAVE_STDINT_H=1 HAVE_STRINGS_H=1 HAVE_SYS_STAT_H=1 HAVE_SYS_TYPES_H=1 HAVE_UNISTD_H=1 STDC_HEADERS=1 SIZEOF_INT=4 >
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libresiddtv
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        
    )

target_compile_options(
    libresiddtv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations @VICE_CFLAGS@>
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -Wall -O2 -funroll-loops -fomit-frame-pointer -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libresiddtv
    PRIVATE
        sid.cc
        voice.cc
        wave.cc
        envelope.cc
        filter.cc
        extfilt.cc
        version.cc
        sid.h
        voice.h
        wave.h
        envelope.h
        filter.h
        extfilt.h
        bittrain.h
        residdtv-config.h
    )

