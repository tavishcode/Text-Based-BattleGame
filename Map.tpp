/*This is the header to define template class Map.
Please add codes after TODO.
You cannot modify the any provided codes or add any new member variables
or modify the accessors of provided member variables and function
or add any new friend class.*/

#ifndef MAPS_H
#define MAPS_H
#include "Heroes.h"
#include <vector>
#include <iostream>
using namespace std;

template <class PVP_ENV>
class Map
{
public:
    template <class PVE_ENV>
    void exercise(const PVE_ENV& pve_env)
    {
        pve_env.update(red);
        pve_env.update(blue);
        red->print();
        blue->print();
    }
    void PK(int total_round)
    {
        for (int i = 0; i < total_round; i++)
        {
            cout << "Round " << i << ": " << endl;
            red->action(blue);
            blue->action(red);

            // TODO:: add codes to let pvp_env influence red and blue
			pvp_env(red);
			pvp_env(blue);
			
            red->print();
            blue->print();
            if (red->is_dead() && blue->is_dead())
            {
                cout << "Tie!" << endl;
                return;
            }
            else if (red->is_dead())
            {
                cout << "Blue wins!" << endl;
                return;
            }
            else if (blue->is_dead())
            {
                cout << "red wins!" << endl;
                return;
            }
            cout << endl;
        }
        cout << "Tie!" << endl;
    }
    Map(const PVP_ENV& pvp_env_)
        : pvp_env(pvp_env_)
        , red(new Hero(0, 1))
        , blue(new Hero(99, -1))
    {
    }
    ~Map()
    {
        delete red;
        delete blue;
    }

private:
    Hero* red;
    Hero* blue;
    const PVP_ENV& pvp_env;
};

#endif // MAPS_H