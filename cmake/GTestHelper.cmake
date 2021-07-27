include(${CMAKE_SOURCE_DIR}/cmake/AddGoogleTest.cmake)

function(INIT_TEST ARG_TARGET)
    add_executable(${ARG_TARGET} ${ARGN})
    target_compile_features(${ARG_TARGET} PRIVATE cxx_std_17)
    target_compile_options(${ARG_TARGET} PRIVATE -Wall)
    add_gtest(${ARG_TARGET})
endfunction()