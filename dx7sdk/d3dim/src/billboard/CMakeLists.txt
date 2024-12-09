add_executable(billboard WIN32
    billboard.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(billboard PRIVATE d3dframe)
