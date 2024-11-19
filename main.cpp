#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

#define INF INT_MAX

unordered_map<string, double> vehicleTypeMultiplier = {
    {"Car", 1.0},
    {"Truck", 1.5},
    {"Bus", 1.2}
};

class TollGateSystem {
public:
    int numPlaces;
    vector<vector<pair<int, double>>> adjList;

    TollGateSystem(int n) {
        numPlaces = n;
        adjList.resize(n);
    }

    void addRoad(int u, int v, double toll) {
        adjList[u].push_back({v, toll});
        adjList[v].push_back({u, toll});
    }

    void dijkstra(int src, vector<double>& dist, vector<int>& parent, string vehicleType) {
        dist.assign(numPlaces, INF);
        parent.assign(numPlaces, -1);
        dist[src] = 0;

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0, src});

        double tollMultiplier = vehicleTypeMultiplier[vehicleType];

        while (!pq.empty()) {
            int u = pq.top().second;
            double currentDist = pq.top().first;
            pq.pop();

            if (currentDist > dist[u]) continue;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                double toll = neighbor.second * tollMultiplier;

                if (dist[u] + toll < dist[v]) {
                    dist[v] = dist[u] + toll;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    void printPath(int dest, vector<int>& parent) {
        if (dest == -1) {
            cout << "No path exists." << endl;
            return;
        }
        if (parent[dest] == -1) {
            cout << "Path: " << dest << endl;
            return;
        }
        printPath(parent[dest], parent);
        cout << " -> " << dest;
    }
};

int main() {
    vector<string> places = {"Mumbai", "Delhi", "Bangalore", "Chennai", "Kolkata",
                             "Hyderabad", "Pune", "Ahmedabad", "Jaipur", "Lucknow"};
   
    cout << "Places available in the TollGate System:" << endl;
    for (int i = 0; i < places.size(); ++i) {
        cout << i << ": " << places[i] << endl;
    }

    TollGateSystem system(10);

    system.addRoad(0, 1, 15.0);
    system.addRoad(0, 2, 20.0);
    system.addRoad(1, 2, 25.0);
    system.addRoad(2, 3, 10.0);
    system.addRoad(3, 4, 12.0);
    system.addRoad(4, 5, 8.0);
    system.addRoad(5, 6, 18.0);
    system.addRoad(6, 7, 22.0);
    system.addRoad(7, 8, 17.0);
    system.addRoad(8, 9, 14.0);

    string vehicleType;
    int source, destination;

    cout << "Enter vehicle type (Car, Truck, Bus): ";
    cin >> vehicleType;

    cout << "Enter source place (0=Mumbai, 1=Delhi, 2=Bangalore, 3=Chennai, 4=Kolkata, 5=Hyderabad, 6=Pune, 7=Ahmedabad, 8=Jaipur, 9=Lucknow): ";
    cin >> source;
   
    if (source < 0 || source >= places.size()) {
        cout << "Invalid source place!" << endl;
        return 1;
    }

    cout << "Enter destination place (0=Mumbai, 1=Delhi, 2=Bangalore, 3=Chennai, 4=Kolkata, 5=Hyderabad, 6=Pune, 7=Ahmedabad, 8=Jaipur, 9=Lucknow): ";
    cin >> destination;

    if (destination < 0 || destination >= places.size()) {
        cout << "Invalid destination place!" << endl;
        return 1;
    }

    if (vehicleTypeMultiplier.find(vehicleType) == vehicleTypeMultiplier.end()) {
        cout << "Invalid vehicle type!" << endl;
        return 1;
    }

    vector<double> dist(10);
    vector<int> parent(10);
    system.dijkstra(source, dist, parent, vehicleType);

    cout << "Best path from " << places[source] << " to " << places[destination] << " is: ";
    system.printPath(destination, parent);
    cout << endl;

    cout << "Minimum toll cost: " << dist[destination] << endl;

    return 0;
}
