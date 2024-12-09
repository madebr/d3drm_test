add_executable(envcube WIN32
    envcube.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(envcube PRIVATE d3dframe)
