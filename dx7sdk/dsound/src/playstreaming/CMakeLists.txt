add_executable(playstreaming WIN32
    playstreaming.cpp
    wavread.cpp
    wavread.h
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(playstreaming PRIVATE dsound winmm)
