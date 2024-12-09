add_executable(videotex WIN32
    videotex.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(videotex PRIVATE avifil32 d3dframe)
