add_executable(keybdimm WIN32
    keybdimm.cpp
    keybdimm.h
    winmain.cpp
    resource.h

    keybdimm.rc
    directx.ico
)
target_link_libraries(keybdimm PRIVATE dinput dxguid)
