add_executable(override WIN32
    override.cpp
    resource.h

    override.rc
    directx.ico
)
target_link_libraries(override PRIVATE dplayx)
