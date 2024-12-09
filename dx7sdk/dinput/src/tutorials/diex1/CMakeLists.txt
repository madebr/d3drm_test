add_executable(diex1 WIN32
    diex1.cpp

    diex1.rc
    directx.ico
)
target_link_libraries(diex1 PRIVATE dinput dxguid)
