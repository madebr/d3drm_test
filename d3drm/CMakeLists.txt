add_executable(test_d3drm WIN32
    dd.c
    dd.h
    main.c
)
target_link_libraries(test_d3drm PRIVATE d3drm ddraw)
add_custom_command(TARGET test_d3drm POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_CURRENT_SOURCE_DIR}/cube.x" "$<TARGET_FILE_DIR:test_d3drm>"
    COMMAND "${CMAKE_COMMAND}" -E copy "${PROJECT_SOURCE_DIR}/dlls/d3drm.dll" "$<TARGET_FILE_DIR:test_d3drm>"
    COMMAND "${CMAKE_COMMAND}" -E copy "${PROJECT_SOURCE_DIR}/dlls/d3drm.pdb" "$<TARGET_FILE_DIR:test_d3drm>"
)
