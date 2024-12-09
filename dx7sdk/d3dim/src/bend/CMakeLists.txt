add_executable(bend WIN32
    bend.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(bend PRIVATE d3dframe)
