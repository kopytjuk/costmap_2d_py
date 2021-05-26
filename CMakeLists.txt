cmake_minimum_required(VERSION 3.5)
project(costmap_2d_py)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(pybind11)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(nav2_costmap_2d REQUIRED)
find_package(nav2_util REQUIRED)
find_package(geometry_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(
  include
  ${nav2_costmap_2d_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
  ${nav2_util_INCLUDE_DIRS}
)

link_directories(/opt/ros/dashing/lib/)

message(STATUS "Variables: ${nav2_costmap_2d_INCLUDE_DIRS}")

ament_python_install_package(${PROJECT_NAME})

pybind11_add_module(mymodule src/example.cpp)
install(TARGETS mymodule
  DESTINATION "${PYTHON_INSTALL_DIR}/${PROJECT_NAME}"
)

pybind11_add_module(mymodule2 src/costmap_2d_py.cpp)
install(TARGETS mymodule2
  DESTINATION "${PYTHON_INSTALL_DIR}/${PROJECT_NAME}"
)

target_link_libraries(mymodule2 PRIVATE nav2_costmap_2d_core)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
