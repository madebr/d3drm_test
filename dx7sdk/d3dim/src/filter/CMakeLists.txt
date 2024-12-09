add_executable(filter WIN32
    filter.cpp
    resource.h

    winmain.rc
    directx.ico
)
target_link_libraries(filter PRIVATE d3dframe)
