/* Skill.hpp */

#include <string>

class Skill {
	private:
		int _index;
		std::string _name;
		int _damage_interval[2];
		// TODO: Change position of consts
		const int MIN_DAMAGE = 0;
		const int MAX_DAMAGE = 1;
	public:
		Skill(int index, std::string name, int min_damage, int max_damage);
		~Skill();
		int get_index();
		std::string get_name();
		int select_damage();
		void draw_skill_in_battle();
};
