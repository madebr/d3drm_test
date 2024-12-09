add_executable(clipmirror WIN32
    clipmirror.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(clipmirror PRIVATE d3dframe)
