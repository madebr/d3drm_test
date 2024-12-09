add_executable(stencilmirror WIN32
    mirror.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(stencilmirror PRIVATE d3dframe)
