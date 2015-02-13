/*Given a maze where some of the cells are blocked, where left top cell is the entry point and right bottom cell is the exit point, find all possible paths from entry to exit which goes through the non blocked cells.*/
#include<iostream>
#include<list>
#include<random>
#include<vector>

#define MAX 4
#define SPARSITY 3

using namespace std;

class Cell {
    public:
    int row;
    int col;
    Cell(int x, int y):row(x), col(y) {}    
};


/* Checks if the cell is in the bounds of the maze and the cell is available to be occupied */
inline bool isValid (Cell c, bool maze[MAX][MAX]) {
    return (c.row >= 0 && c.row < MAX && c.col >=0 && c.col < MAX && !maze[c.row][c.col]);    
}


/* Checks if two cells are the same */
inline bool isEqual (Cell a, Cell b) {
    return (a.row == b.row && a.col == b.col); 
}

/* Return a vector of adjacent cells */
vector<Cell> getAdjacentCells(Cell s) {
    
    vector<Cell> result;
    Cell a(s.row + 1, s.col);
    Cell b(s.row, s.col + 1);
    Cell c(s.row - 1, s.col);
    Cell d(s.row, s.col - 1);

    result.push_back(a);
    result.push_back(b);
    result.push_back(c);
    result.push_back(d);

    return result;
}


/* Print a given path */
void printPath (list<Cell> path) {

    list<Cell>::iterator it;
    cout << endl;
    for(it = path.begin(); it!=path.end(); ++it) {
        cout << "-->(" << it->row << ", " << it->col << ")";
    }
}

/* Prints all paths */
void printAllPaths (list<list<Cell> > paths) {
    
    list<list<Cell> >::iterator path;
    for(path = paths.begin(); path!=paths.end(); ++path) {
        printPath(*path);    
    }    
}


list<list<Cell> > findPaths(bool maze[MAX][MAX], Cell start, Cell end) {
    
    list<list<Cell> > result; 
    
    /* Check if we're in a valid cell */
    if (!isValid(start, maze)) {
        /* We just return a blank result */
        return result;
    }

    /* Check if we've reached the destination
     * If we have reached, add path to result 
     */
    if(isEqual(start, end)) {
        list<Cell> path;
        path.push_front(start);
        result.push_front(path);
        return result;
    }

    /* Mark current cell as visited before exploring further paths */
    maze[start.row][start.col] = 1;

    /* Get adjacent cells and explore paths from them */
    vector<Cell> adjacent = getAdjacentCells(start); 
    for(int i = 0; i < adjacent.size(); i++) {
        list<list<Cell> > paths = findPaths(maze, adjacent[i], end);
        list<list<Cell> >::iterator it;
        for(it = paths.begin(); it!=paths.end(); ++it) {
            list<Cell> path = *it;
            path.push_front(start);
            result.push_back(path);
        }
    }

    /* Mark the current cell back to unvisited */
    maze[start.row][start.col] = 0;
     
    return result;
} 

/* Make a random maze */
void makeRand(bool maze[MAX][MAX]) {
   default_random_engine generator;
   uniform_int_distribution<int> distribution(1,10);
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
           if(distribution(generator) < SPARSITY) {  // generates number in the range 1..6 
                maze[i][j] = true;     
           }
           else{
               maze[i][j] = false;
           }
        } 
    }
}

void printMaze(bool maze[MAX][MAX]) {
    for(int i=0; i<MAX; i++) {
        cout << endl;
        for(int j=0; j<MAX; j++) {
            cout << "\t" << maze[i][j]; 
        }    
    }
    cout << endl;
}

int main() {
    
    bool maze[MAX][MAX];
    //bool maze[MAX][MAX] = {{0,1,0,0},{0,0,0,0},{1,1,1,0},{0,0,0,0}};

    /* Create a random maze */
    makeRand(maze);
    maze[0][0] = maze[MAX-1][MAX-1] = 0;    

    printMaze(maze);
    
    Cell start(0,0);
    Cell end(MAX-1, MAX-1);
    list<list<Cell> >paths = findPaths(maze, start, end);
    printAllPaths(paths);
    cout << endl;

}
