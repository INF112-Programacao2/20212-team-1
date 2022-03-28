/* Skill.hpp */

/*
 * This class is used to store the skills (like power) of some capimon
 */

#ifndef SKILL_HPP
#define SKILL_HPP

#include <string>

class Skill {
	private:
		const int MIN_DAMAGE = 0;
		const int MAX_DAMAGE = 1;
		int _index;
		std::string _name;
		int _damage_interval[2];
	public:
		Skill(int index, std::string name, int min_damage, int max_damage);
		~Skill();
		int get_index();
		std::string get_name();
		int select_damage();
};

#endif /* SKILL_HPP */
