add_executable(spheremap WIN32
    spheremap.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(spheremap PRIVATE d3dframe)
