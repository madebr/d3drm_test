add_executable(capturesound WIN32
    capturesound.cpp
    wavwrite.cpp
    wavwrite.h
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(capturesound PRIVATE dsound winmm)
