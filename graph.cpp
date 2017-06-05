//CPP file for graph creator, C++ Period 07, Colin Aslett
#include <iostream>
#include "graph.h"
#include <cstring>

using namespace std;
int match(vector<char*> &vec, const char* label);
char* Copy(char* str);
void pathCopy(vector<char*> &destination, vector<char*> &index);
graph::graph() : num(numeric_limits<int>::max()){}
//deleting the graph, have to deallocate everything inside of it
graph::~graph(){
  //going through the labels vector and deleting all elements
  for(int i = 0;i < label.size();i++){
    delete[] label[i];
    label[i] = 0;
  }
  //going throught the matrix vector and deleting all elements
  for(int a = 0;a < matrix.size();a++){
    delete matrix[a];
    matrix[a] = 0;
  }
}
//adding vertex label to labels vertex, only if does not already exist in the vertex
bool graph::vertex(const char* name){
  //has to make sure there is not a vertex already in the vector with the same label
  if(match(label,name) != -1){
    return false;
  }
  label.push_back(strcpy(new char[strlen(name)+1],name));
  //have to make sure the old vertexs dont connect to the new vertex
  for(int i = 0; i < matrix.size();i++){
    matrix[i]->push_back(-1);
  }
  //adding vertex's connections
  matrix.push_back(new vector<int>);
  for(int a = 0;a < matrix.size();a++){
    matrix[matrix.size()-1]->push_back(-1);
  }
  return true;
}
//adding edge for two vertexs
bool graph::edge(const char* name1, const char* name2, int x){
  //seeing if there are vertexs with the names that have been given
  //int n1 = match(label,name1);
  //int n2 = match(label,name2);
  int n1 = match(label, name1), n2 = match(label, name2);
  if(n1 == -1 || n2 == -1){
    return false;
  }
  (*matrix[n1])[n2] = x;//setting edge in the adjecency matrix to the weight
  return true;
}
//removing a vertex
bool graph::delvertex(const char* name){
  //finding whether the vertex is inside of the graph/vector
  int n = match(label,name);
  if(n == -1){
    return false;
  }
  //if it is in the vertex then we can delete it
  delete[] label[n];
  label.erase(label.begin() + n);//erasing the vertex in the vector
  //erasing the connections, if any, from the vertex
  for(int a = 0;a < matrix.size();a++){
    matrix[a]->erase(matrix[a]->begin() + n);
  }
  delete matrix[n];
  matrix.erase(matrix.begin() + n);
  return true;
}
//adding a double edge
bool graph::dbedge(const char* name1, const char* name2, int x){
  return edge(name1, name2, x) && edge(name2, name1, x);//using the edge function twice
}
//finding the vertex/match in the vector
int match(vector<char*> &vec, const char* label){
  for(int i = 0;i < vec.size();i++){
    if(strcmp(vec[i],label) == 0){
      return i;//if the vertex is in the graph then it will return its index
    }
  }
  return -1;//if the vertex is not in the graph then it will return -1, cause it got no index
}
//removing an edge
bool graph::deledge(const char* name1, const char* name2){
  //seeing if there are vertexs with the names that have been given
  int n1 = match(label,name1);
  int n2 = match(label,name2);
  if(n1 == -1 || n2 == -1 || (*matrix[n1])[n2] == -1){//checks to make sure there is vertex1, vertex2, and that there exists an edge between them
    return false;
  }
  //all conditions above are met so the matrix for the edge is reset
  (*matrix[n1])[n2] = -1;
  return true;
}
//printing out the path, using breadth first
pair<vector<char*>, int> graph::Path(const char* name1, const char* name2){
  /*
  pair<vector<char*>, int> x;
  //have to make sure the vertexs exist in the matrix
  int n1 = match(label,name1);
  int n2 = match(label,name2);
  if(n1 == -1 || n2 == -1){
    x.second = -1;
    return x;
  }
  //we will be using the const int num as the distance between points for now, we will also be looking at which nodes are gone over more than once
  int visit[label.size()];//setting visited array to size of all vertexs in graph
  vector< pair<vector<char*>, int> > vx;
  for(int i = 0;i < label.size();i++){
    visit[i] = true;//setting that vertex to true becuase we haven't visited them yet
    vx.push_back(pair<vector<char*>, int>());
    vx[vx.size()-1].second = num;//setting distance to the constant
  }
  visit[n1] = false;
  vx[n1].second = 0;
  vx[n1].first.push_back(Copy(label[n1]));
  int xxx = n1;//copying the starting positions location/index
  while(true){
    for(int i = 0; i < label.size();i++){
      if((*matrix[xxx])[i] != -1 && visit[i]){//checking to make sure an edge exists and that we havent visited it
	int dist = vx[xxx].second + (*matrix[xxx])[i];
	if(dist < vx[i].second){
	  vx[i].second = dist;
	  pathCopy(vx[i].first, vx[xxx].first);
	  vx[i].first.push_back(Copy(label[i]));
	}
      }
    }
  }
  visit[xxx] = false;
  if(visit[n2] == false){//if we have found the destination, we deallocate everything but what was returned
    for(int i = 0;i < label.size();i++){
      if(i != n2){//dont want to delete the destination node
	for(int a = 0;a < vx[i].first.size();a++){
	  delete[] (vx[i].first)[a];
	}
      }
    }
    return vx[n2];
  }
  bool path = true;//has a path been found, true = no path, false = Yeah a path
  for(int i = 0;i < label.size();i++){
    if(visit[i] && vx[i].second != num){
      path = false;//foung the path
      break;
    }
  }
  if(path){
    for(int i = 0;i < label.size();i++){
      for(int a = 0;a < vx[i].first.size();a++){
	delete[] (vx[i].first)[a];//deallocating everything like above
      }
    }
    return vx[n2];
  }
  int shortest = num;//shortest path distance
  for(int i = 0;i < label.size();i++){
    if(visit[i] && vx[i].second < shortest){
      shortest = vx[i].second;
      xxx = i;
    }
  }
  */
  //why above code wont work is beyond me, all credit to Artur for this
    pair<vector<char*>, int> result;
    int index1 = match(label, name2), index2 = match(label, name2);
    if(index1 == -1 || index2 == -1){
        result.second = -1;
        return result;
    }
    int unvisited[label.size()];
    vector< pair<vector<char*>, int> > nodes;
    for(int i = 0; i < label.size(); i++){
        unvisited[i] = true;
        nodes.push_back(pair<vector<char*>, int>());
        nodes[nodes.size()-1].second = num;
    }
    unvisited[index1] = false;
    nodes[index1].second = 0;
    nodes[index1].first.push_back(Copy(label[index1]));
    int current = index1;
    while(true){
        for(int i = 0; i < label.size(); i++){
            if((*matrix[current])[i] != -1 && unvisited[i]){
                int distance = nodes[current].second + (*matrix[current])[i];
                if(distance < nodes[i].second){
                    nodes[i].second = distance;
                    pathCopy(nodes[i].first, nodes[current].first);
                    nodes[i].first.push_back(Copy(label[i]));
                }
            }
        }
        unvisited[current] = false;
        if(unvisited[index2] == false){
            for(int i = 0; i < label.size(); i++){
                if(i != index2){
                    for(int j=0; j<nodes[i].first.size(); j++){
                        delete[] (nodes[i].first)[j];
                    }
                }
            }
            return nodes[index2];
        }
        bool noPath = true;
        for(int i = 0; i < label.size(); i++){
            if(unvisited[i] && nodes[i].second != num){
                noPath = false;
                break;
            }
        }
        if(noPath){
            for(int i = 0; i < label.size(); i++){
                for(int j=0; j<nodes[i].first.size(); j++){
                    delete[] (nodes[i].first)[j];
                }
            }
            return nodes[index2];
        }
        int smallest = num;
        for(int i = 0; i < label.size(); i++){
            if(unvisited[i] && nodes[i].second < smallest){
                smallest = nodes[i].second;
                current = i;
            }
        }
    }
}
//Copy function
char* Copy(char* str){
  return strcpy(new char[strlen(str)+1], str);
}
void pathCopy(vector<char*> &destination, vector<char*> &index){
  for(int i = 0;i < destination.size();i++){
    delete[] destination[i];
  }
  destination.clear();
  for(int a = 0;a < index.size();a++){
    destination.push_back(Copy(index[a]));
  }
}
//printing out the path details
void graph::printpath(const char* name1, const char* name2){
  /*
  pair<vector<char*>, int> fin = Path(name1,name2);
  if(fin.second == -1){//either one or two vertexs were missing from graph
    cout << "Could not find both vertices" << endl;
    return;
  }
  if(fin.second == num){//there is no possible path for the vertexs
    cout << "The two vertexs are not connected in any way" << endl;
    return;
  }
  cout << "Path: " << fin.first[0];
  delete[] fin.first[0];
  for(int i = 1;i < fin.first.size();i++){
    cout << "->" << fin.first[i];
    delete[] fin.first[i];
    cout << "Woah" << endl;
  }
  cout << " " << endl;
  cout << "Distance Travelled: " << fin.second << endl;
  */
  pair<vector<char*>, int> result = Path(name1, name2);
  cout << num << endl;
  if(result.second == -1){
     cout << "Could not find both vertices." << endl;
     return;
  }
  if(result.second == num){
     cout << "No path exists between the vertices." << endl;
     return;
  }
  cout << "Path: " << result.first[0];
  delete[] result.first[0];
  for(int i = 1; i < result.first.size(); i++){
     cout << "->" << result.first[i];
     delete[] result.first[i];
  }
  cout << " " << endl;
  cout << "Distance travelled: " << result.second << '.' << endl;
}
//printing out the adjecency table
void graph::print(){
  int maxlength = 0;//the max length of the adjenceny table
  for(int i = 0;i < label.size();i++){
    int n = strlen(label[i]);
    if(n > maxlength){
      maxlength = n;
    }
  }
  //Printing out the top row
  for(int i = 0;i < maxlength + 1;i++){
    cout << ' ';
  }
  for(int a = 0;a < label.size();a++){
    cout << label[a] << ' ';
  }
  cout << endl;
  //printing the columns and rows and the rest of the adjcency table
  for(int i = 0;i < matrix.size();i++){
    cout << label[i];
    for(int a = 0;a < maxlength - strlen(label[i])+1;a++){
      cout << ' ';
    }
    for(int b = 0;b < label.size();b++){
      if((*matrix[i])[b] >= 0){
	cout << (*matrix[i])[b];
      }
      else{
	cout << 'x';//nothing there
      }
      for(int a = 0;a < strlen(label[b]);a++){
	cout << ' ';
      }
    }
    cout << endl;
  }
}
