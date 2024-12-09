add_executable(diex3 WIN32
    diex3.cpp

    diex3.rc
    directx.ico
)
target_link_libraries(diex3 PRIVATE dinput dxguid)
