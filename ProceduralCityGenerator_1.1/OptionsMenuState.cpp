#include "OptionsMenuState.h"

OptionsMenuState::OptionsMenuState(StateManager* stateManager) : IState(stateManager)
{
}

OptionsMenuState::~OptionsMenuState()
{
}

void OptionsMenuState::Init()
{
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_NUMB_STARTING_STREETS, "Starting Streets", 15, 1, 300));					//0
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_STARTING_DISTANCE_MIN, "Starting Min Distance", 2000, 10, 3000));		//1
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_STARTING_DISTANCE_MAX, "Starting Max Distance", 2000, 10, 6000));		//2
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_MAX_STREETS, "Maximum Streets", 25000, 1, 99999));						//3
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_STREET_DISTANCE_MIN, "Street Min Distance", 100, 10, 3000));				//4
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_STREET_DISTANCE_MAX, "Street Max Distance", 300, 10, 6000));				//5
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_DIVISION_PERCENT_CHANCE, "Division Chance", 15, 1, 1000));				//6
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_STREET_DIVISION_ANGLE_MIN, "Minimum Angle of Division", 90, 1, 179));	//7
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_STREET_DIVISION_ANGLE_MAX, "Maximum Angle of Division", 90, 1, 179));	//8
	m_defaultButtonValues.push_back(std::tuple<UserFields, std::string, int, int, int>(UserFields::FIELD_MIN_DISTANCE_BETWEEN_DIVISIONS, "Min Distance Between Divisions", 15, 1, 99999)); //9

	m_background.setScale(1, 1);
	m_buttons.clear();

	m_background.setTexture(ResourceHolder::get().getTexture(TextureName::menu_background));

	m_background.scale(
		DisplayWindow::getSize().x / m_background.getLocalBounds().width,
		DisplayWindow::getSize().y / m_background.getLocalBounds().height);

	m_background.setPosition(
		DisplayWindow::getRelativePosition(
		DisplayWindowPosition::top_left,
		sf::Vector2f(0, 0),
		sf::Vector2f(-20, -20)));

	createButtons();
}

void OptionsMenuState::Cleanup()
{
}

void OptionsMenuState::Pause()
{
}

void OptionsMenuState::Resume()
{
}

void OptionsMenuState::GetEvents()
{
	sf::Event event;
	sf::RenderWindow* rw = DisplayWindow::getRenderWindow();

	while (rw->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			DisplayWindow::Close();
			break;

		case sf::Event::MouseButtonPressed:
			for (auto i = m_buttons.begin(); i != m_buttons.end(); i++)
			{
				if (i->get()->Contains(sf::Mouse::getPosition(*rw)))
				{
					i->get()->Click();
				}
			}
			break;
		}
	}
}

void OptionsMenuState::Update()
{
}

void OptionsMenuState::Display()
{
	DisplayWindow::Draw(m_background);

	for (auto i = m_buttons.begin(); i != m_buttons.end(); i++)
	{
		i->get()->Display();
	}
}

void OptionsMenuState::createButtons()
{
	int offset = 0;
	for (auto i = m_defaultButtonValues.begin(); i != m_defaultButtonValues.begin() + 4; i++)
	{
		m_buttons.push_back(
			std::make_shared
			<TextFieldButton>(
			std::get<0>(*i),
			sf::Vector2f(sf::Vector2f(50 + (offset++ * 220), 50)),
			std::to_string(std::get<2>(*i)),
			std::get<1>(*i)));
	}

	for (auto i = m_defaultButtonValues.begin() + 4; i != m_defaultButtonValues.begin() + 8; i++)
	{
		m_buttons.push_back(
			std::make_shared
			<TextFieldButton>(
			std::get<0>(*i),
			sf::Vector2f(sf::Vector2f(50 + ((offset++ - 4) * 220), 200)),
			std::to_string(std::get<2>(*i)),
			std::get<1>(*i)));
	}

	for (auto i = m_defaultButtonValues.begin() + 8; i != m_defaultButtonValues.begin() + 10; i++)
	{
		m_buttons.push_back(
			std::make_shared
			<TextFieldButton>(
			std::get<0>(*i),
			sf::Vector2f(sf::Vector2f(50 + ((offset++ - 8) * 220), 250)),
			std::to_string(std::get<2>(*i)),
			std::get<1>(*i)));
	}

	m_buttons.push_back(
		std::make_shared
		<DirectionButton>(
		m_p_stateManager,
		std::make_shared<MainMenuState>(m_p_stateManager),
		sf::Vector2f((1 * (DisplayWindow::getSize().x / 2)) + ((DisplayWindow::getSize().x / 2) * (.30)), DisplayWindow::getSize().y / 1.25),
		"Run",
		""));

	m_buttons.push_back(
		std::make_shared
		<BackButton>(
		m_p_stateManager,
		sf::Vector2f((2 * (DisplayWindow::getSize().x / 2)) + ((DisplayWindow::getSize().x / 2) * (.30)), DisplayWindow::getSize().y / 1.25),
		"Back",
		""));

}