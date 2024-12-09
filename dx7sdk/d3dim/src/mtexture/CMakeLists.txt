add_executable(mtexture WIN32
    mtexture.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(mtexture PRIVATE d3dframe)
