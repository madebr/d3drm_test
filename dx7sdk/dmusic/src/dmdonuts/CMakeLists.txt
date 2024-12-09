add_executable(dmdonuts WIN32
    ddutil.cpp
    ddutil.h
    donuts.cpp
    donuts.h
    dsutil.cpp
    input.cpp
    input.h
    resource.h

    donuts.rc
    bangbang.wav
    bounce.wav
    c_bang.wav
    d_bang.wav
    donuts.bmp
    donuts.ico
    gunfire.wav
    hum.wav
    level.wav
    p_bang.wav
    rev.wav
    s_bang.wav
    shield.wav
    skid.wav
    splash.bmp
)
target_link_libraries(dmdonuts PRIVATE ddraw dinput dsound winmm)
