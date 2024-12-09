add_executable(playsound WIN32
    playsound.cpp
    wavread.cpp
    wavread.h
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(playsound PRIVATE dsound winmm)
