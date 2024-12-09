add_executable(duel WIN32
    ddutil.cpp
    ddutil.h
    diutil.cpp
    diutil.h
    dpconnect.cpp
    dputil.cpp
    dputil.h
    dsutil.cpp
    dsutil.h
    duel.cpp
    duel.h
    gameproc.cpp
    gameproc.h
    gfx.cpp
    gfx.h
    lobby.cpp
    lobby.h
    util.cpp
    resource.h

    duel.rc
    bfire.wav
    csession.bmp
    duel.bmp
    duel.ico
    lboom.wav
    osession.bmp
    player.bmp
    sboom.wav
    sbounce.wav
    sengine.wav
    splash.bmp
    sstart.wav
    sstop.wav
)
target_link_libraries(duel PRIVATE ddraw dinput dsound winmm)
