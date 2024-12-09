add_executable(lightmap WIN32
    lightmap.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(lightmap PRIVATE d3dframe)
