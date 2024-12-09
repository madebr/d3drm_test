add_executable(shadowvol WIN32
    shadowvol.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(shadowvol PRIVATE d3dframe)
