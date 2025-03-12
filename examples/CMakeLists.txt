file(GLOB_RECURSE EXAMPLE_SOURCE ${CMAKE_SOURCE_DIR}/examples/*.cpp)

foreach(EXAMPLE ${EXAMPLE_SOURCE})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE} ${SOURCE})
    target_include_directories(${EXAMPLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)
endforeach()