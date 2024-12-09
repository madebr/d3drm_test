add_executable(particle WIN32
    particle.cpp
    cframetimer.cpp
    cframetimer.hpp
    cground.cpp
    cground.hpp
    cparticle.cpp
    cparticle.hpp
    resource.h
    pch.cpp
    pch.hpp

    particle.rc
    directx.ico
)
target_link_libraries(particle PRIVATE d3dx)
