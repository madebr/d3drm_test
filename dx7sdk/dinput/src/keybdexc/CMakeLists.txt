add_executable(keybdexc WIN32
    keybdexc.cpp
    resource.h

    keybdexc.rc
    directx.ico
)
target_link_libraries(keybdexc PRIVATE dinput dxguid)
