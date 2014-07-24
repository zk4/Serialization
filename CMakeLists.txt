set(SOURCE_DIR "src")
 
include_directories (
	${SOURCE_DIR} 
	)
add_executable(testSerialization
		${SOURCE_DIR}/serialization.h
		${SOURCE_DIR}/testSerialization.cpp
		)

 