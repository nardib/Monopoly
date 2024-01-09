//made by : Manuel Andretto 2074979

#include "ComputerPlayer.h"

/*
int random(int min, int max)
{
	//seed the random number generator
	std::random_device rd;
	std::mt19937 gen(rd());

	//create a distribution for this range
	std::uniform_int_distribution<> distribution(min, max);

	//return a random number between min and max
	return distribution(gen);
}*/

bool ComputerPlayer::buy_intent() {
        // Implement the logic for buying the property, this function will return true with a probability of 25%
        int rnd = random(1, 4);
		if(rnd == 1){
                p_property.push_back(pos());
                std::sort(p_property.begin(), p_property.end());
                return true;
            }else{
                return false;
            }
}

 bool ComputerPlayer::upgrade_intent() {
        // Implement the logic for upgrading the building, this function will return true with a probability of 25%
        int rnd = random(1, 4);
        
        return (rnd == 1);
 }

