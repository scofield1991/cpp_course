#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <map>
#include <vector>
#include <stdexcept>

class Graph
{
    map<int, vector<int> > nodes;
public:
    Graph(const vector<int> &starts, const vector<int> &ends);
    int numOutgoing(const int nodeId) const;
    const vector<int> &adjacent(const int nodeID);
};

Graph::Graph(const vector<int> &starts, const vector<int> &ends)
{
    if(starts.size() != ends.size())
        throw std::invalid_argument("Sizes of starts "
                                    "and ends are not the same!");
    //map<int, vector<int> >::iterator p = starts.begin();

    for(int i=0; i < starts.size(); i++)
    {
        nodes[starts[i]].push_back(ends[i]);
    }
}

#endif // GRAPH_H_INCLUDED
