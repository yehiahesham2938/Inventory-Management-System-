cmake_minimum_required(VERSION 3.26)
project(InventoryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(InventoryManagementSystem main.cpp
        src/DataStructures/Node.h
        src/SparePart.h
        src/DataStructures/LinkedList.h
        src/Supplier.h
        src/DataStructures/Stack.h
        src/DataStructures/Queue.h
        src/DataStructures/TreeNode.h
        src/History.h
        src/DataStructures/BinaryTree.h
        src/SparePartTree.h
        src/SupplierTree.h
        src/Connections.h
)
