add_executable(setup WIN32
    dinstall.c
    dinstall.h
    wincode.c
    resource.h

    dinstall.rc
    directx.ico
)
target_link_libraries(setup PRIVATE dsetup)
