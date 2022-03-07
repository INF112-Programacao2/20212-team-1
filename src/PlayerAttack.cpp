/* PlayerAttack.cpp */

PlayerAttack::PlayerAttack()
	: Object(ATTACK_BOX_PATH),
	m_nAtks(2)
{
	m_attacks = { { {"a", 13}, {"b", 1}, { }, { } } }; // inicializa com dois ataques
}

PlayerAttack::~PlayerAttack()
{

}

void PlayerAttack::addAttack(const Attack& _atk)
{
	m_attacks[m_nAtks - 1] = _atk;
}

void PlayerAttack::draw()
{
	Object::draw(); // Fundo

	if (m_nAtks = 1)
		; // TODO: desenha a caixa de selecao do ataque 1
	
	if (m_nAtks = 2)
		; // TODO: desenha a caixa de selecao do ataque 2
	
	if (m_nAtks = 3)
		; // TODO: desenha a caixa de selecao do ataque 3
	
	if (m_nAtks = 4)
		; // TODO: desenha a caixa de selecao do ataque 4
}

void PlayerAttack::do_attack(int _n)
{
	Attack atk = m_attacks[_n - 1];
	// Ataca o adversario
}
