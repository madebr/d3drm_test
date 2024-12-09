add_executable(enumerate WIN32
    enumerate.cpp
    enumerate.h
    render.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(enumerate PRIVATE ddraw dxguid winmm)
