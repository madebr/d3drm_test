add_executable(quat WIN32
    quat.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    quat.def
    d3d.ico
)
target_link_libraries(quat PRIVATE d3drm ddraw)
