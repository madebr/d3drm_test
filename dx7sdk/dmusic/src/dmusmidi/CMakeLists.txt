add_executable(dmusmidi WIN32
    debug.c
    debug.h
    global.h
    mainwnd.c
    midiplyr.c
    midiplyr.h
    timewnd.c
    uiutils.c
    resource.h

    midiplyr.ico
    midiplyr.rc
    toolbar.bmp
)
target_link_libraries(dmusmidi PRIVATE comctl32 dxguid)
