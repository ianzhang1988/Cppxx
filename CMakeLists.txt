project(myproject)

add_definitions(-std=c++17)

# add_executable(../bin/std_accumulate src/std_accumulate.cpp)

# file( GLOB LIB_SOURCES lib/*.cpp )
# file( GLOB LIB_HEADERS lib/*.h )
# add_library( YourLib ${LIB_SOURCES} ${LIB_HEADERS} )

# If necessary, use the RELATIVE flag, otherwise each source file may be listed 
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
# file( GLOB APP_SOURCES RELATIVE app/*.cxx )
# file( GLOB APP_SOURCES src/*.cpp )
# foreach( testsourcefile ${APP_SOURCES} )
    # # I used a simple string replace, to cut off .cpp.
    # string( REPLACE ".cpp" "" testname ${testsourcefile} )
    # add_executable( ${testname} ${testsourcefile} )
    # # Make sure YourLib is linked to each app
    # #target_link_libraries( ${testname} YourLib )
# endforeach( testsourcefile ${APP_SOURCES} )

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp )
# file(MAKE_DIRECTORY bin)
MESSAGE( STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
MESSAGE( STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
MESSAGE( STATUS "lets see: ${APP_SOURCES}")
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR}/src ${sourcefile})
    MESSAGE( STATUS "filename: ${filename}")
    string( REPLACE ".cpp" "" file ${filename} )
    MESSAGE( STATUS "file: ${file}")
    # add_executable( ${CMAKE_CURRENT_SOURCE_DIR}/${file} ${sourcefile} )
    add_executable( ${file} ${sourcefile} )
    set_target_properties(${file} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
    # file(RENAME ${CMAKE_BINARY_DIR}/${file} ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
    # target_link_libraries( ${file} ndn-cxx boost_system )
endforeach( sourcefile ${APP_SOURCES} )
