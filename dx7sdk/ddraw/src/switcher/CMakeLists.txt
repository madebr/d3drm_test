add_executable(switcher WIN32
    switcher.cpp
    resource.h

    switcher.rc
    directx.ico
)
target_link_libraries(switcher PRIVATE ddraw dxguid)
