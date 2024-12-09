add_executable(lights WIN32
    lights.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(lights PRIVATE d3dframe d3dim )
