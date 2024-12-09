add_executable(adjustsound WIN32
    adjustsound.cpp
    wavread.cpp
    wavread.h
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(adjustsound PRIVATE comctl32 dsound winmm)
