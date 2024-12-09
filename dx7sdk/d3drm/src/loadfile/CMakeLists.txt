add_executable(loadfile WIN32
    loadfile.cpp
    winmain.cpp
    resource.h

    winmain.rc
    d3d.ico
)
target_link_libraries(loadfile PRIVATE d3drm ddraw)
