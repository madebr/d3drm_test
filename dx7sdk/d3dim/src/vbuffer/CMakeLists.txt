add_executable(vbuffer WIN32
    vbuffer.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(vbuffer PRIVATE d3dframe)
