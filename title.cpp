//Graph Creator, C++ Colin Aslett, Period 07
#include <iostream>
#include <vector>

using namespace std;
void vertex(vector<char*> &ver);//adding vertex to the graph, if it can
void print(vector<char*> ver);
int main(){
  cout << "Welcome to Graph Creator" << endl;
  vector<char*> labels;
  while(true){
    char input;
    cout << "Several Options: 1 = Add vertex, 2 = Add edge, 3 = Remove Vertex, 4 = remove Edge, 5 = add double edge, 6 = find path, 7 = print, q = quit" << endl;
    cin >> input;
    //Adding vertex
    if(input == '1'){
      vertex(labels);
    }
    //Adding Edge
    else if(input == '2'){

    }
    //Remove Vertex
    else if(input == '3'){
      
    }
    //Remove Edge
    else if(input == '4'){
      
    }
    //Add double Edge
    else if(input == '5'){
      
    }
    //Find Path
    else if(input == '6'){
      
    }
    //Printing the Adjcancy Matrix
    else if(input == '7'){
      print(labels);
    }
    //Quitting program
    else if(input == 'q'){
      break;
    }
  }
  return 0;
}
//adding vertex to graph if not already used
void vertex(vector<char*> &ver){
  char label[16];
  cout << "Enter name for vertex: " << endl;
  cin >> label;
  //check to make sure it is already not in the graph, through iteration
  //adding it to the vector
  ver.push_back(label);
}
//printing out the Adjcancy Matrix
void print(vector<char*> ver){
  int size = ver.size();
  cout << "Size of Vertex: " << size << endl;
  for(int i = 0;i < size;i++){//Maybe do an iterator instead, ver.begin() until ver.end()
    cout << ver[i] << " , " << endl;
  }
  if(size == 0){
    cout << "There are no items in the Graph!" << endl;
  }
}
