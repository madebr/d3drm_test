add_executable(xofuser
    mytest.cpp
    mysave.cpp
    mysave.h
    mytypes.h
    myguids.h
)
target_link_libraries(xofuser PRIVATE d3dxof)
