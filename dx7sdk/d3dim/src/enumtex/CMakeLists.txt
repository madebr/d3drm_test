add_executable(enumtex WIN32
    enumtex.cpp
)
target_link_libraries(enumtex PRIVATE d3dxof ddraw dxguid)
