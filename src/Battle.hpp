/* Battle.hpp */

#include "Npc.hpp"

class Battle {
	private:
		Npc *_enemy;
	public:
		Battle(Npc *enemy);
		~Battle();
		void start_battle();
}
