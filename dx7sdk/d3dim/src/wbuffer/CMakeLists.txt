add_executable(wbuffer WIN32
    wbuffer.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(wbuffer PRIVATE d3dframe)
