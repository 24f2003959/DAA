#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

template <typename T>
class Graph {
private:
    int capacity;
    bool directed;
    std::vector<T> vertices;
    std::unordered_map<T, std::vector<T>> adjacency;

    bool hasVertex(const T& vertex) const {
        return adjacency.find(vertex) != adjacency.end();
    }

    bool hasEdge(const T& u, const T& v) const {
        auto it = adjacency.find(u);
        if (it == adjacency.end()) {
            return false;
        }

        return std::find(it->second.begin(), it->second.end(), v) != it->second.end();
    }

    void removeFromList(std::vector<T>& list, const T& value) {
        list.erase(std::remove(list.begin(), list.end(), value), list.end());
    }

public:
    Graph(int capacity, bool directed = false) {
        this->capacity = capacity;
        this->directed = directed;
    }

    void operator+(const T& vertex) {
        if (static_cast<int>(vertices.size()) == capacity) {
            std::cout << "Graph overflow\n";
            return;
        }

        if (hasVertex(vertex)) {
            std::cout << "Vertex already exists\n";
            return;
        }

        vertices.push_back(vertex);
        adjacency[vertex] = std::vector<T>();
    }

    void operator-(const T& vertex) {
        if (!hasVertex(vertex)) {
            std::cout << "Vertex not found\n";
            return;
        }

        vertices.erase(std::remove(vertices.begin(), vertices.end(), vertex), vertices.end());
        adjacency.erase(vertex);

        for (auto& item : adjacency) {
            removeFromList(item.second, vertex);
        }
    }

    void addEdge(const T& u, const T& v) {
        if (!hasVertex(u) || !hasVertex(v)) {
            std::cout << "Invalid edge: vertex not found\n";
            return;
        }

        if (hasEdge(u, v)) {
            std::cout << "Invalid edge: edge already exists\n";
            return;
        }

        adjacency[u].push_back(v);
        if (!directed && u != v) {
            adjacency[v].push_back(u);
        }
    }

    void removeEdge(const T& u, const T& v) {
        if (!hasVertex(u) || !hasVertex(v)) {
            std::cout << "Invalid edge: vertex not found\n";
            return;
        }

        if (!hasEdge(u, v)) {
            std::cout << "Edge not found\n";
            return;
        }

        removeFromList(adjacency[u], v);
        if (!directed && u != v) {
            removeFromList(adjacency[v], u);
        }
    }

    std::vector<T> DFS(const T& start) const {
        std::vector<T> order;
        if (!hasVertex(start)) {
            std::cout << "Start vertex not found\n";
            return order;
        }

        std::unordered_map<T, bool> visited;
        std::stack<T> st;
        st.push(start);

        while (!st.empty()) {
            T current = st.top();
            st.pop();

            if (visited[current]) {
                continue;
            }

            visited[current] = true;
            order.push_back(current);

            const std::vector<T>& neighbors = adjacency.at(current);
            for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                if (!visited[*it]) {
                    st.push(*it);
                }
            }
        }

        return order;
    }

    std::vector<T> BFS(const T& start) const {
        std::vector<T> order;
        if (!hasVertex(start)) {
            std::cout << "Start vertex not found\n";
            return order;
        }

        std::unordered_map<T, bool> visited;
        std::queue<T> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            T current = q.front();
            q.pop();
            order.push_back(current);

            for (const T& neighbor : adjacency.at(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return order;
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph<T>& graph) {
        if (graph.vertices.empty()) {
            os << "Graph is empty\n";
            return os;
        }

        os << "DFS: ";
        for (const T& vertex : graph.DFS(graph.vertices.front())) {
            os << vertex << " ";
        }

        os << "\nBFS: ";
        for (const T& vertex : graph.BFS(graph.vertices.front())) {
            os << vertex << " ";
        }

        os << "\n";
        return os;
    }
};
