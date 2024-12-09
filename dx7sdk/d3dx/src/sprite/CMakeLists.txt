add_executable(sprite WIN32
    sprite.cpp
    resource.h

    sprite.rc
    directx.ico
)
target_link_libraries(sprite PRIVATE d3dx ddraw winmm)
