//Graph Creator, C++ Colin Aslett, Period 07
#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int main(){
  graph graph;
  cout << "Welcome to Graph Creator" << endl;
  char input[32];
  while(true){
    cout << "Several Options: 1 = Add vertex, 2 = Add edge, 3 = Remove Vertex, 4 = remove Edge, 5 = add double edge, 6 = find path, 7 = print, q = quit" << endl;
    cin.getline(input,32);//getting the input
    input[0] = tolower(input[0]);//putting it to lowercase so there are no discrepencies between Q and q
    //Adding vertex
    if(input[0] == '1'){
      char name[32];
      cout << "enter a label for a vertex: " << endl;
      cin.getline(name,32);
      if(graph.vertex(name)){//only adding if the vertex is not in there
	cout << "vertex added" << endl;
      }
      else{ 
	cout << "vertex already in graph with the same label" << endl;
      }
    }
    //Adding Edge
    else if(input[0] == '2'){
      char name1[32];
      char name2[32];
      int x;//weight of the edge
      cout << "Enter name for first label" << endl;
      cin.getline(name1,32);
      cout << "Enter name for second label" << endl;
      cin.getline(name2,32);
      cout << "Enter the weight of the edge" << endl;
      cin >> x;
      if(graph.edge(name1,name2,x)){
	cout << "edge added" << endl;
      }
      else{
	cout << "One or more the vertexs could not be found" << endl;
      }
    }
    //Remove Vertex
    else if(input[0] == '3'){
      char name[32];//vertex you wanted to delete
      cout << "Enter the vertex you want to be deleted" << endl;
      cin.getline(name,32);
      if(graph.delvertex(name)){
	cout << "Vertex deleted" << endl;
      }
      else{
	cout << "Could not find vertex" << endl;
      }
    }
    //Remove Edge
    else if(input[0] == '4'){
      char name1[32];
      char name2[32];
      cout << "Enter name for first vertex" << endl;
      cin.getline(name1,32);
      cout << "Enter name for second vertex" << endl;
      cin.getline(name2,32);
      if(graph.deledge(name1,name2)){
	cout << "edge deleted" << endl;
      }
      else{
	cout << "Edge or vertices could not be found" << endl;
      }
    }
    //Add double Edge
    else if(input[0] == '5'){
      char name1[32];
      char name2[32];
      int x;
      cout << "Enter name for first vertex: " << endl;
      cin.getline(name1,32);
      cout << "Enter name for second vertex: " << endl;
      cin.getline(name2,32);
      cout << "Enter weight for edge" << endl;
      cin >> x;
      if(graph.dbedge(name1,name2,x)){
	cout << "Double edge added" << endl;
      }
      else{
	cout << "one or more vertexs coudl not be found" << endl;
      }
    }
    //Find Path
    else if(input[0] == '6'){
      char name1[32];
      char name2[32];
      cout << "Enter label for starting vertex: " << endl;
      cin.getline(name1,32);
      cout << "Enter label for destination vertex: " << endl;
      cin.getline(name2,32);
      graph.printpath(name1,name2);//printing out the shortest path
    }
    //Printing the Adjcancy Matrix
    else if(input[0] == '7'){
      graph.print();
    }
    //Quitting program
    else if(input[0] == 'q'){
      break;
    }
    cout << "Press enter to continue, probably have to press it twice";
    cout << endl;
    cin.ignore();
    cin.get();
  }
  return 0;
}
