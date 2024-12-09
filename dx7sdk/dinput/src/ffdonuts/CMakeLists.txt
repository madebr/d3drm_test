add_executable(ffdonuts WIN32
    ffdonuts.cpp
    ffdonuts.h
    ddutil.cpp
    ddutil.h
    diutil.cpp
    diutil.h
    dsutil.cpp
    resource.h

    ffdonuts.rc
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
target_link_libraries(ffdonuts PRIVATE ddraw dinput dsound)
target_compile_definitions(ffdonuts PRIVATE LPDIENUMEFFECTSCALLBACK=LPDIENUMEFFECTSCALLBACKA)
