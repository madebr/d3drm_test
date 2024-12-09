add_executable(rmbegin1 WIN32
    rmbegin1.cpp

    rmbegin1.rc
    d3d.ico
)
target_link_libraries(rmbegin1 PRIVATE d3drm ddraw)
