#ifndef NIU_CSCI340_GRAPH_H
#define NIU_CSCI340_GRAPH_H

// This is the file where the student should do their work.

#include "graph.decl.h"
#include <queue>
#include <stack>
#include <iostream>

size_t Graph::nvertices() const {
  // XXX You must implement this.
  return 0;
}
size_t Graph::nedges() const { 
  // XXX You must implement this.
  return 0; 
}

void Graph::assign(const std::vector<std::string> & vertices, const std::vector<GraphEdge> & edges) {
  // XXX You must implement this.
}

bool Graph::edge_exists(size_t origin, size_t destination) const {
  // XXX You must implement this.
  return false; }

double Graph::edge_weight(size_t origin, size_t destination) const {
  // XXX You must implement this.
  return 99999;
}

std::vector<AdjListEdge> Graph::undirected_adjacency_list(size_t vertex) const {
  // XXX You must implement this.
  return {};
}

std::vector<AdjListEdge> Graph::in_adjacency_list(size_t vertex) const {
  // XXX You must implement this.
  return {};
}

std::vector<AdjListEdge> Graph::out_adjacency_list(size_t vertex) const {
  // XXX You must implement this.
  return {};
}

std::vector <double> Graph::weighted_adjacency_matrix() const {
  // XXX You must implement this.
  return {};
}

std::vector <bool> Graph::unweighted_adjacency_matrix() const {
  // XXX You must implement this.
  return {};
}

std::string Graph::v_label(size_t vertex) const {
  // XXX You must implement this.
  return "wrong";
}

ssize_t Graph::v_index(const std::string &label) const {
  // XXX You must implement this.
  return -1; }

template <typename FN>
void Graph::breadth_first(size_t start, FN visitfn, bool connected_only) {
  // XXX You must implement this.
}

template <typename FN>
void Graph::depth_first(size_t start, FN visitfn, bool connected_only) {
  // XXX You must implement this.
}

std::vector<size_t> Graph::toposort() const {
  // XXX You must implement this.
  return {};
}
    
std::vector<dijkstra_row> Graph::dijkstra(size_t start) const {
  // XXX You must implement this.
  return {};
}


#endif /* NIU_CSCI340_GRAPH_H */

