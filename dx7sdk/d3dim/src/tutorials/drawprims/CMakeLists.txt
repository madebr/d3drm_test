add_executable(drawprims WIN32
    drawprims.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(drawprims PRIVATE d3dim ddraw dxguid)
