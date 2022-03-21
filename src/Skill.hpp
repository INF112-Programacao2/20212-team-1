/* Skill.hpp */

#include <string>

class Skill {
	private:
		std::string _name;
		int _damage_interval[2];
		// TODO: Change position of consts
		const int MIN_DAMAGE = 0;
		const int MAX_DAMAGE = 1;
	public:
		Skill(std::string name, int min_damage, int max_damage);
		~Skill();
		int get_name();
		int select_damage();
};
