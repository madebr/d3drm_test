add_executable(boids WIN32
    boids.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(boids PRIVATE d3dframe)
