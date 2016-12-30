/*This is the main function for testing by yourself
You cannot modify any codes in the main function.
Please complete all the requirement in other files
to ensure the codes should be compiled and run right results.*/

#include "Map.tpp"
#include "Heroes.h"
#include "Env.h"
#include <iostream>
using namespace std;

int main()
{
    General_PVE_ENV pve(1, 1, 1, 1, 1, 40);
    Complex_PVP_ENV pvp;
    Fire_PVP_ENV fire_env;
    Simple_PVE_ENV simple_env;
    Map<Fire_PVP_ENV> map1(fire_env);
	cout<<"Fight in map 1"<<endl;
	cout<<"Exercise in Simple_PVE_ENV"<<endl;
    map1.exercise(simple_env);
	cout<<"Exercise in General_PVE_ENV"<<endl;
    map1.exercise(pve);
	cout<<"Exercise in General_PVE_ENV"<<endl;
    map1.exercise(pve);
	cout<<"Begin to fight"<<endl;
    map1.PK(10);
    cout << endl;
	cout<<"Fight in map 2"<<endl;
    Map<Complex_PVP_ENV> map2(pvp);
	cout<<"Exercise in Simple_PVE_ENV"<<endl;
    map2.exercise(simple_env);
	cout<<"Begin to fight"<<endl;
    map2.PK(30);

    return 0;
}