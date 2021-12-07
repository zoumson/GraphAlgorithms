
   
function (make_exe name Custom_LIB)

#Bring the sources
file(GLOB SOURCES_DEMO ${PROJECT_SOURCE_DIR}/src/demo/${name}/*.cpp)

#Build the executable
add_executable(${name} ${SOURCES_DEMO})

#Link the libraries 
target_link_libraries(${name} ${Custom_LIB})
#target_link_libraries(${name} ${Custom_LIB} ${Boost_LIBRARIES})

endfunction()


make_exe(demo1 trasversal)
#make_exe(demo2 lib2)
#set(demo3_libs  lib1 lib2)
#make_exe(demo3 "${demo3_libs}")

#set(demo4_libs  lib1 lib2 ${Boost_LIBRARIES}))
#make_exe(demo3 "${demo4_libs}")