add_library(libresid)

target_compile_definitions(
    libresid
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:>
        $<$<COMPILE_LANGUAGE:CXX>:PACKAGE_NAME="reSID" PACKAGE_TARNAME="resid" PACKAGE_VERSION="1.0-pre2" PACKAGE_STRING="reSID 1.0-pre2" PACKAGE_BUGREPORT="resid@nimrod.no" PACKAGE_URL="" PACKAGE="resid" VERSION="1.0-pre2" HAVE_STDIO_H=1 HAVE_STDLIB_H=1 HAVE_STRING_H=1 HAVE_INTTYPES_H=1 HAVE_STDINT_H=1 HAVE_STRINGS_H=1 HAVE_SYS_STAT_H=1 HAVE_SYS_TYPES_H=1 HAVE_UNISTD_H=1 STDC_HEADERS=1 SIZEOF_INT=4 NDEBUG >
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    libresid
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        
    )

target_compile_options(
    libresid
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations >
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -g -Wall -O3 -march=native -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_sources(
    libresid
    PRIVATE
        sid.cc
        voice.cc
        wave.cc
        envelope.cc
        filter8580new.cc
        dac.cc
        extfilt.cc
        pot.cc
        version.cc
        wave6581_PST.h
        wave6581_PS_.h
        wave6581_P_T.h
        wave6581__ST.h
        wave8580_PST.h
        wave8580_PS_.h
        wave8580_P_T.h
        wave8580__ST.h
        sid.h
        voice.h
        wave.h
        envelope.h
        filter.h
        filter8580new.h
        dac.h
        extfilt.h
        pot.h
        spline.h
        resid-config.h
        wave6581_PST.h
    )

