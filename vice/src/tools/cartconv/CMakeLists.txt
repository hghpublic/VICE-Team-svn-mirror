
if(FIRST_RUN)
    set(CMAKE_XCODE_GENERATE_SCHEME ON)
    add_executable(cartconv)
    set(CMAKE_XCODE_GENERATE_SCHEME OFF)
else()
    add_executable(cartconv)
endif()

target_compile_definitions(
    cartconv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    cartconv
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src
        /usr/include/SDL2
        /usr/include/libpng16
        /usr/include/aarch64-linux-gnu
        /usr/include/webp
    )

target_compile_options(
    cartconv
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations >
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_link_options(
    cartconv
    PRIVATE
        -Wno-deprecated-declarations 
    )

target_sources(
    cartconv
    PRIVATE
        cartconv.c
        c64-cartridges.c
        c64-saver.c
        c128-cartridges.c
        c128-saver.c
        cbm2-cartridges.c
        cbm2-saver.c
        plus4-cartridges.c
        plus4-saver.c
        vic20-cartridges.c
        vic20-saver.c
        crt.c
    )

target_link_libraries(
    cartconv
    PRIVATE
    	
    )
