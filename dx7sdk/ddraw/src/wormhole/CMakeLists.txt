add_executable(wormhole WIN32
    wormhole.cpp

    wormhole.rc
    directx.ico
    wormhole.bmp
)
target_link_libraries(wormhole PRIVATE ddraw dxguid)
