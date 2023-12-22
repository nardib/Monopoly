//made by: Lorenzo Nardin 2066609

#ifndef CELL_H
#define CELL_H

#include "Player.h"
#include <stdexcept>

//these are the cell types available on the board
enum class CellType
{
  Start = 0, Void , Economic, Standard, Luxury
};

//enum for hotel and house in a cell
enum class Building
{
	None = 0, House, Hotel
};

class Cell
{
public:

	//default constructor
	Cell () : type {CellType::Void}, b {Building::None}, p1 {false}, p2 {false}, p3 {false}, p4 {false}, property_check {0} {}
	Cell (CellType c);
    
    //set the new owner; the argument request a number between 1 and 4 to set the property to another player
    void buy_property(int player);
    
    //returns the owner, zero if not owned
    int return_owner() {return property_check;}
    CellType return_type() {return type;}
    bool is_p1_here() {return p1;}
    bool is_p2_here() {return p2;}
    bool is_p3_here() {return p3;}
    bool is_p4_here() {return p4;}
    Building what_building() {return b;}

    //upgrade the building
    void upgrade_building();
  
private:
  //cell type
  CellType type;
  //can i buy the property, if zero it's not already bought
  int property_check;
  //member variables that memorize the presence of a maximum of 4 player (probably i'm going to delete them)
  bool p1, p2, p3, p4;
  //member variable that tells if there's an house or an hotel
  Building b;
};


#endif