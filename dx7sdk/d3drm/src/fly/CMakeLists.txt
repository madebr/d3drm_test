add_executable(fly WIN32
    fly.cpp
    rmmain.cpp
    resource.h

    fly.def
    rmmain.rc
    d3d.ico
)
target_link_libraries(fly PRIVATE d3drm ddraw)
