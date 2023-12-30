//made by: Lorenzo Nardin 2066609

#include "Cell.h"

//constructor with the CellType as argument
Cell::Cell (CellType c) : type {c}, property_check {0}, p1 {false}, p2 {false}, p3 {false}, p4 {false}, b {Building::None}
{
	if(c == CellType::Start)
	{
		p1 = true;
		p2 = true;
		p3 = true;
		p4 = true;
	}

}

//set the new owner
void Cell::buy_property(int p)
{
	if(property_check == 0 && !(p < 1 || p > 4))
		property_check = p;
	else
		throw std::invalid_argument("The player must be valid or the property is already bought");
}

//function to sell this cell if the player that bought this is no more playing
void Cell::sell_property()
{
	if(property_check == 0)
		throw Cell::PropertyNotBought("This property is not bought, so it can't be sold by a player");
	property_check = 0;
}

//return terrain price for this cell
int Cell::terrain_price() const
{
	switch (type)
	{
	case CellType::Economic:
		return ECONOMIC_TERRAIN_PRICE;
		break;
	case CellType::Standard:
		return STANDARD_TERRAIN_PRICE;
		break;
	case CellType::Luxury:
		return LUXURY_TERRAIN_PRICE;
		break;
	default:
		return 0;
		break;
	}
	return 0;
}

//return house price for this cell
int Cell::house_price() const
{
	switch (type)
	{
	case CellType::Economic:
		return ECONOMIC_HOUSE_PRICE;
		break;
	case CellType::Standard:
		return STANDARD_HOUSE_PRICE;
		break;
	case CellType::Luxury:
		return LUXURY_HOUSE_PRICE;
		break;
	default:
		return 0;
		break;
	}
}

//return hotel price for this cell
int Cell::hotel_price() const
{
	switch (type)
	{
	case CellType::Economic:
		return ECONOMIC_HOTEL_PRICE;
		break;
	case CellType::Standard:
		return STANDARD_HOTEL_PRICE;
		break;
	case CellType::Luxury:
		return LUXURY_HOTEL_PRICE;
		break;
	default:
		return 0;
		break;
	}
}

//return accomodation price for this cell in an house
int Cell::accomodation_house_price() const
{
	switch (type)
	{
	case CellType::Economic:
		return ECONOMIC_ACCOMODATION_HOUSE_PRICE;
		break;
	case CellType::Standard:
		return STANDARD_ACCOMODATION_HOUSE_PRICE;
		break;
	case CellType::Luxury:
		return LUXURY_ACCOMODATION_HOUSE_PRICE;
		break;
	default:
		return 0;
		break;
	}
}

//return accomodation price for this cell in an hotel
int Cell::accomodation_hotel_price() const
{
	switch (type)
	{
	case CellType::Economic:
		return ECONOMIC_ACCOMODATION_HOTEL_PRICE;
		break;
	case CellType::Standard:
		return STANDARD_ACCOMODATION_HOTEL_PRICE;
		break;
	case CellType::Luxury:
		return LUXURY_ACCOMODATION_HOTEL_PRICE;
		break;
	default:
		return 0;
		break;
	}
}

//upgrade the building in that cell
void Cell::upgrade_building()
{	
	//if property is not owned I can't upgrade it
	if(property_check != 0)
	{
		if(b == Building::None)
			b = Building::House;
		else if(b == Building::House)
			b = Building::Hotel;
	}
}

bool Cell::is_pn_here(int n) const
{
	switch (n)
	{
	case 1:
		return p1;
		break;
	case 2:
		return p2;
		break;
	case 3:
		return p3;
		break;
	case 4:
		return p4;
		break;
	default:
		throw std::invalid_argument("Number of player not valid");
		break;
	}
	return false;
}

//overload operator<< for enum CellType
std::ostream& operator<< (std::ostream& out, CellType c)
{
	switch (c)
	{
		case CellType::Start:
			return out << 'P';
			break;
		case CellType::Void:
			return out << ' ';
			break;
		case CellType::Economic:
			return out << 'E';
			break;
		case CellType::Standard:
			return out << 'S';
			break;
		case CellType::Luxury:
			return out << 'L';
			break;
		default:
			throw std::invalid_argument("invalid CellType");
			break;
	}
	return out;
}

//overload operator<< for enum Building
std::ostream& operator<< (std::ostream& out, Building b)
{
	switch (b)
	{
		case Building::None:
			return out << ' ';
			break;
		case Building::House:
			return out << '*';
		case Building::Hotel:
			return out << '^';
			break;
		default:
			throw std::invalid_argument("invalid Building");
			break;
	}
	return out;
}

//overload operator<< for class Cell
std::ostream& operator<< (std::ostream& out, Cell cell)
{
	std::cout << "| ";
	std::cout << cell.return_type() << cell.what_building();
	if(cell.p1)
		std::cout << '1';
	else
		std::cout << ' ';
	if(cell.p2)
		std::cout << '2';
	else
		std::cout << ' ';
	if(cell.p3)
		std::cout << '3';
	else
		std::cout << ' ';
	if(cell.p4)
		std::cout << '4';
	else
		std::cout << ' ';
	return out << " |";
}