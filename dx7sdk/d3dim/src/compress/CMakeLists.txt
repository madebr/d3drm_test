add_executable(compress WIN32
    compress.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(compress PRIVATE d3dframe)
