#pragma once

#include <utility>
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

struct Edge { unsigned int src, dest, weight; };    ///< Structure representing an edge between two vertices
typedef std::pair<unsigned int, unsigned int> Pair; ///< Used by Edge structure to pair multiple dest/weights to one src

// Edges of planar dodecahedron
static const std::vector<Edge> s_planar_dodecahedron_edges
{
    { 1,  2, 5}, { 1,  5, 5}, { 1,  8, 1}, ///< Outer Layer
    { 2,  1, 5}, { 2,  3, 5}, { 2, 10, 1},
    { 3,  2, 5}, { 3,  4, 5}, { 3, 12, 1},
    { 4,  3, 5}, { 4,  5, 5}, { 4, 14, 1},
    { 5,  1, 5}, { 5,  4, 5}, { 5,  6, 1},
    { 6,  5, 1}, { 6,  7, 3}, { 6, 15, 3}, ///< Middle Layer
    { 7,  6, 3}, { 7,  8, 3}, { 7, 17, 2},
    { 8,  1, 1}, { 8,  7, 3}, { 8,  9, 3},
    { 9,  8, 3}, { 9, 10, 3}, { 9, 18, 2},
    {10,  2, 1}, {10,  9, 3}, {10, 11, 3},
    {11, 10, 3}, {11, 12, 3}, {11, 19, 2},
    {12,  3, 1}, {12, 11, 3}, {12, 13, 3},
    {13, 12, 3}, {13, 14, 3}, {13, 20, 2},
    {14,  4, 1}, {14, 13, 3}, {14, 15, 3},
    {15,  6, 2}, {15, 14, 3}, {15, 16, 2},
    {16, 15, 2}, {16, 17, 3}, {16, 20, 3}, ///< Inner Layer
    {17,  7, 2}, {17, 16, 3}, {17, 18, 3},
    {18,  9, 2}, {18, 17, 3}, {18, 19, 3},
    {19, 11, 2}, {19, 18, 3}, {19, 20, 3},
    {20, 13, 2}, {20, 16, 3}, {20, 19, 3}
};

static const unsigned int s_planar_dodecahedron_vertex_count = 20;

class Graph /// A class to represent a Graph
{
public:
    /// Graph Constructor
    Graph(std::vector<Edge> const &edges, const unsigned int n);
    
    virtual const std::vector<Edge> edges() const noexcept;
    virtual const unsigned int size() const noexcept;
    
private:
    
    std::vector<std::vector<Pair>> m_adjList;
    const std::vector<Edge>        m_edges;
    const unsigned int             m_size;
};

class Map : public sf::Drawable, public sf::Transformable ///< A class containing an initialized Graph to represent a Map with connecting edges
{
public:
    Map(std::vector<Edge> const &edges, const unsigned int n);
    
    const std::vector<Edge> edges() const noexcept;
    const unsigned int size() const noexcept;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    Graph              m_graph;
    sf::RectangleShape m_rect;
};
