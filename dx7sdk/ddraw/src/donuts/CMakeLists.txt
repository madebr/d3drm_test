add_executable(donuts WIN32
    donuts.c
    donuts.h
    ddutil.cpp
    dsutil.c
    input.c
    input.h
    resource.h

    donuts.rc
    donuts.ico
    bangbang.wav
    bounce.wav
    c_bang.wav
    c_bang.wav
    d_bang.wav
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
target_link_libraries(donuts PRIVATE ddraw dinput dxguid winmm)
