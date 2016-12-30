/*This is the header containing implementation of
each provided PVE_ENV and PVP_ENV used as template in Map.
Please implement those provided class according to the requierment and
the codes in Maps.tpp and heros.h to ensure the program should be compiled.
You cannot modify any provided codes.
When grading, we will provide more PVE_ENV and PVP_ENV implementation*/

#ifndef ENV_H
#define ENV_H
#include "Heroes.h"
#include <vector>
using namespace std;

class Fire_PVP_ENV
{
public:
    void operator()(Hero*& hero) const
    {
	    //TODO::implement this function to 
		//let the hero's hp decrease by 1 and atk improve 2
		//and the hero will obtain 16 experiance.
		//If the hero can evolve, please let him evolve.
    	hero->update_hp(-1);
    	hero->update_atk(2);
    	if(hero->gain_exp(16))
    	{
    		Hero* oldHero=hero;
			hero=hero->evolve();
			if(hero != oldHero)
				delete oldHero;
    	}
    }
};

class Complex_PVP_ENV
{
public:
    vector<int> exp_vec, dspd_vec, ddef_vec;
    Complex_PVP_ENV()
    {
        dspd_vec.resize(100);
        exp_vec.resize(100);
        ddef_vec.resize(100);
        for (int i = 0; i < 100; i++)
        {
            if (i % 2)
            {
                dspd_vec[i] = 1;
                exp_vec[i] = 10;
            }
            else
            {
                if (i != 52)
                    ddef_vec[i] = 1;
                exp_vec[i] = 20;
            }
        }
    }
    // TODO:: defined and implement operator overloading ().
    // In this function, hero's spd and def will change according to
    // his location, the changing of location i is stored in dspd_vec[i]
    // and ddef_vec[i]. After that, the hero will obtain exp in his location with
    // value exp_vec[i]. If the hero can evolve, evolve him.
    void operator()(Hero*& hero) const
    {
    	int location=hero->get_location();
    	hero->update_spd(dspd_vec[location]);
    	hero->update_def(ddef_vec[location]);
    	if(hero->gain_exp(exp_vec[location]))
    	{
    		Hero* oldHero=hero;
			hero=hero->evolve();
			if(hero != oldHero)
				delete oldHero;
    	}
    }
};

class Simple_PVE_ENV
{
public:
    // TODO:: implement member function update to improve the hero's ability:
    // if hero's location < 50, hero's hp plus 1, else hero's mp plus 1
    // hero will get 50 exp, if  hero's remaining exp is 0, he will evolve.
	void update(Hero*& hero) const
	{
		if(hero->get_location()<50)
			hero->update_hp(1);
		else
			hero->update_mp(1);
		if(hero->gain_exp(50))
		{
			Hero* oldHero=hero;
			hero=hero->evolve();
			if(hero != oldHero)
				delete oldHero;
		}
	}
};

class General_PVE_ENV
{
public:
    // TODO:: implement member function update and constructor. In member function update,
    // hero will improve the corresponding ability stored in the class
    General_PVE_ENV(int dhp_, int dmp_, int datk_, int ddef_, int dspd_, int dexp_): dhp(dhp_),dmp(dmp_),datk(datk_),
    ddef(ddef_), dspd(dspd_), dexp(dexp_) {}
    void update(Hero*& hero) const
    {
    	hero->update_hp(dhp);
    	hero->update_mp(dmp);
    	hero->update_atk(datk);
    	hero->update_def(ddef);
    	hero->update_spd(dspd);
    	if(hero->gain_exp(dexp))
    	{
    		Hero* oldHero=hero;
			hero=hero->evolve();
			if(hero != oldHero)
				delete oldHero;
    	}
    }
private:
    // TODO:: define variables to store the changing of each ability of hero,
    // those ability will be initialized by constructor.
	int dhp;
	int dmp;
	int datk;
	int ddef;
	int dspd;
	int dexp;
};

#endif // ENV_IF
