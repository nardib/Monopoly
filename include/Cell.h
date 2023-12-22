//made by: Lorenzo Nardin 2066609

#ifndef CELL_H
#define CELL_H

#include <stdexcept>
#include <iostream>

//these are the cell types available on the board
enum class CellType
{
  Start = 0, Void , Economic, Standard, Luxury
};

//overload operator<< for enum CellType
std::ostream& operator<< (std::ostream& out, CellType c);

//enum for hotel and house in a cell
enum class Building
{
	None = 0, House, Hotel
};

//overload operator<< for enum Building
std::ostream& operator<< (std::ostream& out, Building b);

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
    Building what_building() {return b;}

    //upgrade the building, if building is an Hotel it does nothing
    void upgrade_building();

    //member variables that memorize the presence of a maximum of 4 player
    //p1 is first player, etc.
    //public to avoid the creation of two functions that wouldn't have check on them
    bool p1, p2, p3, p4;

    //returns if player n is in this cell
    bool is_pn_here(int n);
    //aggiungo dei const values per le fee e per il prezzo dei terreni
  
private:
  //cell type
  CellType type;
  //can i buy the property, if zero it's not already bought
  int property_check;
  //member variable that tells if there's an house or an hotel
  Building b;
};

//overload operator<<
std::ostream& operator<< (std::ostream& out, Cell cell);

#endif