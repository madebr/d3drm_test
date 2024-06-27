add_executable(test_ddraw WIN32
    dd.c
    dd.h
    main.c
)
target_link_libraries(test_ddraw PRIVATE ddraw)
