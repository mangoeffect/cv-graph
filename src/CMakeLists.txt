include_directories(./)

set(HPP 
./graph/graph.hpp 
./graph/util.hpp 
./node/node_base.hpp 
)

set(CPP 
./graph/graph.cpp 
./graph/util.cpp 
./node/node_base.cpp 
)

find_package(OpenCV REQUIRED)
find_package(OpenMP REQUIRED)

if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    add_library(cv_graph ${HPP} ${CPP})
    target_link_libraries(cv_graph ${OpenCV_LIBS} OpenMP::OpenMP_CXX)
else()
    message(FATAL_ERROR "OpenCV not found!")
endif()

