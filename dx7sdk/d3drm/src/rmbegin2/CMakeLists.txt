add_executable(rmbegin2 WIN32
    rmbegin2.cpp

    rmbegin2.rc
    d3d.ico
)
target_link_libraries(rmbegin2 PRIVATE d3drm ddraw)
