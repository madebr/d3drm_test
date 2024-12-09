add_executable(test_d3drm WIN32
        dd.c
        dd.h
        main.c
)
target_link_libraries(test_d3drm PRIVATE d3drm ddraw)
