add_subdirectory(src/3dmusic)
add_subdirectory(src/dmboids)
add_subdirectory(src/dmdonuts)
add_subdirectory(src/dmhook)
add_subdirectory(src/dmshell)
add_subdirectory(src/dmusmidi)
add_subdirectory(src/echotool)
add_subdirectory(src/musiclines)
add_subdirectory(src/playmotf)
add_subdirectory(src/playpri)

file(GLOB resources "media/*.x" "media/*")
execute_process(
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different ${resources} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
