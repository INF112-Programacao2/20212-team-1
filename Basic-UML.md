Position
	- position_x
	- position_y
	creat(int x, int y)
	creat()
	change_to(int x, int y)
	change_x(int x)
	change_y(int y)
	add_to_x(int value)	// x + value
	add_to_y(int value)	// y + value
	
Object
 - BMP *initial_image
 - BMP *viewing_image
 - Position initial_position
 virtual create(BMP *initial_image, Position initial_position) = 0
 change_image(BMP *image)
 move(Position position)
 delete()
  
Interaction
 	- vector<key-value(string speech: string response)> dialogs
 	begin()
 	stop()

Character : Object
	- string name
	- vector<*BMP> walk_images
	- vector<*Capimon> deck
	virtual create()
	
Player : Character
	walk()
	act()	// other actions like (e.g. to open the deck)
	interact(NPC *npc)
	capture_capimon(Capimon *capimon)
	
NPC : Character
	- vector<Interaction> interactions
	
Attack
	- int damage
	- int critic_damage
	- double chance_of_critic
	
Capimon
	- string name
	- int total_life
	- int life
	- vector<*BMP> battle_images
	- vector<Attack> attacks
	attack()
	
Map : Object
	- int walkable[][]
	draw_part(int part_x, int part_y)
	
Battle
	- NPC *enimy
	begin(NPC *enimy)
	end()
