add_executable(bumpwaves WIN32
    bumpwaves.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(bumpwaves PRIVATE d3dframe)
