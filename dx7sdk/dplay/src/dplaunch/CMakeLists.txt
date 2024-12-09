add_executable(dplaunch WIN32
    dplaunch.cpp
    resource.h

    dplaunch.rc
    directx.ico
)
target_link_libraries(dplaunch PRIVATE dplayx)
