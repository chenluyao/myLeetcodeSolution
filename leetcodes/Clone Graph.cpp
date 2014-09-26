/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<UndirectedGraphNode *,UndirectedGraphNode *> nodeMap;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       if(node == NULL)
       {
           return NULL;
       }
       UndirectedGraphNode * newNode;
       if(nodeMap.find(node) == nodeMap.end())
       {
           newNode = new UndirectedGraphNode(node->label);
           nodeMap[node] = newNode;
       }
       else
       {
           return nodeMap[node];
       }
       int m = (node->neighbors).size();
       int i;
       for(i = 0; i < m; i++)
       {
           (newNode->neighbors).push_back(cloneGraph((node->neighbors)[i]));
       }
       return newNode;
    }
};