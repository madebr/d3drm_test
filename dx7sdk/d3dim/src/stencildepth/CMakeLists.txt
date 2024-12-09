add_executable(stencildepth WIN32
    stencildepth.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(stencildepth PRIVATE d3dframe)
