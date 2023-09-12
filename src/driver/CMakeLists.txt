file(GLOB driver_sources CONFIGURE_DEPENDS "*.[co]")

add_library(driver STATIC ${driver_sources})
