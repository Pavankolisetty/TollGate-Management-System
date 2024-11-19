# Toll Gate Management System - Dijkstra's Algorithm

## Description
The **Toll Gate Management System** is a simulation of a toll road network between various cities in India. It allows the user to input the source and destination cities, as well as the type of vehicle (Car, Truck, Bus), and then calculates the best route with the minimum toll cost using **Dijkstra's Algorithm**.

The system uses an adjacency list to represent the cities and the toll roads between them, and Dijkstra's algorithm is used to compute the shortest path with the least toll cost. The toll rates vary depending on the vehicle type, with higher tolls for larger vehicles like trucks.

This project provides a simple yet effective way to model toll roads and find optimal routes between cities in India.

## Features
- **Graph Representation**: Cities are represented as nodes and toll roads as weighted edges.
- **Dijkstra's Algorithm**: Calculates the least-cost path based on toll values.
- **Vehicle Type Differentiation**: Different toll rates for different vehicle types (Car, Truck, Bus).
- **Real Indian Cities**: The project uses 10 popular cities in India as the places in the toll network.

## Cities (Places)
The following Indian cities are used in the system:
- Mumbai
- Delhi
- Bangalore
- Chennai
- Kolkata
- Hyderabad
- Pune
- Ahmedabad
- Jaipur
- Lucknow

## Input
The user is prompted to input the following:
1. **Vehicle Type**: The type of vehicle, which can be **Car**, **Truck**, or **Bus**.
2. **Source City**: The starting city, selected from the list of available cities by entering the corresponding index number.
3. **Destination City**: The destination city, selected similarly by entering the index number.



## Output
The program will output:
- The best path from the source city to the destination city.
- The minimum toll cost for the journey based on the selected vehicle type.


## Benefits
1. **Efficient Route Calculation**: Uses **Dijkstra's Algorithm** to find the shortest path with the minimum toll cost.
2. **Vehicle-Specific Toll Calculation**: Different toll rates for different types of vehicles (Car, Truck, Bus).
3. **Real-World Application**: The project simulates a real-world toll system between major cities in India.
4. **Graph-Based Representation**: Easy to extend and modify with additional cities or toll roads.
5. **User-Friendly**: Simple input prompts guide the user to select cities and vehicle types for optimal path calculation.

## How to Run
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/your-username/toll-gate-management-system.git
   cd toll-gate-management-system

g++ toll_gate_system.cpp -o toll_gate_system
