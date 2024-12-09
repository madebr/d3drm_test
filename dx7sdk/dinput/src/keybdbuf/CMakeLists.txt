add_executable(keybdbuf WIN32
    keybdbuf.cpp
    keybdbuf.h
    winmain.cpp
    resource.h

    keybdbuf.rc
    directx.ico
)
target_link_libraries(keybdbuf PRIVATE dinput)
