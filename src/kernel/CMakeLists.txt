file(GLOB kernel_sources CONFIGURE_DEPENDS "*.[co]")

add_library(kernelx STATIC ${kernel_sources})
