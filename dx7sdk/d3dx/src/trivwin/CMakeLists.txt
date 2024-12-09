add_executable(trivwin WIN32
    trivwin.cpp
    resource.h

    trivwin.rc
    directx.ico
)
target_link_libraries(trivwin PRIVATE d3dx)
