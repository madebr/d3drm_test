add_executable(flare WIN32
    flare.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(flare PRIVATE d3dframe)
