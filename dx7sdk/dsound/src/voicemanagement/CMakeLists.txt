add_executable(voicemanagement WIN32
    voicemanagement.cpp
    wavread.cpp
    wavread.h
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(voicemanagement PRIVATE dsound winmm)
