/* Skill.hpp */

class Skill {
	public:
		string _name;
		int _damage_interval[2];
		// TODO: Change position of consts
		const int MIN_DAMAGE = 0;
		const int MAX_DAMAGE = 1;
	private:
		Skill(name, int min_damage, int max_damage);
		~Skill();
		int select_damage();
};
