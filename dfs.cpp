#include <vector>
#include <stack>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  /**
   * DFS - left to right
   *
   * O(v + e) time - Time complexity grows with the combination of vertices
   *   and edges in the graph.
   * O(v) space - For each vertex in the graph, a new call to depthFirstSearch
   *  is placed on the call stack, so memory grows with `v`.
   */
  vector<string> depthFirstSearch(vector<string> *array) {
    array->push_back(this->name);

    for (int i = 0; i < this->children.size(); i++) {
      this->children[i]->depthFirstSearch(array);
    }

    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
