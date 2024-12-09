add_executable(fullduplexfilter WIN32
    fullduplexfilter.cpp
    winmain.cpp
    resource.h

    winmain.rc
    winmain.ico
)
target_link_libraries(fullduplexfilter PRIVATE dsound)
