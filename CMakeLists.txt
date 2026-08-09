cmake_minimum_required(VERSION 3.20)
project(MagiqueNumbers VERSION 1.0.2)
include(GNUInstallDirs)
add_executable(MagiqueNumbers src/Magicnumbers.cpp)
set_target_properties(MagiqueNumbers PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED ON)

install(TARGETS MagiqueNumbers
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER sammyj48)
include(CPack)
cpack_add_component(magiquenumbers
    DISPLAY_NAME MagiqueNumbers
    DESCRIPTION A fun guessing game with numbers!
)


