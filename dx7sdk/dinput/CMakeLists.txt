include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(src/digame)
add_subdirectory(src/ffdonuts)
add_subdirectory(src/fffileread)
add_subdirectory(src/joyffeed)
add_subdirectory(src/joystimm)
add_subdirectory(src/keybdbuf)
add_subdirectory(src/keybdexc)
add_subdirectory(src/keybdimm)
add_subdirectory(src/mouseexc)
add_subdirectory(src/mousenon)
add_subdirectory(src/scrawl)
add_subdirectory(src/tutorials/diex1)
add_subdirectory(src/tutorials/diex2)
add_subdirectory(src/tutorials/diex3)
add_subdirectory(src/tutorials/diex4)
add_subdirectory(src/tutorials/diex5)

file(GLOB resources "media/*.x" "media/*")
execute_process(
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different ${resources} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
