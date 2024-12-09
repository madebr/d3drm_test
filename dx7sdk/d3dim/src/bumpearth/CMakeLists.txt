add_executable(bumpearth WIN32
    bumpearth.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(bumpearth PRIVATE d3dframe)
