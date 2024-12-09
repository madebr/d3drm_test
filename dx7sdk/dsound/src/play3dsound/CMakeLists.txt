add_executable(play3dsound WIN32
    play3dsound.cpp
    wavread.cpp
    wavread.h
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
    bitmap1.bmp
)
target_link_libraries(play3dsound PRIVATE comctl32 dsound winmm)
