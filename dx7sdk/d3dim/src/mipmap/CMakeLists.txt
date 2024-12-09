add_executable(mipmap WIN32
    mipmap.cpp
    resource.h

    winmain.rc
    directx.ico
    brick0.bmp
    brick1.bmp
    brick2.bmp
    brick3.bmp
    brick4.bmp
)
target_link_libraries(mipmap PRIVATE d3dframe)
