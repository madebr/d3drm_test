add_executable(fireworks WIN32
    fireworks.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(fireworks PRIVATE d3dframe)
