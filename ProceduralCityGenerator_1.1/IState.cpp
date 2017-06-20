#include "IState.h"

ResourceHolder IState::m_s_c_resourceHolder;


IState::IState(StateManager* stateManager) : m_p_stateManager(stateManager)
{

}


const sf::Texture& IState::getTexture(TextureName name) const
{
	return m_s_c_resourceHolder.textures.get(name);
}

const sf::Font& IState::getFont(FontName name) const
{
	return m_s_c_resourceHolder.fonts.get(name);
}