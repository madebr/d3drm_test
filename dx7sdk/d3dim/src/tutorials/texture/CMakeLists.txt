add_executable(texture WIN32
    texture.cpp
    render.cpp
    winmain.cpp
    resource.h

    winmain.rc
    directx.ico
    earth.bmp
    tex1.bmp
    tree1.bmp
)
target_link_libraries(texture PRIVATE ddraw dxguid winmm)
