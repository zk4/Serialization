set(SOURCE_DIR "src")
 
include_directories (
	${SOURCE_DIR} 
	)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(testSerialization
		${SOURCE_DIR}/testSerialization.cpp
		)

 
