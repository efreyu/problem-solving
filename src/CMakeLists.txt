include(${CMAKE_SOURCE_DIR}/cmake/GTestHelper.cmake)

################### All solutions ###################
################### Arrays ###################
init_test(arrayTest main.cpp
        array/twoSum.cpp
        array/removeDuplicates.cpp
        array/rotateArray.cpp
        array/maxProfit.cpp
        array/containsDuplicate.cpp
        array/singleNumber.cpp
        array/intersection.cpp
        array/plusOne.cpp
        array/moveZeroes.cpp
        )

