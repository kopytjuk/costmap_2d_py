PYINCLUDES = $(shell python3 -m pybind11 --includes)
EXECUTABLE_SUFFIX = $(shell python3-config --extension-suffix)

build:
	g++ -O3 -Wall -shared -std=c++11 -fPIC \
	$(PYINCLUDES) \
	-I../navigation2/nav2_costmap_2d/include \
	-I../navigation2/nav2_util/include \
	-I/opt/ros/dashing/include \
	../navigation2/nav2_costmap_2d/src/costmap_2d.cpp \
	costmap_2d_py.cpp \
	-o costmap_2d_py$(EXECUTABLE_SUFFIX)