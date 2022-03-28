/* Skill.hpp */

/*
 * This class is used to store the skills (like power) of some capimon.
 */

#ifndef SKILL_HPP
#define SKILL_HPP

#include <string>

class Skill {
	private:
		int _index;	// value that indetificates the skill
		std::string _name;	// name of the skill
		int _damage_interval[2];	// interval of the attack damage (min and max values)
	public:
		Skill(int index, std::string name, int min_damage, int max_damage);	// constructor
		~Skill();	// destructor
		const int MIN_DAMAGE = 0;	// const that defines the position of min damage in _damage_interval[] 
		const int MAX_DAMAGE = 1;	// const that defines the position of max damage in _damage_interval[]
		int get_index();	// returns _index
		std::string get_name();	// returns _name
		int select_damage();	// return a rand damage beetween the min and max damage
};

#endif /* SKILL_HPP */
