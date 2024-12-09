add_executable(triangle WIN32
    triangle.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(triangle PRIVATE ddraw dxguid)
