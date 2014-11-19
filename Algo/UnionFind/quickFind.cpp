// Simple implementation of Union-Find
// In this algorithm, find is quick but initialization and Union are O(N)

#include<iostream>

class UF {
    int *graph;
    int size;
    public:
    // Constructor
    UF(int N) {
        graph = (int*) malloc(sizeof(int)*N);
        size = N;
        // Initializing the connected components
        // Initially all are disconnected
        for(int i=0; i<N; i++){
            graph[i] = i;    
        }    
    }

    bool Find(int x, int y) {
        bool result =  (graph[x]==graph[y]);   
        std::cout << std::endl << "Find(" << x << "," << y << "): " << (result?"True":"False") ;
        return result;
    }

    void Union(int x, int y) {
        int y_val = graph[y];
        int x_val = graph[x];

        for(int i=0; i<size; i++){
            if(graph[i] == x_val){
                graph[i] = y_val;    
            }    
        }
    }
};


// Driver function
int main () {

    UF u(10);
    
    u.Union(5,0);    
    u.Union(1,0);    
    u.Union(1,6);    
    u.Union(2,7);    
    u.Union(3,8);    
    u.Union(8,9);    
    u.Union(4,9);    

    u.Find(5,0);    
    u.Find(1,0);    
    u.Find(1,6);    
    u.Find(2,7);    
    u.Find(3,8);    
    u.Find(8,9);    
    u.Find(4,9);    
    
    u.Find(1,2);
    u.Find(6,7);
    u.Find(2,9);

    std::cout<< std::endl;
}

