add_executable(zbuffer WIN32
    zbuffer.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(zbuffer PRIVATE ddraw dxguid)
