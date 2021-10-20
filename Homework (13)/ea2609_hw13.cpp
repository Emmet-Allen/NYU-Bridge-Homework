#include <iostream>
#include <string>
#include <vector> 


// If grid is smart: Use organism pointers, NEED
// if we are pointing to a organism then have something to delete it once its dead. 
// This thing should either be a 'starve()' where after 6 steps it delete
// Or a 'Eat()' where after its eaten it calls delete  

using namespace std;

const int WORLD_DIMENSION = 8;
const char ANT ='o';
const char DOODLEBUG = 'X';
const int INITAL_ANTS = 1;
const int INITAL_DOODLEBUGS = 1;


class Organism{
    protected:
    char type; 
    int breedStep = -1;
    int starveStep = 0;
    bool moved = false; 

    public:

public:
	// Only applies if node is '-' (unoccupied)
	// Organism will spawn in a random unoccupied node in the world
	virtual void getSpawn() {}
	
	// Organism will Breed depending on the time step
	// Would be useful to include a 'timestep' or 'spawn' counter 
	virtual int getBreedStep() {};
	
    char getType() const {return type;}
	
	// Chose between one space in the grid, either in the x direction or y direction
	// The space cannot be occupied, if its occupied check for another empty node
	// If the space is off the grid, check for another empty node
	// Else If there are no empty nodes, stay in place 
	virtual void Move() {}

	virtual void setSpawn() {};
	virtual int resetBreed(int resetNum) {};
    virtual void setBreedStep() {};

};

class Ant : public Organism{
public:
    Ant(){type='o';}

    int resetBreedStep (int resetNum){
        breedStep = resetNum;
        return breedStep; 
    }

    void setBreedStep(){
       breedStep++;  
    }

    int getBreedStep () {
        return breedStep; 
    }

    bool hasMoved () const{
        return true; 
    }

    char getType() const{
        return ANT;
    }



};

class DoodleBug : public Organism{
public:
    DoodleBug(){type = 'X';}

    char getType() const {
        return DOODLEBUG;
    }

};

// DoodleBug::DoodleBug(/* args */)
// {
//         type='X';
// }



class World{
    private:
 
    vector<vector<Organism*>> Grid;

    public:
    World (){
        // NO MORE POINTERS, You either reassign or 
        Grid.resize(WORLD_DIMENSION, vector<Organism*>(WORLD_DIMENSION, nullptr) );
        
    }

       void printWorld(){
        for(int x = 0; x < WORLD_DIMENSION; x++){
            for(int y = 0; y < WORLD_DIMENSION; y++){
                if(Grid[x][y] == nullptr){
                    cout << '-';
                }
                else{
                    if(Grid[x][y]->getType() == 'o'){
                        cout << 'o';
                    }
                    else if(Grid[x][y]->getType() == 'X'){
                        cout << 'X';
                    }
                }
            }
            cout << endl;
        }
    }
        //Randomized, 
        //Take an integer, and a char type
        // integer is how many things you want to spawn
        // char is the type of the thing

        //If it randomly crashes you probably missed checking for a nullptr
        // WILL DEF FUCK ME IN THE MOVE AND BREED
        // DONT GO OUT OF BOUNDS
//[x+1][y], [x][y+1], [x-1][y], [x][y-1] Cardinal Points
    void intialSpawn(int n, char type){
        while(n){
            int x = rand() % WORLD_DIMENSION; 
            int y = rand() % WORLD_DIMENSION;
            if(Grid[x][y] == nullptr){
                n -= 1;
                if(type == 'o'){
                    Grid[x][y] = new Ant;
                }
                else if(type == 'X'){
                    Grid[x][y] = new DoodleBug; 
                }
            }
        }
    }


// for moveBug
// Check if ant is near by
// if ant is near by, eat ant and move to ant position, and Grid[x][y]->ResetStarve() == 0
// if it cant do that, then move how ants move, and Grid[x][y]->setStarve( do like starveCount += 1 within doodlebug function).

