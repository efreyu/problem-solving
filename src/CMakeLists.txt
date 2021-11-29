include(${CMAKE_SOURCE_DIR}/cmake/GTestHelper.cmake)

################### All solutions ###################
################### Arrays ###################
init_test(arrayTest main.cpp
        array/twoSum.cpp
        array/removeDuplicates.cpp
        )

