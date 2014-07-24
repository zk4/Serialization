#ONLY HEADER required.

#A lite serialization solution
there are several lib out there support serialization,like protobuffer, boost:serialization , too heavy for me.  so I wrote this lite version.

#support 
* vector
* map
* set
* string
* primitives(int,double,long,...)

#build
you can build this project by CMake. or  just import **serialization.h** into your project.

camke build process:

```sh
	mkdir prj
	cd prj
	cmake ..
```

#demo
check testSerialization.cpp 




