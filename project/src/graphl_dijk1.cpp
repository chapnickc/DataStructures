#include "GraphL.h"
#include "heap.h"

#include <chrono>
#include <cmath>
#include <ctime>
#include <stdlib.h>  
#include <string>
#include <thread>


using namespace std;





// Test Dijkstra's algorithm:
// Version for Adjancency List representation
int main(){
  srand(2100);

  int N = 9;
  Graph* graphs[N];

  std::clock_t start;
  double duration;

  for (int i=0; i < N; i++){
    start = std::clock();
    cout << "Building graph " << i;
    graphs[i] = handshake_graph<GraphL>(pow(2, i+1));
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"\t\tElapsed Time: "<< duration <<'\n';
  }

  test_graph_array(graphs);

  return 0;
}


