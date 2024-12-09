add_executable(shadowvol2 WIN32
    shadowvol2.cpp
    chull.cpp
    geom.cpp
    shadow.h
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(shadowvol2 PRIVATE d3dframe)
