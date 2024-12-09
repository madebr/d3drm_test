add_library(dmhook MODULE
    dmhook.cpp
    ../dmshell/events.h

    dmhook.def
)
set_property(TARGET dmhook PROPERTY PREFIX "")
if(MINGW)
    target_link_options(dmhook PRIVATE "-Wl,--enable-stdcall-fixup")
endif()
