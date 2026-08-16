
set(target example-0)
add_executable(${target} ${target}.c)
target_compile_features(${target} PRIVATE c_std_23)
target_link_libraries(${target} PRIVATE ${GTK3_LIBRARIES})
set_target_properties(${target} PROPERTIES FOLDER "Getting Started with GTK")

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
