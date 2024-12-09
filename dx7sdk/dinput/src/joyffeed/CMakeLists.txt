add_executable(joyffeed WIN32
    joyffeed.cpp
    joyffeed.h
    winmain.cpp
    resource.h

    joyffeed.rc
    directx.ico
)
target_link_libraries(joyffeed PRIVATE dinput winmm)
