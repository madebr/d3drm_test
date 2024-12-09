add_executable(xfile WIN32
    xfile.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(xfile PRIVATE d3dframe)
