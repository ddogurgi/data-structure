#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <vector>
#include <unordered_map>
#include <list>
#include <tuple>

/* Feel free to add more standard library headers */

// A vertex is typed as `vertex_t`. An edge is typed as `edge_t`,
// which is associated with a source vertex, a destination vertex, and
// its weight. A list of edges is typed as `edges_t`, which is a
// vector of `edge_t`.

using vertex_t = std::size_t;
using edge_weight_t = double;
using edge_t = std::tuple<vertex_t,
                          vertex_t,
                          edge_weight_t>;
using edges_t = std::vector<edge_t>;

enum class GraphType {
UNDIRECTED,
DIRECTED
};

/*
 * We do not enforce a specific design constraints other than the
 * consturtor. You may introduce your own changes as you
 * want---implementing your own member functions or variables. You
 * will still need to ensure that your constructor works properly,
 * such that we can run the test for grading. The provided test will
 * check if the constructor is correctly designed.
 */
class Graph {
    public:
        Graph() = delete;
        Graph(const Graph&) = delete;
        Graph(Graph&&) = delete;

        /* We assume that if num_vertices is n, a graph contains n vertices
           from 0 to n-1. */
        Graph(size_t num_vertices,
              const edges_t& edges,
              GraphType Type) {
            // TODO: Implement the constructor
            _num_vertices = num_vertices;
            _Type = Type;
            adj_list.resize(num_vertices, std::vector<std::tuple<vertex_t, edge_weight_t>>(0, std::make_tuple(0, 0.0f)));
            //indegree.resize(num_vertices);
            for(edge_t edge : edges){
                adj_list[std::get<0>(edge)].push_back(std::make_tuple(std::get<1>(edge), std::get<2>(edge)));
                if(Type == GraphType::UNDIRECTED)
                    {adj_list[std::get<1>(edge)].push_back(std::make_tuple(std::get<0>(edge), std::get<2>(edge)));}
            }
        }
        // TODO(optional): Define helper functions, e.g., out_deges(v)
		std::vector<std::vector<std::tuple<vertex_t, edge_weight_t>>> get_adj_list(){return adj_list;} 
        bool isdirected(){return (_Type == GraphType::DIRECTED) ? true : false;}
        size_t get_num_vertices(){return _num_vertices;}

    private:
        // TODO: Roll out your own data structures
        std::vector<std::vector<std::tuple<vertex_t, edge_weight_t>>> adj_list;
        size_t _num_vertices;
        GraphType _Type;
};

#endif // __GRAPH_H_
