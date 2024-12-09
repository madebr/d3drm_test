if(MSVC)
    add_subdirectory(src/envmap)
    add_subdirectory(src/gravity)
    add_subdirectory(src/particle)
    add_subdirectory(src/sprite)
    add_subdirectory(src/tentacle)
    add_subdirectory(src/trivfs)
    add_subdirectory(src/trivwin)
endif()

file(GLOB resources "media/*.x" "media/*")
execute_process(
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different ${resources} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
