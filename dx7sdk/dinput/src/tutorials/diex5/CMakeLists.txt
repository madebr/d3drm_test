add_executable(diex5 WIN32
    diex5.cpp

    diex5.rc
    directx.ico
)
target_link_libraries(diex5 PRIVATE dinput dxguid)
