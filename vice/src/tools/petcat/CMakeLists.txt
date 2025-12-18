
if(FIRST_RUN)
    set(CMAKE_XCODE_GENERATE_SCHEME ON)
    add_executable(petcat)
    set(CMAKE_XCODE_GENERATE_SCHEME OFF)
else()
    add_executable(petcat)
endif()

target_compile_definitions(
    petcat
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:HAVE_CONFIG_H NDEBUG >
        $<$<COMPILE_LANGUAGE:CXX>:>
        $<$<COMPILE_LANGUAGE:OBJC>:>
    )

target_include_directories(
    petcat
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/src/arch/systemheaderoverride
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/arch/shared
        /usr/include/SDL2
        /usr/include/libpng16
        /usr/include/aarch64-linux-gnu
        /usr/include/webp
    )

target_compile_options(
    petcat
    PRIVATE
        $<$<COMPILE_LANGUAGE:C>:-Wno-deprecated-declarations >
        $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-declarations -fno-exceptions>
        $<$<COMPILE_LANGUAGE:OBJC>:-Wno-deprecated-declarations >
    )

target_link_options(
    petcat
    PRIVATE
        -Wno-deprecated-declarations 
    )

target_sources(
    petcat
    PRIVATE
        petcat.c
    )

target_link_libraries(
    petcat
    PRIVATE
    	
    )
