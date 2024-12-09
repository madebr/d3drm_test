add_executable(diex4 WIN32
    diex4.cpp

    diex4.rc
    directx.ico
)
target_link_libraries(diex4 PRIVATE dinput dxguid)
