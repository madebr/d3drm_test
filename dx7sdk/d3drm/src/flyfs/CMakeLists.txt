add_executable(flyfs
    fly.cpp
    d3dapp.c
    d3dapp.h
    d3dappi.h
    d3dcalls.c
    ddcalls.c
    misc.c
    rmfull.cpp
    rmfull.h
    rmstats.cpp
    texture.c
    resource.h

    rmfull.rc
    d3d.ico
)
target_link_libraries(flyfs PRIVATE d3drm ddraw)
