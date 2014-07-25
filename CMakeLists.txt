set(SOURCE_DIR "src")
 
include_directories (
	${SOURCE_DIR} 
	)
add_executable(testSerialization
		${SOURCE_DIR}/core/serialization.h
		${SOURCE_DIR}/core/serialization.cpp
		${SOURCE_DIR}/core/ISerializable.h
		${SOURCE_DIR}/testSerialization.cpp
		)

 