    void MoveAnt(){
        for(int x = 0; x < WORLD_DIMENSION; x++){
            for(int y = 0; y < WORLD_DIMENSION; y++){
                //check if cord is nullptr first if not
                if(Grid[x][y] == nullptr ){
                    continue;
                }
                // then do getType()
                else if(Grid[x][y]->getType() == ANT){
                int randMove = rand()%4;
                switch (randMove)
                {
                case 0:
                if( (x + 1 != WORLD_DIMENSION) && Grid[x + 1][y] == nullptr){
                    Grid[x + 1][y] = Grid[x][y];
                    Grid[x + 1][y]->setBreedStep(); 
                    Grid[x][y] =  nullptr;
                }
                break;
                case 1:
                if( (x - 1 >= 0) && Grid[x - 1][y] == nullptr){
                    Grid[x - 1][y] = Grid[x][y];
                    Grid[x - 1][y]->setBreedStep(); 
                    Grid[x][y] =  nullptr;
                }
                break;
                case 2:
                if( (y + 1 != WORLD_DIMENSION) && Grid[x][y + 1] == nullptr){
                    Grid[x][y + 1] = Grid[x][y];
                    Grid[x][y + 1]->setBreedStep(); 
                    Grid[x][y] =  nullptr;
                    
                }
                break;
                case 3:
                if( (y - 1 >= 0) && Grid[x][y - 1] == nullptr){
                    Grid[x][y - 1] = Grid[x][y];
                    Grid[x][y - 1]->setBreedStep(); 
                    Grid[x][y] =  nullptr;
                }
                break;
                default:
                    break;
                }
            }
        }
    }
}

//Basically use the same AntMove functionallity, but have it check each cardinal position for each switch case.
//Meh... I need to find a way to loop this multiple times for each iteration... 

    void AntBreed(){
        for(int x = 0; x < WORLD_DIMENSION; x++){
            for(int y = 0; y < WORLD_DIMENSION; y++){
                //check if cord is nullptr first if not
                if(Grid[x][y] == nullptr){
                    continue;
                }
                else if(Grid[x][y]->getType() == ANT && Grid[x][y]->getBreedStep() == 3){
                int randMove = rand()%4;
                switch (randMove)
                {
                case 0:
                if( (x + 1 != WORLD_DIMENSION) && Grid[x + 1][y] == nullptr){
                    Grid[x + 1][y] = new Ant;
                    Grid[x][y]->resetBreed(0);
                }
                break;
                case 1:
                if( (x - 1 >= 0) && Grid[x - 1][y] == nullptr){
                    Grid[x - 1][y] = new Ant;
                    Grid[x][y]->resetBreed(0);
                }
                break;
                case 2:
                if( (y + 1 != WORLD_DIMENSION) && Grid[x][y + 1] == nullptr){
                    Grid[x][y + 1] = new Ant;
                    Grid[x][y]->resetBreed(0); 
                }
                break;
                case 3:
                if( (y - 1 >= 0) && Grid[x][y - 1] == nullptr){
                    Grid[x][y - 1] = new Ant;
                    Grid[x][y]->resetBreed(0);
                }
                break;
                default:
                    break;
                }
            }
        }
    }
}

    void MoveDoodleBug(){
        for(int x = 0; x < WORLD_DIMENSION; x++){
            for(int y = 0; y < WORLD_DIMENSION; y++){
                //check if cord is nullptr first if not
                if(Grid[x][y] == nullptr){
                    continue;
                }
                // then do getType()
                else if(Grid[x][y]->getType() == DOODLEBUG){
                int randMove = rand()%4;
                switch (randMove)
                {
                case 0:
                if( (x + 1 != WORLD_DIMENSION) && Grid[x + 1][y] == nullptr){
                    Grid[x + 1][y] = Grid[x][y];
                    Grid[x][y] =  nullptr;
                }
                break;
                case 1:
                if( (x - 1 >= 0) && Grid[x - 1][y] == nullptr){
                    Grid[x - 1][y] = Grid[x][y];
                    Grid[x][y] =  nullptr;
                }
                break;
                case 2:
                if( (y + 1 != WORLD_DIMENSION) && Grid[x][y + 1] == nullptr){
                    Grid[x][y + 1] = Grid[x][y];
                    Grid[x][y] =  nullptr;
                    
                }
                break;
                case 3:
                if( (y - 1 >= 0) && Grid[x][y - 1] == nullptr){
                    Grid[x][y - 1] = Grid[x][y];
                    Grid[x][y] =  nullptr;
                }
                break;
                default:
                    break;
                }
            }
        }
    }
}

//Destructor that turns all cords in the Grid into a nullptr. 
    ~World(){
        //auto specifies the type automatically for anything
        // Use a range for loop between r and Grid
        // Use a nested range for loop for c and r to get all points in the grid
        for(auto& r:Grid ){
            for(auto& c:r){
                if(c != nullptr){
                    delete c;
                    c = nullptr;
                }
            }
        }
    }
};

int main(){
    World Hank;
    Hank.intialSpawn(INITAL_DOODLEBUGS, 'X');
    Hank.intialSpawn(INITAL_ANTS, 'o');
    Hank.printWorld();

    int timeStep = 0; 


    while (cin.get() == '\n') {
        Hank.MoveDoodleBug();
        Hank.MoveAnt();
        Hank.AntBreed();
        Hank.printWorld();
        cout << "The current time step is " << timeStep++ << endl; 
    }

    return 0;
}