#include "Heroes.h"
#include <math.h>
// TODO:: implement all the required member function in Heroes.h
void Hero::update_hp(int dhp)
{
	if(hp>=0)
		hp+=dhp;
	if(hp<0)
		hp=0;
}
void Hero::update_mp(int dmp)
{
	if(mp>=0)
		mp+=dmp;
	if(mp<0)
		mp=0;
}
void Hero::update_atk(int datk)
{
	if(atk>=0)
		atk+=datk;
	if(atk<0)
		atk=0;
}
void Hero::update_def(int ddef)
{
	if(def>=0)
		def+=ddef;
	if(def<0)
		def=0;
}
void Hero::update_spd(int dspd)
{
	if(spd>=1)
		spd+=dspd;
	if(spd<1)
		spd=1;
}
bool Hero::gain_exp(int exp)
{
	if(remain_exp>=0)
	{
		remain_exp-=exp;
		if(remain_exp==0)
			return true;
		else if(remain_exp<0)
		{
			remain_exp=0;
			return true;
		}
	}
	return false;
}
void Hero::just_move(const Hero* enemy)
{
	location+=direction*spd;
	if((direction==1 && enemy->location<location) || (direction==-1 && enemy->location>location))
			location=enemy->location;
}
Hero* Hero::evolve()
{
	if(remain_exp==0)
	{
		Hero* evolvedHero;
		if(hp>mp)
			evolvedHero = new Warrior(*this);
		else
			evolvedHero = new Mage(*this);
		return evolvedHero;
	}
	return this;
}
void Hero::move(const Hero* enemy){ just_move(enemy); }
void Hero::attack(Hero* enemy)
{
	if(location==enemy->location)
		enemy->attacked(atk-enemy->def);
}
void Hero::attacked(int dhp)
{
	if(dhp>0)
		update_hp(-dhp);
}
void Warrior::attacked(int dhp)
{
	if(dhp>0)
	{
		armor-=dhp;
		if(armor<0)
		{
			hp+=armor;
			armor=0;
		}
	}
}
Hero* Warrior::evolve()
{
	if(remain_exp==0)
	{
		Hero* evolvedHero;
		if(atk<spd+15)
			evolvedHero = new Knight(*this);
		else
			evolvedHero = new Berserker(*this);
		return evolvedHero;
	}
	return this;
}
void Knight::move(const Hero* enemy)
{
	if(mp>=5)
	{
		location+=(spd+2)*direction;
		update_mp(-5);
	}
	else
		location+=spd*direction;
	if((direction==1 && enemy->location<location) || (direction==-1 && enemy->location>location))
		location=enemy->location;
}
Hero* Knight::evolve(){ return this; }
void Berserker::attack(Hero* enemy)
{
	if(mp>=5)
	{
		if(location==enemy->location)
		{
			enemy->attacked(atk*2-enemy->def);
			update_mp(-5);
		}
	}
	else
		Hero::attack(enemy);
}
Hero* Berserker::evolve(){ return this; }
void Mage::attack(Hero* enemy)
{
	if(fabs(location-enemy->location)<4)
	{
		if(wand>=10)
		{
			enemy->attacked(floor(atk*1.5)-enemy->def);
			wand-=10;
		}
		else
			enemy->attacked(atk-enemy->def);
	}
}
void Mage::attacked(int dhp)
{
	if(dhp>0)
	{
		hp-=dhp;
		if(mp>=5)
		{
			if(dhp<5)
				update_hp(dhp);
			else
				update_hp(5);
			update_mp(-5);
		}
	}
}
Hero* Mage::evolve()
{
	if(remain_exp==0)
	{
		Hero* evolvedHero;
		if(atk<def+20)
			evolvedHero = new Healer(*this);
		else
			evolvedHero = new Magician(*this);
		return evolvedHero;
	}
	return this;
}
void Magician::attack(Hero* enemy)
{
	if(fabs(location-enemy->location)<5)
	{
		if(mp>=5)
		{
			if(wand>=10)
			{
				enemy->attacked((atk*2)-enemy->def);
				update_mp(-5);
				wand-=10;
			}
			else
			{
				enemy->attacked(floor(atk*1.5)-enemy->def);
				update_mp(-5);
			}
		}
		else
			enemy->attacked(atk-enemy->def);
	}
}
Hero* Magician::evolve(){ return this; }
void Healer::move(const Hero* enemy)
{
	Hero::just_move(enemy);
	if(mp>=5)
	{
		update_hp(5);
		update_mp(-5);
	}
}
Hero* Healer::evolve(){ return this; }
