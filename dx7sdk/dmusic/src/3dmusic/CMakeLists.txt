add_executable(3dmusic WIN32
    3dsound.cpp
    dsutil3d.c
    dsutil3d.h
    helper.cpp
    helper.h
    sound.cpp
    sound.h
    resource.h

    script1.rc
    icon1.ico
)
target_link_libraries(3dmusic PRIVATE dsound dxguid winmm)
