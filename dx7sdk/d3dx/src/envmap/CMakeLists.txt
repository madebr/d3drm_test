add_executable(envmap WIN32
    envmap.cpp
    envmap.h
    resource.h

    envmap.rc
    directx.ico
)
target_link_libraries(envmap PRIVATE d3dx d3dxd d3dxof ddraw)
