add_executable(dmboids WIN32
    boids.cpp
    boids.h
    common.h
    d3dscene.h
    d3dtex.cpp
    d3dtex.h
    d3dutils.cpp
    d3dutils.h
    d3dutils.inl
    d3dwin.cpp
    d3dwin.h
    debug.cpp
    debug.h
    drvmgr.cpp
    drvmgr.h
    flock.cpp
    gull.cpp
    input.cpp
    input.h
    music.cpp
    music.h
    winmain.cpp
    winproc.cpp
    winproc.h
    resource.h


    dmboids.rc
    d3d.ico
    dx5.bmp
)
target_link_libraries(dmboids PRIVATE ddraw dinput dxguid)
