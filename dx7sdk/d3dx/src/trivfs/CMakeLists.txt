add_executable(trivfs WIN32
    trivfs.cpp
    resource.h

    trivfs.rc
    directx.ico
)
target_link_libraries(trivfs PRIVATE d3dx)
