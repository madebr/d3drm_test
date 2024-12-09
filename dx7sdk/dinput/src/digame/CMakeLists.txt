add_executable(digame WIN32
    digame.cpp
    gameplay.cpp
    resource.h

    digame.rc
    directx.ico
    bitmap2.bmp
    bitmap3.bmp
    bitmap5.bmp
    bmp00001.bmp
    bmp00002.bmp
    bmp00003.bmp
    bmp00004.bmp
    bmp00005.bmp
    bmp00006.bmp
    bmp00007.bmp
    explosio.bmp
    rbarrier.bmp
    spaceshi.bmp
)
target_link_libraries(digame PRIVATE dinput dxguid winmm)
