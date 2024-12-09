add_executable(trans WIN32
    trans.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    trans.def
    d3d.ico
)
target_link_libraries(trans PRIVATE d3drm ddraw)
