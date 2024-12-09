add_executable(faces
    faces.cpp
    rmmain.cpp
    resource.h

    faces.def
    rmmain.rc
    d3d.ico
)
target_link_libraries(faces PRIVATE d3drm ddraw)
