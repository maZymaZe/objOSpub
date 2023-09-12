file(GLOB fs_sources CONFIGURE_DEPENDS "*.[co]")

add_library(fs STATIC ${fs_sources})
