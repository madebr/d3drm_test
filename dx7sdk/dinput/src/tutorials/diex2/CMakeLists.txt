add_executable(diex2 WIN32
    diex2.cpp

    diex2.rc
    directx.ico
)
target_link_libraries(diex2 PRIVATE dinput dxguid)
