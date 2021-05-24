#include <pybind11/pybind11.h>

#include "nav2_costmap_2d/costmap_2d.hpp"

// first compile with g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) -I/home/marat/Code/navigation2/nav2_costmap_2d/include -I/home/marat/Code/navigation2/nav2_util/include -I/opt/ros/dashing/include costmap_python.cpp nav2_costmap_2d/src/costmap_2d.cpp -L /opt/ros/dashing/lib -lboost_python3 -o costmap_python$(python3-config --extension-suffix)

namespace py = pybind11;
namespace nav2 = nav2_costmap_2d;

PYBIND11_MODULE(costmap_2d_py, m)
{
    
    m.doc() = "This is a Python binding of costmap_2d";

    py::class_<nav2::Costmap2D>(m, "Costmap2D")
        .def(py::init<unsigned int, unsigned int, double,
                      double, double, unsigned char>())
        .def("getCost", static_cast<unsigned char (nav2::Costmap2D::*)(unsigned int, unsigned int) const>(&nav2::Costmap2D::getCost), "Get the cost of a cell in the costmap");
}
