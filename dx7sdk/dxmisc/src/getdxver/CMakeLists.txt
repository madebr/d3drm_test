add_executable(getdxver WIN32
    dxver.cpp
    getdxver.cpp
)
target_link_libraries(getdxver PRIVATE dxguid)
