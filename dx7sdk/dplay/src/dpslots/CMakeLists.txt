add_executable(dpslots WIN32
    client.cpp
    dialog.cpp
    dpslots.cpp
    dpslots.h
    lobby.cpp
    server.cpp
    resource.h

    dpslots.rc
    media/ding.wav
    media/lose.wav
    media/wheel.bmp
    media/win.wav
)
target_link_libraries(dpslots PRIVATE dplayx winmm)
