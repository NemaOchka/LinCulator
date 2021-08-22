cmake_minimum_required(VERSION 3.10)
project("LinCulator"
	VERSION 1.0.0
        LANGUAGES CXX)
set(LIBRARY_NAME Classes)
#==================================================
#SET HEADERS
#==================================================

list(APPEND headers_path "${CMAKE_CURRENT_SOURCE_DIR}/include")
#==================================================
#SET SOURCES
#==================================================
#set(CMAKE_BUILD_TYPE Debug)
set(sources_path ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(exec_source
    ${sources_path}/LinCulator.cpp)
set(srcs
    ${sources_path}/Fraction.cpp
    ${sources_path}/Matrix.cpp
    ${sources_path}/MyNamespace.cpp)


add_library(${LIBRARY_NAME} SHARED )
set_target_properties(
    ${LIBRARY_NAME}
    PROPERTIES
      VERSION ${PROJECT_VERSION}
      SOVERSION ${PROJECT_VERSION}
  )
target_include_directories(
  ${LIBRARY_NAME}
  PRIVATE
    ${headers_path}
)
target_sources(
  ${LIBRARY_NAME}
  PRIVATE
    ${srcs}
)


add_executable(${PROJECT_NAME} ${exec_source})
set_target_properties(
	${PROJECT_NAME}
    PROPERTIES
      VERSION ${PROJECT_VERSION}
      SOVERSION ${PROJECT_VERSION}
  )
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
    ${headers_path}
)
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
    Classes
)

#==================================================
#INSTALLING MQTT_LIBRARY IN SYSTEM
#==================================================
include(GNUInstallDirs)
 set(targets_export_name ${LIBRARY_NAME}-targets)
  set(include_install_dir ${CMAKE_INSTALL_LIBDIR})

  install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/LinCulator
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(
    TARGETS ${LIBRARY_NAME}
    EXPORT ${targets_export_name}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(
    EXPORT ${targets_export_name}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME}
  )

  file(
    WRITE ${CMAKE_CURRENT_BINARY_DIR}/config.cmake.in [==[
    include("${CMAKE_CURRENT_LIST_DIR}/@targets_export_name@.cmake")
    ]==]
  )

  include(CMakePackageConfigHelpers)
  configure_package_config_file(
    ${CMAKE_CURRENT_BINARY_DIR}/config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME}
    PATH_VARS include_install_dir
  )

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}-config-version.cmake
    VERSION "${PROJECT_VERSION}" COMPATIBILITY SameMajorVersion
  )
  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}-config-version.cmake
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME}
  )



 set(targets_export_name ${PROJECT_NAME}-targets)        
  set(include_install_dir ${CMAKE_INSTALL_LIBDIR})
 
  install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/LinCulator
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
 
  install(
	  TARGETS ${PROJECT_NAME}
    EXPORT ${targets_export_name}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
 
  install(
    EXPORT ${targets_export_name}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  )
 
  file(
    WRITE ${CMAKE_CURRENT_BINARY_DIR}/config.cmake.in [==[
    include("${CMAKE_CURRENT_LIST_DIR}/@targets_export_name@.cmake")
    ]==]
  )
 
  include(CMakePackageConfigHelpers)
  configure_package_config_file(
    ${CMAKE_CURRENT_BINARY_DIR}/config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    PATH_VARS include_install_dir
  )
 
  write_basic_package_version_file(
	  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
    VERSION "${PROJECT_VERSION}" COMPATIBILITY SameMajorVersion
  )
  install(
	  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
	  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake 
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  )


