//made by: Lorenzo Nardin 206609

//these are the cell types available on the board
enum CellType
{
  Start = 0, Void , Economic, Standard, Luxury
};

class Cell
{
public:
    
    //set the new owner
    void buy_property();
    
    //returns the owner, zero if not owned
    int return_owner() {return property_check;}
  
private:
  //cell type
  CellType type;
  //can i buy the property, if zero it's not already bought
  int property_check = 0;
  
  //dovro' fare delle variabili per capire quali giocatori sono presenti nella cella quando andro' a stampare
};
