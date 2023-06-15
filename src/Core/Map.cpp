#include "Map.hpp"

#include "Resources.hpp"

Graph::Graph(std::vector<Edge> const &edges, const unsigned int n)
    : m_edges{ edges }
    , m_size(n)
{
    m_adjList.clear();
    
    /// Resize vector to hold `n` elements of type vector<Edge>
    m_adjList.resize(n * 3);
    
    /// Iterate through edges : Form directed graph
    for (auto &edge : edges)
    {
        /// Get current edge data to insert
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;
        
        /// Push to back
        m_adjList[src].push_back( std::make_pair(dest, weight) );
    }
}

const std::vector<Edge> Graph::edges() const noexcept
{
    return m_edges;
}

const unsigned int Graph::size() const noexcept
{
    return m_size;
}





Map::Map(std::vector<Edge> const &edges, const unsigned int n)
    : m_graph(edges, n)
{
    m_rect.setSize({192.f, 192.f});
    m_rect.setTexture(&map_texture);
    m_rect.setPosition({448.f, 288.f});
}

const std::vector<Edge> Map::edges() const noexcept
{
    return m_graph.edges();
}
const unsigned int Map::size() const noexcept
{
    return m_graph.size();
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_rect);
}
