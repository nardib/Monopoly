//made by: Lorenzo Nardin 2066609

#include "Cell.h"

//constructor with the CellType as argument
Cell::Cell (CellType c) : type {c}, property_check {0}, p1 {false}, p2 {false}, p3 {false}, p4 {false}, b {Building::None}
{
	if(c == CellType::Start)
	{
		p1 == true;
		p2 == true;
		p3 == true;
		p4 == true;
	}

}

//set the new owner
void Cell::buy_property(int p)
{
	if(property_check == 0 && !(p < 1 || p > 4))
		property_check = p;
	throw std::invalid_argument("The player must be valid or the property is already bought");
}

