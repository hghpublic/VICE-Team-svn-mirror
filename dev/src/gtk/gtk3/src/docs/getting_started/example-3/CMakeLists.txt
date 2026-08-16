
set(target example-3)
add_executable(${target})
target_sources(${target} PRIVATE
    ${target}.c
    builder.ui
)
target_compile_features(${target} PRIVATE c_std_23)
target_link_libraries(${target} PRIVATE ${GTK3_LIBRARIES})
set_target_properties(${target} PROPERTIES FOLDER "Getting Started with GTK")

add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/builder.ui"
        "$<TARGET_FILE_DIR:${target}>/builder.ui"
)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
target_link_libraries(${target} PRIVATE
  "$<LINK_LIBRARY:FRAMEWORK,Carbon>"
  "$<LINK_LIBRARY:FRAMEWORK,Cocoa>"
  "$<LINK_LIBRARY:FRAMEWORK,CoreFoundation>"
  "$<LINK_LIBRARY:FRAMEWORK,CoreGraphics>"
  "$<LINK_LIBRARY:FRAMEWORK,CoreText>"
  "$<LINK_LIBRARY:FRAMEWORK,CoreVideo>"
  "$<LINK_LIBRARY:FRAMEWORK,Foundation>"
  "$<LINK_LIBRARY:FRAMEWORK,IOSurface>"
  "$<LINK_LIBRARY:FRAMEWORK,QuartzCore>"
  "$<LINK_LIBRARY:FRAMEWORK,UniformTypeIdentifiers>"
)
endif()


# set_target_properties(program PROPERTIES LINK_FLAGS "-Wl,-F/Library/Frameworks")
