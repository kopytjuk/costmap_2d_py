import costmap_2d_py

print("Import suceeded!")

costmap = costmap_2d_py.Costmap2D(100, 10, 0.1, -0.42, -0.42, 5)
print(costmap.getCost(0, 0))