add_executable(musiclines WIN32
    debug.cpp
    debug.h
    dmhelper.cpp
    dmhelper.h
    mlai.cpp
    mlai.h
    mlbmpsrf.cpp
    mlbmpsrf.h
    mlgame.cpp
    mlgame.h
    mlinput.cpp
    mlinput.h
    mlinput.cpp
    mlinput.h
    mllocalplayer.cpp
    mllocalplayer.h
    mlmain.cpp
    mlmusic.cpp
    mlmusic.h
    mloptpal.cpp
    mloptpal.h
    mlrender.cpp
    mlrender.h
    musiclines.h
    resource.h

    musiclines.rc
    ml.ico
    backdrop2.bmp
    player0.bmp
    player1.bmp
    score0.bmp
    score1.bmp
)
target_link_libraries(musiclines PRIVATE ddraw dinput dxguid winmm)
